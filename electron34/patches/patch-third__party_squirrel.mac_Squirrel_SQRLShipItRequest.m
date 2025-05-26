$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/squirrel.mac/Squirrel/SQRLShipItRequest.m.orig	2021-06-18 22:08:36.000000000 +0000
+++ third_party/squirrel.mac/Squirrel/SQRLShipItRequest.m
@@ -9,7 +9,7 @@
 #import "SQRLShipItRequest.h"
 
 #import "EXTKeyPathCoding.h"
-#import <ReactiveCocoa/RACSignal+Operations.h>
+#import <ReactiveObjC/RACSignal+Operations.h>
 
 NSString * const SQRLShipItRequestErrorDomain = @"SQRLShipItRequestErrorDomain";
 
