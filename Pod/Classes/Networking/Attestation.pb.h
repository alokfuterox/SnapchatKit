// Generated by the protocol buffer compiler.  DO NOT EDIT!

//#import <ProtocolBuffers/ProtocolBuffers.h>
#import "ProtocolBuffers.h"
#import "GeneratedMessage.h"

// @@protoc_insertion_point(imports)

@class Attestation;
@class AttestationBuilder;
@class DataContainer;
@class DataContainerBuilder;
@class SuExec;
@class SuExecBuilder;
@class UnknownData;
@class UnknownDataBuilder;



@interface AttestationRoot : NSObject {
}
+ (PBExtensionRegistry*) extensionRegistry;
+ (void) registerAllExtensions:(PBMutableExtensionRegistry*) registry;
@end

#define Attestation_datacontainer @"datacontainer"
#define Attestation_droidGuard @"droidGuard"
@interface Attestation : PBGeneratedMessage<GeneratedMessageProtocol> {
@private
  BOOL hasDroidGuard_:1;
  BOOL hasDatacontainer_:1;
  NSString* droidGuard;
  DataContainer* datacontainer;
}
- (BOOL) hasDatacontainer;
- (BOOL) hasDroidGuard;
@property (readonly, strong) DataContainer* datacontainer;
@property (readonly, strong) NSString* droidGuard;

+ (instancetype) defaultInstance;
- (instancetype) defaultInstance;

- (BOOL) isInitialized;
- (void) writeToCodedOutputStream:(PBCodedOutputStream*) output;
- (AttestationBuilder*) builder;
+ (AttestationBuilder*) builder;
+ (AttestationBuilder*) builderWithPrototype:(Attestation*) prototype;
- (AttestationBuilder*) toBuilder;

+ (Attestation*) parseFromData:(NSData*) data;
+ (Attestation*) parseFromData:(NSData*) data extensionRegistry:(PBExtensionRegistry*) extensionRegistry;
+ (Attestation*) parseFromInputStream:(NSInputStream*) input;
+ (Attestation*) parseFromInputStream:(NSInputStream*) input extensionRegistry:(PBExtensionRegistry*) extensionRegistry;
+ (Attestation*) parseFromCodedInputStream:(PBCodedInputStream*) input;
+ (Attestation*) parseFromCodedInputStream:(PBCodedInputStream*) input extensionRegistry:(PBExtensionRegistry*) extensionRegistry;
@end

@interface AttestationBuilder : PBGeneratedMessageBuilder {
@private
  Attestation* resultAttestation;
}

- (Attestation*) defaultInstance;

- (AttestationBuilder*) clear;
- (AttestationBuilder*) clone;

- (Attestation*) build;
- (Attestation*) buildPartial;

- (AttestationBuilder*) mergeFrom:(Attestation*) other;
- (AttestationBuilder*) mergeFromCodedInputStream:(PBCodedInputStream*) input;
- (AttestationBuilder*) mergeFromCodedInputStream:(PBCodedInputStream*) input extensionRegistry:(PBExtensionRegistry*) extensionRegistry;

- (BOOL) hasDatacontainer;
- (DataContainer*) datacontainer;
- (AttestationBuilder*) setDatacontainer:(DataContainer*) value;
- (AttestationBuilder*) setDatacontainerBuilder:(DataContainerBuilder*) builderForValue;
- (AttestationBuilder*) mergeDatacontainer:(DataContainer*) value;
- (AttestationBuilder*) clearDatacontainer;

- (BOOL) hasDroidGuard;
- (NSString*) droidGuard;
- (AttestationBuilder*) setDroidGuard:(NSString*) value;
- (AttestationBuilder*) clearDroidGuard;
@end

#define DataContainer_nonce @"nonce"
#define DataContainer_apkPackageName @"apkPackageName"
#define DataContainer_apkCertificateDigestSha256 @"apkCertificateDigestSha256"
#define DataContainer_apkDigestSha256 @"apkDigestSha256"
#define DataContainer_gmsVersion @"gmsVersion"
#define DataContainer_suexec @"suexec"
#define DataContainer_unknowndata @"unknowndata"
#define DataContainer_timestamp @"timestamp"
@interface DataContainer : PBGeneratedMessage<GeneratedMessageProtocol> {
@private
  BOOL hasTimestamp_:1;
  BOOL hasGmsVersion_:1;
  BOOL hasApkPackageName_:1;
  BOOL hasSuexec_:1;
  BOOL hasUnknowndata_:1;
  BOOL hasNonce_:1;
  BOOL hasApkCertificateDigestSha256_:1;
  BOOL hasApkDigestSha256_:1;
  SInt64 timestamp;
  SInt32 gmsVersion;
  NSString* apkPackageName;
  SuExec* suexec;
  UnknownData* unknowndata;
  NSData* nonce;
  NSData* apkCertificateDigestSha256;
  NSData* apkDigestSha256;
}
- (BOOL) hasNonce;
- (BOOL) hasApkPackageName;
- (BOOL) hasApkCertificateDigestSha256;
- (BOOL) hasApkDigestSha256;
- (BOOL) hasGmsVersion;
- (BOOL) hasSuexec;
- (BOOL) hasUnknowndata;
- (BOOL) hasTimestamp;
@property (readonly, strong) NSData* nonce;
@property (readonly, strong) NSString* apkPackageName;
@property (readonly, strong) NSData* apkCertificateDigestSha256;
@property (readonly, strong) NSData* apkDigestSha256;
@property (readonly) SInt32 gmsVersion;
@property (readonly, strong) SuExec* suexec;
@property (readonly, strong) UnknownData* unknowndata;
@property (readonly) SInt64 timestamp;

