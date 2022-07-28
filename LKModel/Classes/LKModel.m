//
//  LKModel.m
//  LKModel
//
//  Created by BOE on 2022/7/28.
//

#import "LKModel.h"
#import <YYModel/YYModel.h>

@implementation LKModel

+ (instancetype)modelWithDictionary:(NSDictionary *)dictionary {
    return [self yy_modelWithDictionary:dictionary];
}

+ (instancetype)modelWithJson:(NSString *)json {
    return [self yy_modelWithJSON:json];
}

+ (NSArray *)modelArrayWithDictionaryArray:(NSArray *)dictionaryArray {
    return [NSArray yy_modelArrayWithClass:self json:dictionaryArray];
}

- (BOOL)modelSetWithDictionary:(NSDictionary *)dic {
    return [self yy_modelSetWithDictionary:dic];
}

- (BOOL)modelSetWithJSON:(id)json {
    return [self yy_modelSetWithJSON:json];
}

- (NSString *)json {
    return [self yy_modelToJSONString];
}

- (NSDictionary *)dictionary {
    return [self yy_modelToJSONObject];
}

+ (BOOL)supportsSecureCoding {
    return YES;
}

- (void)encodeWithCoder:(NSCoder *)aCoder {
    [self yy_modelEncodeWithCoder:aCoder];
}

- (id)initWithCoder:(NSCoder *)aDecoder {
    self = [super init]; return [self yy_modelInitWithCoder:aDecoder];
}

#ifdef DEBUG
- (NSString *)description {
    return [self yy_modelDescription];
}
#endif
@end

@implementation NSDictionary (LKModel)

+ (instancetype)modelWithJson:(NSString *)json {
    return [self yy_modelWithJSON:json];
}

- (NSString *)json {
    return [self yy_modelToJSONString];
}

@end

@implementation NSArray (LKModel)

+ (instancetype)modelWithJson:(NSString *)json {
    return [self yy_modelWithJSON:json];
}

- (NSString *)json {
    return [self yy_modelToJSONString];
}

@end
