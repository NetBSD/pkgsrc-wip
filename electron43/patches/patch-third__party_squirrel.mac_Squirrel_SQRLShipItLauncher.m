$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/squirrel.mac/Squirrel/SQRLShipItLauncher.m.orig	2021-06-18 22:08:36.000000000 +0000
+++ third_party/squirrel.mac/Squirrel/SQRLShipItLauncher.m
@@ -7,9 +7,9 @@
 //
 
 #import "SQRLShipItLauncher.h"
-#import "EXTScope.h"
+#import <ReactiveObjC/EXTScope.h>
 #import "SQRLDirectoryManager.h"
-#import <ReactiveCocoa/ReactiveCocoa.h>
+#import <ReactiveObjC/ReactiveObjC.h>
 #import <Security/Security.h>
 #import <ServiceManagement/ServiceManagement.h>
 #import <launch.h>
