$NetBSD$

* Add Free- and NetBSD support

--- ts/util/os/shared.std.ts.orig	2026-10-28 21:49:13.000000000 +0000
+++ ts/util/os/shared.std.ts
@@ -24,6 +24,8 @@ export type OSType = {
   getName: () => string;
   isLinux: (minVersion?: string) => boolean;
   isLinuxAppImage: () => boolean;
+  isFreeBSD: (minVersion?: string) => boolean;
+  isNetBSD: (minVersion?: string) => boolean;
   isMacOS: (minVersion?: string) => boolean;
   isMAS: () => boolean;
   isWindows: (minVersion?: string) => boolean;
@@ -33,6 +35,8 @@ export function getOSFunctions(osRelease
   const isMacOS = createIsPlatform('darwin', osRelease);
   const isLinux = createIsPlatform('linux', osRelease);
   const isWindows = createIsPlatform('win32', osRelease);
+  const isFreeBSD = createIsPlatform('freebsd', osRelease);
+  const isNetBSD = createIsPlatform('netbsd', osRelease);
 
   const isLinuxAppImage = (): boolean => {
     return process.platform === 'linux' && process.env.APPIMAGE != null;
@@ -45,6 +49,12 @@ export function getOSFunctions(osRelease
     if (isWindows()) {
       return 'Windows';
     }
+    if (isFreeBSD()) {
+      return 'FreeBSD';
+    }
+    if (isNetBSD()) {
+      return 'NetBSD';
+    }
     return 'Linux';
   };
 
@@ -56,6 +66,12 @@ export function getOSFunctions(osRelease
       // oxlint-disable-next-line signal-desktop/enforce-class-name-has-styles
       return 'os-windows';
     }
+    if (isFreeBSD()) {
+      return 'os-freebsd';
+    }
+    if (isNetBSD()) {
+      return 'os-netbsd';
+    }
     // oxlint-disable-next-line signal-desktop/enforce-class-name-has-styles
     return 'os-linux';
   };
@@ -68,5 +84,7 @@ export function getOSFunctions(osRelease
     isMacOS,
     isMAS: () => process.mas,
     isWindows,
+    isFreeBSD,
+    isNetBSD,
   };
 }
