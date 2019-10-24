//
//  IBeaconManager.h
//  BLECommAPI
//
//  Created by cheneyang on 2019/10/22.
//  Copyright © 2019 cheneyang. All rights reserved.
//

#ifndef IBeaconManager_h
#define IBeaconManager_h

#import "Beacon.h"
#import <CoreBluetooth/CoreBluetooth.h>
#import <CoreBluetooth/CBManager.h>
#import <CoreLocation/CoreLocation.h>
#import "AnyIBeacons.h"
#import "IBeaconProtocol.h"

typedef NS_ENUM (NSInteger, ConnectStatus) {
    Normal,
    ConnectRequest,
    ConnectReceive,
    Disconnect,
    TransmitData,
    Open,
    Close,
};

@interface IBeaconManager : NSObject <CBPeripheralManagerDelegate, CLLocationManagerDelegate>

@property(nonatomic, setter=setConnectStatus:) ConnectStatus connectStatus;
@property(nonatomic, setter=setDisconnectedCount:) int disconnectedCount;

@property(nonatomic) BLEStatus            bleState;
@property            CLLocationManager*   localManager;
@property            AnyIBeacons*         region;
@property            CBPeripheralManager* peripheralManager;
@property            Beacon*              targetBeaconDevice;
@property            NSString*            searchName;
@property            BOOL                 isConnect;
@property            BOOL                 isFirst;
@property            dispatch_source_t    timer;
@property            NSString*            lastMsg;
@property            int                  lastIndex;
@property            NSData*              token;
@property            int                  timeOutInterval;
@property            NSMutableArray*      sendList;

+(IBeaconManager*) sharedInstance;

@property id listener;

- (void)startScanWith:(NSString *)name;
- (void)startScan;
- (void)stopScan;
- (void)connect:(Beacon*) beacon token: (NSString*) token timeout: (int) timeout;
- (void)disconnect;
- (void)write:(NSData *)data;

@end

#endif /* IBeaconManager_h */
