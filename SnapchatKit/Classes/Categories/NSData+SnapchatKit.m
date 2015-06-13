//
//  NSData+SnapchatKit.m
//  SnapchatKit
//
//  Created by Tanner on 5/5/15.
//  Copyright (c) 2015 Tanner Bennett. All rights reserved.
//

#import "NSData+SnapchatKit.h"
#import "NSString+SnapchatKit.h"
#import <CommonCrypto/CommonCryptor.h>
#import <CommonCrypto/CommonDigest.h>

#import "SnapchatKit-Constants.h"

#define ChunkSize 16384

@implementation NSData (Encryption)

- (NSData *)AES128EncryptedDataWithKey:(NSString *)key {
    return [self AES128EncryptedDataWithKey:key iv:nil];
}

- (NSData *)AES128DecryptedDataWithKey:(NSString *)key {
    return [self AES128DecryptedDataWithKey:key iv:nil];
}

- (NSData *)AES128EncryptedDataWithKey:(NSString *)key iv:(NSString *)iv {
    return [self AES128Operation:kCCEncrypt key:key iv:iv];
}

- (NSData *)AES128DecryptedDataWithKey:(NSString *)key iv:(NSString *)iv {
    return [[self pad:0] AES128Operation:kCCDecrypt key:key iv:iv];
}

- (NSData *)AES128DecryptedDataWithKeyData:(NSData *)key ivData:(NSData *)iv {
    return [[self pad:0] AES128Operation:kCCDecrypt keyData:key ivData:iv];
}

- (NSData *)AES128Operation:(CCOperation)operation key:(NSString *)key iv:(NSString *)iv {
    return [self AES128Operation:operation keyData:[key dataUsingEncoding:NSUTF8StringEncoding] ivData:[iv dataUsingEncoding:NSUTF8StringEncoding]];
}

// kCCModeCBC
- (NSData *)AES128Operation:(CCOperation)operation keyData:(NSData *)key ivData:(NSData *)iv {
//    char keyPtr[kCCKeySizeAES128 + 1];
//    bzero(keyPtr, sizeof(keyPtr));
//    [key getBytes:keyPtr length:kCCKeySizeAES128 + 1];
////    [key getCString:keyPtr maxLength:sizeof(keyPtr) encoding:NSUTF8StringEncoding];
//
//    char ivPtr[kCCBlockSizeAES128 + 1];
//    bzero(ivPtr, sizeof(ivPtr));
//    if (iv) {
//        [iv getBytes:ivPtr length:kCCKeySizeAES128 + 1];
////        [iv getCString:ivPtr maxLength:sizeof(ivPtr) encoding:NSUTF8StringEncoding];
//    }

    size_t bufferSize = self.length + kCCBlockSizeAES128;
    void *buffer = malloc(bufferSize);

    size_t decryptedLength = 0;
    CCCryptorStatus cryptStatus = CCCrypt(operation,
                                          kCCAlgorithmAES128,
                                          kCCOptionPKCS7Padding | kCCModeCBC,
                                          key.bytes,
                                          kCCBlockSizeAES128,
                                          iv.bytes,
                                          self.bytes,
                                          self.length,
                                          buffer,
                                          bufferSize,
                                          &decryptedLength);
    if (cryptStatus == kCCSuccess) {
        return [NSData dataWithBytesNoCopy:buffer length:decryptedLength];
    }
    free(buffer);
    return nil;
}

- (NSData *)pad:(NSUInteger)blockSize {
    NSMutableData *data = self.mutableCopy;
    if (blockSize == 0)
        blockSize = 16;
    
    NSUInteger count = blockSize - (data.length % blockSize);
    data.length = data.length + count;
    
    return data;
}

@end

@implementation NSData (FileFormat)

- (BOOL)isJPEG {
    uint8_t a, b, c, d;
    [self getHeader:&a b:&b c:&c d:&d];
    
    return a == 0xFF && b == 0xD8 && c == 0xFF && d == 0xE0;
}

- (BOOL)isMPEG4 {
    uint8_t a, b, c, d;
    [self getHeader:&a b:&b c:&c d:&d];
    
    return a == 0x00 && b == 0x00 && c == 0x00 && (d == 0x14 || d == 0x18);
}

- (BOOL)isCompressed {
    uint8_t a, b, c, d;
    [self getHeader:&a b:&b c:&c d:&d];
    
    // PK header
    return a == 0x50 && b == 0x4B && c == 0x03 && d == 0x04;
}

- (void)getHeader:(void *)a b:(void *)b c:(void *)c d:(void *)d {
    [self getBytes:a length:1];
    [self getBytes:b range:NSMakeRange(1, 1)];
    [self getBytes:c range:NSMakeRange(2, 1)];
    [self getBytes:d range:NSMakeRange(3, 1)];
}

@end

@implementation NSData (Encoding)
- (NSString *)MD5Hash {
    unsigned char result[CC_MD5_DIGEST_LENGTH];
    CC_MD5( self.bytes, (CC_LONG)self.length, result ); // This is the md5 call
    return [NSString stringWithFormat:
            @"%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x",
            result[0], result[1], result[2], result[3],
            result[4], result[5], result[6], result[7],
            result[8], result[9], result[10], result[11],
            result[12], result[13], result[14], result[15]
            ];  
}
@end


@implementation NSData (Blob)

/** Decrypts blob data for standard images and videos. */
- (NSData *)decryptECB {
    return [[self pad:0] AES128DecryptedDataWithKey:kBlobEncryptionKey];
}

/** Encrypts blob data for standard images and videos. */
- (NSData *)encryptECB {
    return [[self pad:0] AES128EncryptedDataWithKey:kBlobEncryptionKey];
}

// This probably doesn't work at all. Idr where I got this code from.
- (NSData *)decryptStoryWithIdentifier:(NSInteger)storyID {
    NSString *key = [NSString stringWithFormat:@"/bq/story_blob?story_id=%ld", (long)storyID];
    return [self decryptCBCWithKey:key iv:nil];
}

/** Decrypts blob data for stories. key and iv are base 64 encoded. */
- (NSData *)decryptCBCWithKey:(NSString *)key iv:(NSString *)iv {
    // Decode the key and IV
    NSData *keyData = [[NSData alloc] initWithBase64EncodedString:key options:0];
    NSData *ivData = [[NSData alloc] initWithBase64EncodedString:iv options:0];
    
    NSData *decrypted = [self AES128DecryptedDataWithKeyData:keyData ivData:ivData];
    
    // Probably unnecessary to trim the data, not sure until I get a successful decryption.
//    unsigned char buffer[1];
//    [decrypted getBytes:buffer range:NSMakeRange(decrypted.length-1, 1)];
//    NSUInteger padding = (NSUInteger)buffer;
//    decrypted.length -= padding;
    
    return decrypted;
}

@end