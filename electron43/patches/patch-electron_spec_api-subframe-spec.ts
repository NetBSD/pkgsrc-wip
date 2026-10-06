$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/spec/api-subframe-spec.ts.orig	2025-05-09 16:52:15.000000000 +0000
+++ electron/spec/api-subframe-spec.ts
@@ -218,7 +218,7 @@ describe('renderer nodeIntegrationInSubF
 });
 
 // app.getAppMetrics() does not return sandbox information on Linux.
-ifdescribe(process.platform !== 'linux')('cross-site frame sandboxing', () => {
+ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd' && process.platform !== 'netbsd')('cross-site frame sandboxing', () => {
   let server: http.Server;
   let crossSiteUrl: string;
   let serverUrl: string;
