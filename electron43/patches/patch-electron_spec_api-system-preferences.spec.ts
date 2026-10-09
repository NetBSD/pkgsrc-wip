$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/spec/api-system-preferences.spec.ts.orig	2026-10-06 22:48:58.000000000 +0000
+++ electron/spec/api-system-preferences.spec.ts
@@ -5,8 +5,8 @@ import { expect } from 'chai';
 import { ifdescribe, ifit } from './lib/spec-helpers.ts';
 
 describe('systemPreferences module', () => {
-  ifdescribe(['win32', 'linux'].includes(process.platform))('systemPreferences.getAccentColor', () => {
-    ifit(process.platform === 'linux')('should return a string', () => {
+  ifdescribe(['win32', 'linux', 'freebsd', 'netbsd'].includes(process.platform))('systemPreferences.getAccentColor', () => {
+    ifit(process.platform === 'linux' || process.platform === 'freebsd' || process.platform === 'netbsd')('should return a string', () => {
       // Testing this properly (i.e. non-empty string) requires
       // some tricky D-Bus mock setup.
       const accentColor = systemPreferences.getAccentColor();
