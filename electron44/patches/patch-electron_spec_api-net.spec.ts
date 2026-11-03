$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, 
  FreeBSD's electron patches, and pkgsrc's nodejs patches

--- electron/spec/api-net.spec.ts.orig	2026-10-30 06:33:33.000000000 +0000
+++ electron/spec/api-net.spec.ts
@@ -2156,7 +2156,7 @@ describe('net module', () => {
   // The select-client-certificate event only fires when the platform cert
   // store yields at least one matching identity, which the test suite cannot
   // guarantee on Linux (NSS) without app.importCertificate.
-  ifdescribe(process.platform !== 'linux')('client certificate authentication', () => {
+  ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd' && process.platform !== 'netbsd')('client certificate authentication', () => {
     let server: https.Server;
     let secureUrl: string;
     const certPath = path.join(fixturesPath, 'certificates');
