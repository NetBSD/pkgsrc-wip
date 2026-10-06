$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/squirrel.mac/vendor/ReactiveObjC/ReactiveObjC/RACDynamicSignal.m.orig	2019-03-14 15:12:17.000000000 +0000
+++ third_party/squirrel.mac/vendor/ReactiveObjC/ReactiveObjC/RACDynamicSignal.m
@@ -7,7 +7,11 @@
 //
 
 #import "RACDynamicSignal.h"
+#if defined(BUILDING_RAC_FRAMEWORK)
+#import "extobjc/EXTScope.h"
+#else
 #import <ReactiveObjC/EXTScope.h>
+#endif
 #import "RACCompoundDisposable.h"
 #import "RACPassthroughSubscriber.h"
 #import "RACScheduler+Private.h"