+ (instancetype) defaultInstance;
- (instancetype) defaultInstance;

- (BOOL) isInitialized;
- (void) writeToCodedOutputStream:(PBCodedOutputStream*) output;
- (DataContainerBuilder*) builder;
+ (DataContainerBuilder*) builder;
+ (DataContainerBuilder*) builderWithPrototype:(DataContainer*) prototype;
- (DataContainerBuilder*) toBuilder;

+ (DataContainer*) parseFromData:(NSData*) data;
+ (DataContainer*) parseFromData:(NSData*) data extensionRegistry:(PBExtensionRegistry*) extensionRegistry;
+ (DataContainer*) parseFromInputStream:(NSInputStream*) input;
+ (DataContainer*) parseFromInputStream:(NSInputStream*) input extensionRegistry:(PBExtensionRegistry*) extensionRegistry;
+ (DataContainer*) parseFromCodedInputStream:(PBCodedInputStream*) input;
+ (DataContainer*) parseFromCodedInputStream:(PBCodedInputStream*) input extensionRegistry:(PBExtensionRegistry*) extensionRegistry;
@end

@interface DataContainerBuilder : PBGeneratedMessageBuilder {
@private
  DataContainer* resultDataContainer;
}

- (DataContainer*) defaultInstance;

- (DataContainerBuilder*) clear;
- (DataContainerBuilder*) clone;

- (DataContainer*) build;
- (DataContainer*) buildPartial;

- (DataContainerBuilder*) mergeFrom:(DataContainer*) other;
- (DataContainerBuilder*) mergeFromCodedInputStream:(PBCodedInputStream*) input;
- (DataContainerBuilder*) mergeFromCodedInputStream:(PBCodedInputStream*) input extensionRegistry:(PBExtensionRegistry*) extensionRegistry;

- (BOOL) hasNonce;
- (NSData*) nonce;
- (DataContainerBuilder*) setNonce:(NSData*) value;
- (DataContainerBuilder*) clearNonce;

- (BOOL) hasApkPackageName;
- (NSString*) apkPackageName;
- (DataContainerBuilder*) setApkPackageName:(NSString*) value;
- (DataContainerBuilder*) clearApkPackageName;

- (BOOL) hasApkCertificateDigestSha256;
- (NSData*) apkCertificateDigestSha256;
- (DataContainerBuilder*) setApkCertificateDigestSha256:(NSData*) value;
- (DataContainerBuilder*) clearApkCertificateDigestSha256;

- (BOOL) hasApkDigestSha256;
- (NSData*) apkDigestSha256;
- (DataContainerBuilder*) setApkDigestSha256:(NSData*) value;
- (DataContainerBuilder*) clearApkDigestSha256;

- (BOOL) hasGmsVersion;
- (SInt32) gmsVersion;
- (DataContainerBuilder*) setGmsVersion:(SInt32) value;
- (DataContainerBuilder*) clearGmsVersion;

- (BOOL) hasSuexec;
- (SuExec*) suexec;
- (DataContainerBuilder*) setSuexec:(SuExec*) value;
- (DataContainerBuilder*) setSuexecBuilder:(SuExecBuilder*) builderForValue;
- (DataContainerBuilder*) mergeSuexec:(SuExec*) value;
- (DataContainerBuilder*) clearSuexec;

- (BOOL) hasUnknowndata;
- (UnknownData*) unknowndata;
- (DataContainerBuilder*) setUnknowndata:(UnknownData*) value;
- (DataContainerBuilder*) setUnknowndataBuilder:(UnknownDataBuilder*) builderForValue;
- (DataContainerBuilder*) mergeUnknowndata:(UnknownData*) value;
- (DataContainerBuilder*) clearUnknowndata;

- (BOOL) hasTimestamp;
- (SInt64) timestamp;
- (DataContainerBuilder*) setTimestamp:(SInt64) value;
- (DataContainerBuilder*) clearTimestamp;
@end

#define SuExec_execPath @"execPath"
#define SuExec_execSignature @"execSignature"
@interface SuExec : PBGeneratedMessage<GeneratedMessageProtocol> {
@private
  BOOL hasExecPath_:1;
  BOOL hasExecSignature_:1;
  NSString* execPath;
  NSData* execSignature;
}
- (BOOL) hasExecPath;
- (BOOL) hasExecSignature;
@property (readonly, strong) NSString* execPath;
@property (readonly, strong) NSData* execSignature;

