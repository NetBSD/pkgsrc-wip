$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/squirrel.mac/Squirrel/SQRLTerminationListener.m.orig	2021-06-18 22:08:36.000000000 +0000
+++ third_party/squirrel.mac/Squirrel/SQRLTerminationListener.m
@@ -9,12 +9,12 @@
 #import "SQRLTerminationListener.h"
 
 #import "EXTKeyPathCoding.h"
-#import <ReactiveCocoa/NSArray+RACSequenceAdditions.h>
-#import <ReactiveCocoa/RACDisposable.h>
-#import <ReactiveCocoa/RACScheduler.h>
-#import <ReactiveCocoa/RACSequence.h>
-#import <ReactiveCocoa/RACSignal+Operations.h>
-#import <ReactiveCocoa/RACSubscriber.h>
+#import <ReactiveObjC/NSArray+RACSequenceAdditions.h>
+#import <ReactiveObjC/RACDisposable.h>
+#import <ReactiveObjC/RACScheduler.h>
+#import <ReactiveObjC/RACSequence.h>
+#import <ReactiveObjC/RACSignal+Operations.h>
+#import <ReactiveObjC/RACSubscriber.h>
 
 @interface SQRLTerminationListener ()
 
