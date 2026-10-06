$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/crash/content/tools/generate_breakpad_symbols.py.orig	2025-02-24 19:59:26.000000000 +0000
+++ components/crash/content/tools/generate_breakpad_symbols.py
@@ -204,7 +204,7 @@ def GetSharedLibraryDependenciesMac(bina
                'rpaths %s' %
                (m.group(1), exe_path, loader_path, ', '.join(rpaths))),
               file=sys.stderr)
-        sys.exit(1)
+        # sys.exit(1)
   return deps
 
 
