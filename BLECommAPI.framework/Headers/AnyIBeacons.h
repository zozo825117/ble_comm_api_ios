#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
NS_ASSUME_NONNULL_BEGIN

@interface AnyIBeacons : CLBeaconRegion
- (id)initWithIdentifier:(NSString *)identifier;
@end

NS_ASSUME_NONNULL_END
