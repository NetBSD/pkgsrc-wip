$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, 
  FreeBSD's electron patches, and pkgsrc's nodejs patches

--- electron/spec/api-screen.spec.ts.orig	2026-10-16 03:32:58.000000000 +0000
+++ electron/spec/api-screen.spec.ts
@@ -97,7 +97,7 @@ describe('screen module', { tags: ['seri
 
       const { size } = display!;
 
-      if (process.platform === 'linux') {
+      if (process.platform === 'linux' || process.platform === 'freebsd' || process.platform === 'netbsd') {
         expect(size).toHaveProperty('width', expect.any(Number));
         expect(size).toHaveProperty('height', expect.any(Number));
       } else {
@@ -113,7 +113,7 @@ describe('screen module', { tags: ['seri
 
       const { workAreaSize } = display!;
 
-      if (process.platform === 'linux') {
+      if (process.platform === 'linux' || process.platform === 'freebsd' || process.platform === 'netbsd') {
         expect(workAreaSize).toHaveProperty('width', expect.any(Number));
         expect(workAreaSize).toHaveProperty('height', expect.any(Number));
       } else {
@@ -131,7 +131,7 @@ describe('screen module', { tags: ['seri
       expect(bounds).toHaveProperty('x', expect.any(Number));
       expect(bounds).toHaveProperty('y', expect.any(Number));
 
-      if (process.platform === 'linux') {
+      if (process.platform === 'linux' || process.platform === 'freebsd' || process.platform === 'netbsd') {
         expect(bounds).toHaveProperty('width', expect.any(Number));
         expect(bounds).toHaveProperty('height', expect.any(Number));
       } else {
