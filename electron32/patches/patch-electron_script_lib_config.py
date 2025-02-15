$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/script/lib/config.py.orig	2025-01-21 17:36:55.000000000 +0000
+++ electron/script/lib/config.py
@@ -7,6 +7,11 @@ PLATFORM = {
   'cygwin': 'win32',
   'msys': 'win32',
   'darwin': 'darwin',
+  'freebsd13': 'freebsd',
+  'freebsd14': 'freebsd',
+  'freebsd15': 'freebsd',
+  'openbsd': 'openbsd',
+  'netbsd': 'netbsd',
   'linux': 'linux',
   'linux2': 'linux',
   'win32': 'win32',
