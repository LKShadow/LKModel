//
//  LKModel.h
//  LKModel
//
//  Created by BOE on 2022/7/28.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LKModel : NSObject <NSSecureCoding>

+ (instancetype)modelWithDictionary:(NSDictionary *)dictionary;

+ (instancetype)modelWithJson:(NSString *)json;

+ (NSArray *)modelArrayWithDictionaryArray:(NSArray *)dictionaryArray;

- (BOOL)modelSetWithDictionary:(NSDictionary *)dic;

- (BOOL)modelSetWithJSON:(id)json;

- (NSString *)json;

- (NSDictionary *)dictionary;


@end


@protocol LKModel <NSObject>

@optional
/**
Custom property mapper.

@discussion 当后台服务器返回的属性的 key 与本地 Model 不同时，可以通过改方法转换

Example:
   
   json:
       {
           "n":"Harry Pottery",
           "p": 256,
           "ext" : {
               "desc" : "A book written by J.K.Rowling."
           },
           "ID" : 100010
       }

   model:
       @property NSString *name;
       @property NSInteger page;
       @property NSString *desc;
       @property NSString *bookID;
       @end
       
       @implementation YYBook
       + (NSDictionary *)modelCustomPropertyMapper {
           return @{@"name"  : @"n",
                    @"page"  : @"p",
                    @"desc"  : @"ext.desc",
                    @"bookID": @[@"id", @"ID", @"book_id"]};
       }
       @end

@return 自定义属性转换
*/
+ (NSDictionary<NSString *, id> *)modelCustomPropertyMapper;

/// 用于有嵌套对象时使用
/// + (NSDictionary *)modelContainerPropertyGenericClass {
///     return @{@"shadows"     : [YYShadow class],
///              @"borders"     : YYBorder.class,
///              @"attachments" : @"YYAttachment" };
///              }
/// key 为属性名，value 嵌套对象类名
+ (nullable NSDictionary<NSString *, id> *)modelContainerPropertyGenericClass;

@end
@interface NSDictionary (LKModel)


+ (instancetype)modelWithJson:(NSString *)json;

- (NSString *)json;

@end

@interface NSArray (LKModel)

+ (instancetype)modelWithJson:(NSString *)json;

- (NSString *)json;

@end

NS_ASSUME_NONNULL_END
