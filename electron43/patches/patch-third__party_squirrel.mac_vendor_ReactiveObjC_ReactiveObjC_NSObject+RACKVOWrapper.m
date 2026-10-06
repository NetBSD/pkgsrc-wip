$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/squirrel.mac/vendor/ReactiveObjC/ReactiveObjC/NSObject+RACKVOWrapper.m.orig	2019-03-14 15:12:17.000000000 +0000
+++ third_party/squirrel.mac/vendor/ReactiveObjC/ReactiveObjC/NSObject+RACKVOWrapper.m
@@ -7,8 +7,16 @@
 //
 
 #import "NSObject+RACKVOWrapper.h"
+#if defined(BUILDING_RAC_FRAMEWORK)
+#import "extobjc/EXTRuntimeExtensions.h"
+#else
 #import <ReactiveObjC/EXTRuntimeExtensions.h>
+#endif
+#if defined(BUILDING_RAC_FRAMEWORK)
+#import "extobjc/EXTScope.h"
+#else
 #import <ReactiveObjC/EXTScope.h>
+#endif
 #import "NSObject+RACDeallocating.h"
 #import "NSString+RACKeyPathUtilities.h"
 #import "RACCompoundDisposable.h"
