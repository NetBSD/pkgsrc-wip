$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/squirrel.mac/Squirrel/RACSignal+SQRLTransactionExtensions.h.orig	2021-06-18 22:08:36.000000000 +0000
+++ third_party/squirrel.mac/Squirrel/RACSignal+SQRLTransactionExtensions.h
@@ -6,7 +6,7 @@
 //  Copyright (c) 2013 GitHub. All rights reserved.
 //
 
-#import <ReactiveCocoa/RACSignal.h>
+#import <ReactiveObjC/RACSignal.h>
 
 @interface RACSignal (SQRLTransactionExtensions)
 
