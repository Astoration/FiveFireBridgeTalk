//
//  BroadcastMessage.h
//  JiverExample
//
//  Created by Jed Kyung on 2015. 4. 10..
//  Copyright (c) 2015년 JIVER.CO. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JiverMessageModel.h"

/**
 *  Class for broadcast messages. This class is comprised of message and additional data.
 */
@interface JiverBroadcastMessage : JiverMessageModel

/**
 *  Broadcast message
 */
@property (retain) NSString *message;

@property (retain) NSDictionary *jsonObj;

/**
 *  Additional data
 */
@property (retain) NSString *data;

- (id) initWithDic:(NSDictionary *)dic inPresent:(BOOL)present;

- (NSString *) toJson;

@end
