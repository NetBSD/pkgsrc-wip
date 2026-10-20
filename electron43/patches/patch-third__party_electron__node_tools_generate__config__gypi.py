$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, 
  FreeBSD's electron patches, and pkgsrc's nodejs patches

--- third_party/electron_node/tools/generate_config_gypi.py.orig	2026-10-13 14:09:48.000000000 +0000
+++ third_party/electron_node/tools/generate_config_gypi.py
@@ -19,7 +19,7 @@ import getnapibuildversion
 
 # Regex used for parsing results of "gn args".
 GN_RE = re.compile(r'(\w+)\s+=\s+(.*?)$', re.MULTILINE)
-GN = 'gn.bat' if sys.platform == 'win32' else 'gn'
+GN = 'gn.bat' if sys.platform == 'win32' else '@WRKSRC@/out/Release/gn'
 
 def bool_to_number(v):
   return 1 if v else 0