+ (instancetype) defaultInstance;
- (instancetype) defaultInstance;

- (BOOL) isInitialized;
- (void) writeToCodedOutputStream:(PBCodedOutputStream*) output;
- (SuExecBuilder*) builder;
+ (SuExecBuilder*) builder;
+ (SuExecBuilder*) builderWithPrototype:(SuExec*) prototype;
- (SuExecBuilder*) toBuilder;

+ (SuExec*) parseFromData:(NSData*) data;
+ (SuExec*) parseFromData:(NSData*) data extensionRegistry:(PBExtensionRegistry*) extensionRegistry;
+ (SuExec*) parseFromInputStream:(NSInputStream*) input;
+ (SuExec*) parseFromInputStream:(NSInputStream*) input extensionRegistry:(PBExtensionRegistry*) extensionRegistry;
+ (SuExec*) parseFromCodedInputStream:(PBCodedInputStream*) input;
+ (SuExec*) parseFromCodedInputStream:(PBCodedInputStream*) input extensionRegistry:(PBExtensionRegistry*) extensionRegistry;
@end

@interface SuExecBuilder : PBGeneratedMessageBuilder {
@private
  SuExec* resultSuExec;
}

- (SuExec*) defaultInstance;

- (SuExecBuilder*) clear;
- (SuExecBuilder*) clone;

- (SuExec*) build;
- (SuExec*) buildPartial;

- (SuExecBuilder*) mergeFrom:(SuExec*) other;
- (SuExecBuilder*) mergeFromCodedInputStream:(PBCodedInputStream*) input;
- (SuExecBuilder*) mergeFromCodedInputStream:(PBCodedInputStream*) input extensionRegistry:(PBExtensionRegistry*) extensionRegistry;

- (BOOL) hasExecPath;
- (NSString*) execPath;
- (SuExecBuilder*) setExecPath:(NSString*) value;
- (SuExecBuilder*) clearExecPath;

- (BOOL) hasExecSignature;
- (NSData*) execSignature;
- (SuExecBuilder*) setExecSignature:(NSData*) value;
- (SuExecBuilder*) clearExecSignature;
@end

#define UnknownData_unknown1 @"unknown1"
#define UnknownData_unknown2 @"unknown2"
@interface UnknownData : PBGeneratedMessage<GeneratedMessageProtocol> {
@private
  BOOL hasUnknown1_:1;
  BOOL hasUnknown2_:1;
  BOOL unknown1_:1;
  BOOL unknown2_:1;
}
- (BOOL) hasUnknown1;
- (BOOL) hasUnknown2;
- (BOOL) unknown1;
- (BOOL) unknown2;

+ (instancetype) defaultInstance;
- (instancetype) defaultInstance;

- (BOOL) isInitialized;
- (void) writeToCodedOutputStream:(PBCodedOutputStream*) output;
- (UnknownDataBuilder*) builder;
+ (UnknownDataBuilder*) builder;
+ (UnknownDataBuilder*) builderWithPrototype:(UnknownData*) prototype;
- (UnknownDataBuilder*) toBuilder;

+ (UnknownData*) parseFromData:(NSData*) data;
+ (UnknownData*) parseFromData:(NSData*) data extensionRegistry:(PBExtensionRegistry*) extensionRegistry;
+ (UnknownData*) parseFromInputStream:(NSInputStream*) input;
+ (UnknownData*) parseFromInputStream:(NSInputStream*) input extensionRegistry:(PBExtensionRegistry*) extensionRegistry;
+ (UnknownData*) parseFromCodedInputStream:(PBCodedInputStream*) input;
+ (UnknownData*) parseFromCodedInputStream:(PBCodedInputStream*) input extensionRegistry:(PBExtensionRegistry*) extensionRegistry;
@end

@interface UnknownDataBuilder : PBGeneratedMessageBuilder {
@private
  UnknownData* resultUnknownData;
}

- (UnknownData*) defaultInstance;

- (UnknownDataBuilder*) clear;
- (UnknownDataBuilder*) clone;

- (UnknownData*) build;
- (UnknownData*) buildPartial;

- (UnknownDataBuilder*) mergeFrom:(UnknownData*) other;
- (UnknownDataBuilder*) mergeFromCodedInputStream:(PBCodedInputStream*) input;
- (UnknownDataBuilder*) mergeFromCodedInputStream:(PBCodedInputStream*) input extensionRegistry:(PBExtensionRegistry*) extensionRegistry;

- (BOOL) hasUnknown1;
- (BOOL) unknown1;
- (UnknownDataBuilder*) setUnknown1:(BOOL) value;
- (UnknownDataBuilder*) clearUnknown1;

- (BOOL) hasUnknown2;
- (BOOL) unknown2;
- (UnknownDataBuilder*) setUnknown2:(BOOL) value;
- (UnknownDataBuilder*) clearUnknown2;
@end


// @@protoc_insertion_point(global_scope)
