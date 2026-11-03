$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, 
  FreeBSD's electron patches, and pkgsrc's nodejs patches

--- electron/node_modules/@sentry/cli/scripts/install.js.orig	2026-11-03 19:08:22.352586569 +0000
+++ electron/node_modules/@sentry/cli/scripts/install.js
@@ -79,6 +79,7 @@ function getDownloadUrl(platform, arch) 
       return `${releasesUrl}-Windows-${archString}.exe`;
     case 'linux':
     case 'freebsd':
+    case 'netbsd':
       return `${releasesUrl}-Linux-${archString}`;
     default:
       return null;
