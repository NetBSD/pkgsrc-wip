$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, 
  FreeBSD's electron patches, and pkgsrc's nodejs patches

--- electron/script/lib/config.py.orig	2026-10-16 03:32:58.000000000 +0000
+++ electron/script/lib/config.py
@@ -7,6 +7,11 @@ PLATFORM = {
   'cygwin': 'win32',
   'msys': 'win32',
   'darwin': 'darwin',
+  'freebsd13': 'freebsd',
+  'freebsd14': 'freebsd',
+  'freebsd15': 'freebsd',
+  'freebsd16': 'freebsd',
+  'netbsd': 'netbsd',
   'linux': 'linux',
   'linux2': 'linux',
   'win32': 'win32',
