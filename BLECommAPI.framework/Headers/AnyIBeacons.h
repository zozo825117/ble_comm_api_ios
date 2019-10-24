//
//  AnyIBeacons.h
//  IBeacon
//
//  Created by Mr.Zhu on 2019/9/7.
//  Copyright © 2019 Mr.Zhu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
NS_ASSUME_NONNULL_BEGIN

@interface AnyIBeacons : CLBeaconRegion
- (id)initWithIdentifier:(NSString *)identifier;
@end

NS_ASSUME_NONNULL_END
