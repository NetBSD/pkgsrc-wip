$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/squirrel.mac/Squirrel/SQRLZipArchiver.m.orig	2021-06-18 22:08:36.000000000 +0000
+++ third_party/squirrel.mac/Squirrel/SQRLZipArchiver.m
@@ -7,8 +7,8 @@
 //
 
 #import "SQRLZipArchiver.h"
-#import <ReactiveCocoa/EXTScope.h>
-#import <ReactiveCocoa/ReactiveCocoa.h>
+#import <ReactiveObjC/EXTScope.h>
+#import <ReactiveObjC/ReactiveObjC.h>
 
 NSString * const SQRLZipArchiverErrorDomain = @"SQRLZipArchiverErrorDomain";
 NSString * const SQRLZipArchiverExitCodeErrorKey = @"SQRLZipArchiverExitCodeErrorKey";
@@ -135,7 +135,7 @@ const NSInteger SQRLZipArchiverShellTask
 			return [RACSignal
 				zip:@[ self.taskTerminated, self.standardErrorData ]
 				reduce:^(NSNumber *exitStatus, NSData *errorData) {
-					if (exitStatus.intValue == 0) return [RACSignal empty];
+					if (exitStatus.intValue == 0) return [RACSignal return:self];
 
 					NSMutableDictionary *userInfo = [NSMutableDictionary dictionary];
 					userInfo[SQRLZipArchiverExitCodeErrorKey] = exitStatus;
