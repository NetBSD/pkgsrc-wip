$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, 
  FreeBSD's electron patches, and pkgsrc's nodejs patches

--- electron/spec/api-content-tracing.spec.ts.orig	2026-10-16 03:32:58.000000000 +0000
+++ electron/spec/api-content-tracing.spec.ts
@@ -23,7 +23,7 @@ const isCI = !!process.env.CI;
 const fixturesPath = path.resolve(import.meta.dirname, 'fixtures');
 
 // FIXME: The tests are skipped on linux arm/arm64
-ifdescribe(!['arm', 'arm64'].includes(process.arch) || process.platform !== 'linux')('contentTracing', () => {
+ifdescribe(!['arm', 'arm64'].includes(process.arch) || (process.platform !== 'linux' && process.platform !== 'freebsd' && process.platform !== 'netbsd'))('contentTracing', () => {
   let pendingRecording: Promise<string> | undefined;
   const record = (
     options: TraceConfig | TraceCategoriesAndOptions,
@@ -118,7 +118,7 @@ ifdescribe(!['arm', 'arm64'].includes(pr
     });
   });
 
-  ifdescribe(process.platform !== 'linux')('stopRecording', { timeout: recordingTimeout }, () => {
+  ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd' && process.platform !== 'netbsd')('stopRecording', { timeout: recordingTimeout }, () => {
     // FIXME(samuelmaddock): this test regularly flakes
     it.skip('does not crash on empty string', async () => {
       const options = {
