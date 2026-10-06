$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/squirrel.mac/vendor/ReactiveObjC/ReactiveObjC/NSUserDefaults+RACSupport.m.orig	2019-03-14 15:12:17.000000000 +0000
+++ third_party/squirrel.mac/vendor/ReactiveObjC/ReactiveObjC/NSUserDefaults+RACSupport.m
@@ -7,7 +7,11 @@
 //
 
 #import "NSUserDefaults+RACSupport.h"
+#if defined(BUILDING_RAC_FRAMEWORK)
+#import "extobjc/EXTScope.h"
+#else
 #import <ReactiveObjC/EXTScope.h>
+#endif
 #import "NSNotificationCenter+RACSupport.h"
 #import "NSObject+RACDeallocating.h"
 #import "RACChannel.h"
