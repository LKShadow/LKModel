//
//  LKViewController.m
//  LKModel
//
//  Created by LKShadow on 07/28/2022.
//  Copyright (c) 2022 LKShadow. All rights reserved.
//

#import "LKViewController.h"
#import "LKUserModel.h"
@interface LKViewController ()

@end

@implementation LKViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    NSDictionary *dic = @{
        @"name" : @"姓名是啥",
        @"age" : @"100",
        @"address" : @"北京市朝阳区"
    };
    LKUserModel *model = [LKUserModel modelWithDictionary:dic];
    NSLog(@"%@", [model json]);
    
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
