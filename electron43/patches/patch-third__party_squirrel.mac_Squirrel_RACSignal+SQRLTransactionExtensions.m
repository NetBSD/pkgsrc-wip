$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/squirrel.mac/Squirrel/RACSignal+SQRLTransactionExtensions.m.orig	2021-06-18 22:08:36.000000000 +0000
+++ third_party/squirrel.mac/Squirrel/RACSignal+SQRLTransactionExtensions.m
@@ -8,7 +8,7 @@
 
 #import "RACSignal+SQRLTransactionExtensions.h"
 
-#import <ReactiveCocoa/RACDisposable.h>
+#import <ReactiveObjC/RACDisposable.h>
 #import <IOKit/pwr_mgt/IOPMLib.h>
 
 // How long before power assertions time out.
