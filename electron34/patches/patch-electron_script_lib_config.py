$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/script/lib/config.py.orig	2025-05-09 16:52:15.000000000 +0000
+++ electron/script/lib/config.py
@@ -7,6 +7,10 @@ PLATFORM = {
   'cygwin': 'win32',
   'msys': 'win32',
   'darwin': 'darwin',
+  'freebsd13': 'freebsd',
+  'freebsd14': 'freebsd',
+  'freebsd15': 'freebsd',
+  'netbsd': 'netbsd',
   'linux': 'linux',
   'linux2': 'linux',
   'win32': 'win32',
