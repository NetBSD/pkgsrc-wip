$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, 
  FreeBSD's electron patches, and pkgsrc's nodejs patches

--- electron/spec/api-content-tracing.spec.ts.orig	2026-10-30 06:33:33.000000000 +0000
+++ electron/spec/api-content-tracing.spec.ts
@@ -23,7 +23,7 @@ const isCI = !!process.env.CI;
 const fixturesPath = path.resolve(import.meta.dirname, 'fixtures');
 
 // FIXME: The tests are skipped on linux arm64
-ifdescribe(process.arch !== 'arm64' || process.platform !== 'linux')('contentTracing', () => {
+ifdescribe(process.arch !== 'arm64' || (process.platform !== 'linux' && process.platform !== 'freebsd' && process.platform !== 'netbsd'))('contentTracing', () => {
   let pendingRecording: Promise<string> | undefined;
   const record = (
     options: TraceConfig | TraceCategoriesAndOptions,
@@ -125,7 +125,7 @@ ifdescribe(process.arch !== 'arm64' || p
     });
   });
 
-  ifdescribe(process.platform !== 'linux')('stopRecording', () => {
+  ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd' && process.platform !== 'netbsd')('stopRecording', () => {
     // FIXME(samuelmaddock): this test regularly flakes
     it.skip('does not crash on empty string', async () => {
       const options = {
