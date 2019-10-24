//
//  Beacon.h
//  BLECommAPI
//
//  Created by cheneyang on 2019/10/22.
//  Copyright © 2019 cheneyang. All rights reserved.
//

#ifndef Beacon_h
#define Beacon_h

#import <Foundation/Foundation.h>

typedef NS_ENUM (NSInteger, BLEError) {
    BLEErrorOk,
    BLEErrorInvalidParameter,
    BLEErrorInvalidOperation,
    BLEErrorConnectionTimeout,
    BLEErrorConnectionDisconnected,
    BLEErrorNeedLocation,
};

typedef NSString *BLEStatus NS_STRING_ENUM;

FOUNDATION_EXPORT BLEStatus const BLEStatusPowerOn;
FOUNDATION_EXPORT BLEStatus const BLEStatusResetting;
FOUNDATION_EXPORT BLEStatus const BLEStatusUnsupported;
FOUNDATION_EXPORT BLEStatus const BLEStatusUnauthorized;
FOUNDATION_EXPORT BLEStatus const BLEStatusPoweredOff;
FOUNDATION_EXPORT BLEStatus const BLEStatusUnknown;

@interface Beacon : NSObject

@property(nonatomic, copy) NSString *uuid;
@property(nonatomic, copy, getter=getName) NSString *name;
@property(nonatomic) UInt16 major;
@property(nonatomic) UInt16 minor;
@property(nonatomic, getter=getMac) NSString *mac;
@property(nonatomic, getter=getOp) UInt8 op;
@property(nonatomic, getter=getSn) UInt8 sn;
@property(nonatomic, getter=getNesn) UInt8 nesn;
@property(nonatomic, getter=getSm) UInt8 sm;

- (UInt8)getOp;
- (UInt8)getSn;
- (UInt8)getNesn;
- (UInt8)getSm;
- (NSString *)getName;
- (NSString *)getMac;
- (NSData *)getData;

- (id)initWithUUID:(NSString*)uuid Major:(UInt16)major Minor:(UInt16) minor;

@end

#endif /* Beacon_h */
