$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/squirrel.mac/Squirrel/SQRLInstaller.h.orig	2021-06-18 22:08:36.000000000 +0000
+++ third_party/squirrel.mac/Squirrel/SQRLInstaller.h
@@ -37,6 +37,9 @@ extern const NSInteger SQRLInstallerErro
 // There was an error changing the file permissions of the update.
 extern const NSInteger SQRLInstallerErrorChangingPermissions;
 
+// There was a running instance of the app just prior to the update attempt
+extern const NSInteger SQRLInstallerErrorAppStillRunning;
+
 @class RACCommand;
 
 // Performs the installation of an update, saving its intermediate state to user
