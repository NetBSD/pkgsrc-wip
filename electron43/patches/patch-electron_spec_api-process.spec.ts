$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, 
  FreeBSD's electron patches, and pkgsrc's nodejs patches

--- electron/spec/api-process.spec.ts.orig	2026-10-16 03:32:58.000000000 +0000
+++ electron/spec/api-process.spec.ts
@@ -44,7 +44,7 @@ describe('process module', () => {
       it('resolves promise successfully with valid data', async () => {
         const memoryInfo = await invoke(() => process.getProcessMemoryInfo());
         expect(memoryInfo).toBeTypeOf('object');
-        if (process.platform === 'linux' || process.platform === 'win32') {
+        if (process.platform === 'linux' || process.platform === 'win32' || process.platform === 'freebsd' || process.platform === 'netbsd') {
           expect(memoryInfo.residentSet).toBeTypeOf('number');
           expect(memoryInfo.residentSet).toBeGreaterThan(0);
         }
@@ -61,7 +61,7 @@ describe('process module', () => {
         const systemMemoryInfo = await invoke(() => process.getSystemMemoryInfo());
         expect(systemMemoryInfo.free).toBeTypeOf('number');
         expect(systemMemoryInfo.total).toBeTypeOf('number');
-        if (process.platform === 'linux') {
+        if (process.platform === 'linux' || process.platform === 'freebsd' || process.platform === 'netbsd') {
           expect(systemMemoryInfo.available).toBeTypeOf('number');
           expect(systemMemoryInfo.available).toBeGreaterThan(0);
         }
@@ -141,7 +141,7 @@ describe('process module', () => {
     generateSpecs((fn, ...args) => fn(...args));
   });
 
-  ifdescribe(process.platform === 'linux')('process.env', () => {
+  ifdescribe(process.platform === 'linux' || process.platform === 'freebsd' || process.platform === 'netbsd')('process.env', () => {
     it('can add variables while another thread reads the environment', async () => {
       const fixture = path.join(import.meta.dirname, 'fixtures', 'api', 'environ-write-race.js');
       const child = cp.spawn(process.execPath, [fixture], { stdio: ['ignore', 'pipe', 'inherit'] });
