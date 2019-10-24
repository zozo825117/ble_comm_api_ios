//
//  ViewController.h
//  BeaconSample
//
//  Created by cheneyang on 2019/10/21.
//  Copyright © 2019 cheneyang. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <BLECommAPI/BLECommAPI.h>

@interface ViewController : UIViewController <IBeaconListener>

@property (weak, nonatomic) IBOutlet UITextField *searchNameTextField;
@property (weak, nonatomic) IBOutlet UILabel *beaconInfoLabel;
@property (weak, nonatomic) IBOutlet UIButton *searchButton;
@property (weak, nonatomic) IBOutlet UIButton *connectButton;
@property (weak, nonatomic) IBOutlet UIButton *writeButton;
@property (weak, nonatomic) IBOutlet UIButton *disconnectButton;
@property (weak, nonatomic) IBOutlet UITextField *writeDataTextField;
@property (weak, nonatomic) IBOutlet UILabel *receiveLabel;

@property(nonatomic) Beacon *beacon;

@end
