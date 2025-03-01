#import "ViewController.h"
#import <Foundation/Foundation.h>

@implementation ViewController : UIViewController

- (void)viewDidLoad {
    [super viewDidLoad];
//    self.navigationController.navigationBar.backgroundColor = UIColor.whiteColor;
    // set listener
    IBeaconManager.sharedInstance.listener = self;
}

- (IBAction)search:(id)sender {
    NSString *name = self.searchNameTextField.text;
    NSLog(@"[sample] call search with name: %@", name);
    
    [IBeaconManager.sharedInstance startScanWith:name];
    
    self.title = @"SEARCHING";
    [self.view endEditing:YES];
}

- (IBAction)connect:(id)sender {
    NSLog(@"[sample] call connect");
    
    NSString *tokenHex = @"010203040506";
    [IBeaconManager.sharedInstance connect:self.beacon token:tokenHex timeout:10];
    
    [self.view endEditing:YES];
}

- (IBAction)send:(id)sender {
    NSString *msg = self.writeDataTextField.text;
    NSLog(@"[sample] call write with msg: %@", msg);
    
    NSData *data = [self hexStringToData:msg];
    if (data == nil || data.length == 0) {
        NSLog(@"[sample] invalid hex string to write: %@", msg);
        return;
    }
    [IBeaconManager.sharedInstance write:data];
    
    [self.view endEditing:YES];
}

- (IBAction)disconnect:(id)sender {
    NSLog(@"[sample] call disconnect");
    
    [IBeaconManager.sharedInstance disconnect];
    
    [self.view endEditing:YES];
}

- (void)onOperationStartSuccess:(int)op {
    NSLog(@"[sample] callback: on start success: %d", op);
}

- (void)onOperationStartFailure:(int)op error:(BLEError)error {
    NSLog(@"[sample] callback: on start fail: %d %ld", op, error);
}

- (void)onBLEStatusUpdate:(nonnull BLEStatus)status {
    NSLog(@"[sample] on device update status: %@", status);
    if (status == BLEStatusPowerOn) {
        NSLog(@"[sample] bluetooth open");
    }
}

- (void)onScanStart:(bool)result error:(BLEError)error {
    NSLog(@"[sample] callback: on scan start: %u", result);
    self.title = @"SCAN START";
}

- (void)onScanSuccess:(nonnull Beacon *)beacon {
    NSLog(@"[sample] callback: on scan success: %@", beacon.uuid);
    self.title = @"SEARCH SUCCESS";
    self.beacon = beacon;
    self.beaconInfoLabel.text = [NSString stringWithFormat:@"%@", beacon.mac];
    self.connectButton.enabled = YES;
    self.writeButton.enabled = NO;
}

- (void)onConnectStart:(nonnull Beacon *)beacon error:(BLEError)error {
    self.title = @"CONNECTING...";
    NSLog(@"[sample] connecting...");
    if (error != BLEErrorOk) {
        NSLog(@"[sample] connection error: %ld", (long)error);
        if (error == BLEErrorConnectionTimeout) {
            self.disconnectButton.enabled = NO;
            self.writeButton.enabled = NO;
            self.title = @"CONNECT TIMEOUT";
        }
    }
}

- (void)onConnectSuccess:(nonnull Beacon *)beacon {
    NSLog(@"[sample] callback: on connect success: %@", beacon.uuid);
    self.disconnectButton.enabled = YES;
    self.writeButton.enabled = YES;
    self.title = @"CONNECTED";
    self.connectButton.enabled = NO;
}

- (void)onDisconnect:(nonnull Beacon *)beacon error:(BLEError)error {
    NSLog(@"[sample] callbaclk: on disconnect: %@, %ld", beacon.uuid, (long)error);
    self.title = @"DISCONNECTED";
    self.beacon = nil;
    self.receiveLabel.text = @"";
    self.disconnectButton.enabled = NO;
    self.connectButton.enabled = YES;
    self.writeButton.enabled = NO;
}

- (void)onSendSuccess:(int)index {
    NSLog(@"[sample] on send sta: %d", index);
}

- (void)onReceive:(NSData *) data {
    NSLog(@"[sample] on received data: %@", data);
    self.receiveLabel.text = [self dataToHexString:data];
}

- (NSString *)dataToHexString: (NSData *) data {
    const Byte *dataBuffer = (const Byte *)[data bytes];
    if (!dataBuffer)
        return [NSString string];

    NSUInteger dataLength = [data length];
    NSMutableString *hexString = [NSMutableString stringWithCapacity:(dataLength * 2)];

    for (int i = 0; i < dataLength; ++i)
        [hexString appendString:[NSString stringWithFormat:@"%02x", dataBuffer[i]]];

    return [NSString stringWithString:hexString];
}

- (NSData*)hexStringToData: (NSString *) hexString {
    NSMutableData* data = [NSMutableData data];
    for (int i = 0; i + 2 <= hexString.length; i += 2) {
        NSRange range = NSMakeRange(i, 2);
        NSString* hex = [hexString substringWithRange:range];
        NSScanner* scanner = [NSScanner scannerWithString:hex];
        unsigned int intValue;
        BOOL result = [scanner scanHexInt:&intValue];
        if (!result) {
            return nil;
        }
        [data appendBytes:&intValue length:1];
    }

    return data;
}

@end
