//
//  TodayEvents.h
//  Today
//
//  Created by shendong on 2017/2/21.
//  Copyright © 2017年 shendong. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVOSCloud/AVOSCloud.h>

@class Account;

NS_ASSUME_NONNULL_BEGIN

//! 日记Item
@interface TodayEvents : AVObject<AVSubclassing>

//@property (nonatomic, strong, readonly) Account *owner; //所有者
//! 文章标题
@property (nonatomic, copy) NSString *title;
//! 记录内容
@property (nonatomic, copy) NSString *contents;
//! 记录时间
@property (nonatomic) NSDate *recordDate;
//! 封面图片(最多为一张)
@property (nonatomic, nullable) AVFile *image;
//! 标签(为以后的标签查询做准备)
@property (nonatomic, copy, nullable) NSString *tag; //标签
//! 群组(日记群组,旅游群组)
@property (nonatomic, copy, nullable) NSString *group; //群组
//! 地址位置
@property (nonatomic) AVGeoPoint *geoPoint;

/*
 
 待定需求：
    
    1. 贴纸
 
 */

+ (instancetype)event;

+ (instancetype)eventWithTitle:(NSString *)title content:(NSString *)content;

@end

@interface TodayEvents(AVHelper)

//! 创建一条日志, 并且保存
- (BOOL)saveEvents;
//! 删除本条目录
- (BOOL)deleteEvents;
//! 查询所有日志
+ (NSArray<__kindof TodayEvents *> *)queryAllEvents;

@end

NS_ASSUME_NONNULL_END
