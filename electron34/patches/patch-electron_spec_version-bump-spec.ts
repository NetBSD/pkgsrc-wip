$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/spec/version-bump-spec.ts.orig	2025-05-09 16:52:15.000000000 +0000
+++ electron/spec/version-bump-spec.ts
@@ -53,7 +53,7 @@ class GitFake {
 }
 
 describe('version-bumper', () => {
-  ifdescribe(!(process.platform === 'linux' && process.arch.indexOf('arm') === 0) && process.platform !== 'darwin')('nextVersion', () => {
+  ifdescribe(!((process.platform === 'linux' || process.platform === 'freebsd' || process.platform === 'netbsd') && process.arch.indexOf('arm') === 0) && process.platform !== 'darwin')('nextVersion', () => {
     describe('bump versions', () => {
       const nightlyPattern = /[0-9.]*(-nightly.(\d{4})(\d{2})(\d{2}))$/g;
       const betaPattern = /[0-9.]*(-beta[0-9.]*)/g;
