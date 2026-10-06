$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/squirrel.mac/vendor/ReactiveObjC/ReactiveObjC/UIRefreshControl+RACCommandSupport.m.orig	2019-03-14 15:12:17.000000000 +0000
+++ third_party/squirrel.mac/vendor/ReactiveObjC/ReactiveObjC/UIRefreshControl+RACCommandSupport.m
@@ -7,7 +7,11 @@
 //
 
 #import "UIRefreshControl+RACCommandSupport.h"
+#if defined(BUILDING_RAC_FRAMEWORK)
+#import "extobjc/EXTKeyPathCoding.h"
+#else
 #import <ReactiveObjC/EXTKeyPathCoding.h>
+#endif
 #import "RACCommand.h"
 #import "RACCompoundDisposable.h"
 #import "RACDisposable.h"
