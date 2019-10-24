//
//  IBeaconProtocol.h
//  BLECommAPI
//
//  Created by cheneyang on 2019/10/22.
//  Copyright © 2019 cheneyang. All rights reserved.
//

#ifndef IBeaconProtocol_h
#define IBeaconProtocol_h

#import <Foundation/Foundation.h>
#import "IBeaconManager.h"
#import "Beacon.h"

NS_ASSUME_NONNULL_BEGIN

@protocol IBeaconListener <NSObject>

/**
 * ble communication requirement success
 * @param Op :
 *             OpAdv : start advertisement
 *             OpConnReq : connection request
 *             OpConnResp : connection resp
 *             OpDisconnReq : disconnect
 *             OpTran : write data
 */
@required
-(void) onStartSuccess:(int) op;

/**
 * ble communication requirement failed
 * @param Op :
 *             OpAdv : start advertisement
 *             OpConnReq : connection request
 *             OpConnResp : connection resp
 *             OpDisconnReq : disconnect
 *             OpTran : write data
 * @param errorCode :  BLE_ERROR_INVALID_PARAMETER or BLE_ERROR_INVALID_OPERATION
 */
@required
-(void) onStartFailure:(int) op error:(BLEError) error;

///start scan
///
///
///@param result: result
///@param error: error
@required
-(void) onScanStart:(bool) result error:(BLEError) error;

/// scan success
///
/// - Parameter beacon: beacon
@required
-(void) onScanSuccess:(Beacon*) beacon;

/// connect start
///
/// @param beacon: target
/// @param error: error
@required
-(void) onConnectStart:(Beacon*) beacon error:(BLEError) error;

/// connected
///
///@param beacon: beacon device
@required
-(void) onConnectSuccess:(Beacon*) beacon;

/// disconnected
///
/// @param beacon: device
/// @param error: error
@required
-(void) onDisconnect:(Beacon*) beacon error:(BLEError) error;

/// bluetooth device status updated
///
/// @param status: new device status
@required
-(void) onBLEStatusUpdate:(BLEStatus) status;

/// received data
///
/// @param data: received data
@required
-(void) onReceive:(NSData*) data;

/// send success with index
///
/// @param index: index of sended data
@required
-(void) onSendSuccess:(int) index;

@end

NS_ASSUME_NONNULL_END

#endif /* IBeaconProtocol_h */
