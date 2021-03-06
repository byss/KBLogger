//
//  KBLogger.h
//  KBLogger
//
//  Created by Kirill Bystrov on 4/1/16.
//  Copyright © 2016 Kirill byss Bystrov. All rights reserved.
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM (NSInteger, KBLogLevel) {
	KBLogLevelNone = 0,
	KBLogLevelError = 1,
	KBLogLevelWarning = 2,
	KBLogLevelInfo = 3,
	KBLogLevelDebug = 4,
};

@protocol KBLogger <NSObject>

@required
@property (nonatomic, assign) KBLogLevel logLevel;

- (void) logWithLevel: (KBLogLevel) level module: (char const *_Nullable) module file: (char const *_Nonnull) file line: (int) line function: (char const *_Nonnull) function message: (NSString *_Nullable) fmt, ...;

@end

@interface KBLogger: NSObject <KBLogger>

+ (id <KBLogger> _Nonnull) sharedLogger;
+ (void) setSharedLogger: (id <KBLogger> _Nullable) sharedLogger;

@end

#	define KBLOG_MACRO(lvl, mod, fmt, args...) ([[KBLogger sharedLogger] logWithLevel:lvl module:mod file:__FILE__ line:__LINE__ function:__PRETTY_FUNCTION__ message:fmt, ##args])
#	define KBLOGE(fmt, args...) KBLOG_MACRO (KBLogLevelError, NULL, fmt, ##args)
#	define KBLOGW(fmt, args...) KBLOG_MACRO (KBLogLevelWarning, NULL, fmt, ##args)
#	define KBLOGI(fmt, args...) KBLOG_MACRO (KBLogLevelInfo, NULL, fmt, ##args)
#	define KBLOGD(fmt, args...) KBLOG_MACRO (KBLogLevelDebug, NULL, fmt, ##args)
