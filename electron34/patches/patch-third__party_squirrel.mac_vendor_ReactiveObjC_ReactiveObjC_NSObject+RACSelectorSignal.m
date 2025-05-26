$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/squirrel.mac/vendor/ReactiveObjC/ReactiveObjC/NSObject+RACSelectorSignal.m.orig	2019-03-14 15:12:17.000000000 +0000
+++ third_party/squirrel.mac/vendor/ReactiveObjC/ReactiveObjC/NSObject+RACSelectorSignal.m
@@ -7,7 +7,11 @@
 //
 
 #import "NSObject+RACSelectorSignal.h"
+#if defined(BUILDING_RAC_FRAMEWORK)
+#import "extobjc/EXTRuntimeExtensions.h"
+#else
 #import <ReactiveObjC/EXTRuntimeExtensions.h>
+#endif
 #import "NSInvocation+RACTypeParsing.h"
 #import "NSObject+RACDeallocating.h"
 #import "RACCompoundDisposable.h"
