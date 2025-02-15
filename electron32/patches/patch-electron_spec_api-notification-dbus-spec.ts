$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/spec/api-notification-dbus-spec.ts.orig	2025-01-21 17:36:55.000000000 +0000
+++ electron/spec/api-notification-dbus-spec.ts
@@ -19,7 +19,8 @@ import { ifdescribe } from './lib/spec-h
 
 const fixturesPath = path.join(__dirname, 'fixtures');
 
-const skip = process.platform !== 'linux' ||
+const skip = (process.platform !== 'linux' && process.platform !== 'freebsd' &&
+                        process.platform !== 'openbsd' && process.platform !== 'netbsd') ||
              process.arch === 'ia32' ||
              process.arch.indexOf('arm') === 0 ||
              !process.env.DBUS_SESSION_BUS_ADDRESS;
