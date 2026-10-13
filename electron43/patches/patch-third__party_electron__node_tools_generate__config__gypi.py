$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/tools/generate_config_gypi.py.orig	2026-09-07 09:57:40.000000000 +0000
+++ third_party/electron_node/tools/generate_config_gypi.py
@@ -19,7 +19,7 @@ import getnapibuildversion
 
 # Regex used for parsing results of "gn args".
 GN_RE = re.compile(r'(\w+)\s+=\s+(.*?)$', re.MULTILINE)
-GN = 'gn.bat' if sys.platform == 'win32' else 'gn'
+GN = 'gn.bat' if sys.platform == 'win32' else '@WRKSRC@/out/Release/gn'
 
 def bool_to_number(v):
   return 1 if v else 0
