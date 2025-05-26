$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/squirrel.mac/Squirrel/SQRLUpdate.m.orig	2021-06-18 22:08:36.000000000 +0000
+++ third_party/squirrel.mac/Squirrel/SQRLUpdate.m
@@ -7,7 +7,7 @@
 //
 
 #import "SQRLUpdate.h"
-#import <ReactiveCocoa/ReactiveCocoa.h>
+#import <ReactiveObjC/ReactiveObjC.h>
 
 NSString * const SQRLUpdateJSONURLKey = @"url";
 NSString * const SQRLUpdateJSONReleaseNotesKey = @"notes";
