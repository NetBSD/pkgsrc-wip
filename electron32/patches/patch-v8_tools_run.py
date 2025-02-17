$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- v8/tools/run.py.orig	2024-10-18 12:48:36.152417400 +0000
+++ v8/tools/run.py
@@ -9,7 +9,7 @@ scripts."""
 import subprocess
 import sys
 
-result = subprocess.call(sys.argv[1:])
+sys.exit(subprocess.call(sys.argv[1:], env={"LD_LIBRARY_PATH":"@WRKSRC@/out/Release"}))
 if result != 0:
   # Windows error codes such as 0xC0000005 and 0xC0000409 are much easier
   # to recognize and differentiate in hex.
