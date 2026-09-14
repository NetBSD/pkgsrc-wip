$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/typescript/typescript.py.orig	2026-09-07 10:14:27.000000000 +0000
+++ third_party/typescript/typescript.py
@@ -11,6 +11,9 @@ import os
 
 
 def GetBinaryPath():
+  if platform.system() in ['OpenBSD', 'FreeBSD', 'NetBSD']:
+    return "tsc"
+
   if platform.machine() == 'arm64':
     darwin_path = 'mac-arm64'
   else:
