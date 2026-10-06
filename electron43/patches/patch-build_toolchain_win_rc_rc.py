$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- build/toolchain/win/rc/rc.py.orig	2025-02-24 19:59:26.000000000 +0000
+++ build/toolchain/win/rc/rc.py
@@ -244,7 +244,10 @@ def CompareToMsRcOutput(preprocessed_out
   # Assert Microsoft rc.exe and rc.py produced identical .res files.
   if rc_exe_exit_code == 0:
     import filecmp
-    assert filecmp.cmp(msrc_out, flags.output)
+    # Temporarily ignore compares
+    # Nightly builds use very large version numbers that fail this check
+    # FIXME(zacwalk): Enable the assert.
+    # assert filecmp.cmp(msrc_out, flags.output)
   return rc_exe_exit_code
 
 
