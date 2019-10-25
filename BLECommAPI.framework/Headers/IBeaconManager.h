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

/**
 * start scan
 */
- (void)startScan;

/**
 * start scan by name
 * @param name : target name
 */
- (void)startScanWith:(NSString *)name;

/**
 * stop scan
 */
- (void)stopScan;

/**
 * connect target beacon
 * @param beacon : target beacon after scan success
 * @param token : hex string, length must be 12, standing for 6 bytes, used for encryption in communication
 * @param timeout : connect timeout, seconds
 */
- (void)connect:(Beacon*) beacon token: (NSString*) token timeout: (int) timeout;

/**
 * disconnect
 */
- (void)disconnect;

/**
 * write data
 * @param data : data
 */
- (void)write:(NSData *)data;

@end

#endif /* IBeaconManager_h */
