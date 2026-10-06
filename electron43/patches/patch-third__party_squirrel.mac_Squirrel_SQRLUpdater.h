$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/squirrel.mac/Squirrel/SQRLUpdater.h.orig	2021-06-18 22:08:36.000000000 +0000
+++ third_party/squirrel.mac/Squirrel/SQRLUpdater.h
@@ -7,7 +7,7 @@
 //
 
 #import <Foundation/Foundation.h>
-#import <ReactiveCocoa/ReactiveCocoa.h>
+#import <ReactiveObjC/ReactiveObjC.h>
 
 // Represents the current state of the updater.
 //
@@ -117,6 +117,10 @@ typedef enum {
 // documentation for more information.
 @property (atomic, strong) Class updateClass;
 
+// Publicly exposed for testing purposes, compares two version strings to see if it's
+// allowed.  This assumes that the ElectronSquirrelPreventDowngrades flag is enabled.
++ (bool) isVersionAllowedForUpdate:(NSString*)targetVersion from:(NSString*)currentVersion;
+
 // Initializes an updater that will send the given request to check for updates.
 //
 // This is the designated initializer for this class.
