$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/spec/api-screen-spec.ts.orig	2024-12-05 00:03:24.000000000 +0000
+++ electron/spec/api-screen-spec.ts
@@ -95,7 +95,8 @@ describe('screen module', () => {
 
       const { size } = display!;
 
-      if (process.platform === 'linux') {
+      if (process.platform === 'linux' || process.platform === 'freebsd' ||
+           process.platform === 'openbsd' || process.platform === 'netbsd') {
         expect(size).to.have.property('width').that.is.a('number');
         expect(size).to.have.property('height').that.is.a('number');
       } else {
@@ -109,7 +110,8 @@ describe('screen module', () => {
 
       const { workAreaSize } = display!;
 
-      if (process.platform === 'linux') {
+      if (process.platform === 'linux' || process.platform === 'freebsd' ||
+           process.platform === 'openbsd' || process.platform === 'netbsd') {
         expect(workAreaSize).to.have.property('width').that.is.a('number');
         expect(workAreaSize).to.have.property('height').that.is.a('number');
       } else {
@@ -125,7 +127,8 @@ describe('screen module', () => {
       expect(bounds).to.have.property('x').that.is.a('number');
       expect(bounds).to.have.property('y').that.is.a('number');
 
-      if (process.platform === 'linux') {
+      if (process.platform === 'linux' || process.platform === 'freebsd' ||
+           process.platform === 'openbsd' || process.platform === 'netbsd') {
         expect(bounds).to.have.property('width').that.is.a('number');
         expect(bounds).to.have.property('height').that.is.a('number');
       } else {
