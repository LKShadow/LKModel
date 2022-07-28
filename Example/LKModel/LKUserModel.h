//
//  LKUserModel.h
//  LKModel_Example
//
//  Created by BOE on 2022/7/28.
//  Copyright © 2022 LKShadow. All rights reserved.
//

#import <LKModel/LKModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface LKUserModel : LKModel

@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *address;
@property (nonatomic, copy) NSString *age;

@end

NS_ASSUME_NONNULL_END
