$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/lib/browser/api/dialog.ts.orig	2025-05-09 16:52:15.000000000 +0000
+++ electron/lib/browser/api/dialog.ts
@@ -41,7 +41,7 @@ const normalizeAccessKey = (text: string
   // existing single underscores with a second underscore, replace double
   // ampersands with a single ampersand, and replace a single ampersand with
   // a single underscore
-  if (process.platform === 'linux') {
+  if (process.platform === 'linux' || process.platform === 'freebsd' || process.platform === 'netbsd') {
     return text.replaceAll('_', '__').replaceAll(/&(.?)/g, (match, after) => {
       if (after === '&') return after;
       return `_${after}`;
