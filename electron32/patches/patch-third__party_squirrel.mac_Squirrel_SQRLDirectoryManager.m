$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/squirrel.mac/Squirrel/SQRLDirectoryManager.m.orig	2021-06-18 22:08:36.000000000 +0000
+++ third_party/squirrel.mac/Squirrel/SQRLDirectoryManager.m
@@ -8,7 +8,7 @@
 
 #import "SQRLDirectoryManager.h"
 
-#import <ReactiveCocoa/RACSignal+Operations.h>
+#import <ReactiveObjC/RACSignal+Operations.h>
 
 @implementation SQRLDirectoryManager
 
