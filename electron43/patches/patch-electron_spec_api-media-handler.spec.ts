$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/spec/api-media-handler.spec.ts.orig	2026-10-06 22:48:58.000000000 +0000
+++ electron/spec/api-media-handler.spec.ts
@@ -64,7 +64,7 @@ describe('setDisplayMediaRequestHandler'
 
   // Process-level loopback audio capture (restrictOwnAudio / loopbackWithoutChrome)
   // is not supported on Linux audio backends (PulseAudio / PipeWire).
-  ifit(process.platform !== 'linux')(
+  ifit(process.platform !== 'linux' && process.platform !== 'freebsd' && process.platform !== 'netbsd')(
     'honors the restrictOwnAudio constraint when granted loopback audio',
     async function () {
       if ((await desktopCapturer.getSources({ types: ['screen'] })).length === 0) {
