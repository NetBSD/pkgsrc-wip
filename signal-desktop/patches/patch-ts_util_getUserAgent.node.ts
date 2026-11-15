$NetBSD$

* Add Free- and NetBSD support

--- ts/util/getUserAgent.node.ts.orig	2026-10-28 21:49:13.000000000 +0000
+++ ts/util/getUserAgent.node.ts
@@ -9,6 +9,8 @@ const PLATFORM_STRINGS: { [platform: str
   win32: 'Windows',
   darwin: 'macOS',
   linux: 'Linux',
+  freebsd: 'FreeBSD',
+  netbsd: 'NetBSD',
 };
 
 export function getUserAgent(
