$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- tools/clang/scripts/update.py.orig	2025-02-24 19:59:26.000000000 +0000
+++ tools/clang/scripts/update.py
@@ -304,6 +304,8 @@ def GetDefaultHostOs():
       'win32': 'win',
   }
   default_host_os = _PLATFORM_HOST_OS_MAP.get(sys.platform, sys.platform)
+  if "host_os=mac" in os.environ.get('GCLIENT_EXTRA_ARGS', ''):
+    default_host_os = 'mac'
   if default_host_os == 'mac' and platform.machine() == 'arm64':
     default_host_os = 'mac-arm64'
   return default_host_os
