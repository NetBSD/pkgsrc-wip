$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- build/gn_run_binary.py.orig	2025-02-24 19:59:26.000000000 +0000
+++ build/gn_run_binary.py
@@ -23,7 +23,7 @@ if not os.path.isabs(path):
 # The rest of the arguments are passed directly to the executable.
 args = [path] + sys.argv[2:]
 
-ret = subprocess.call(args)
+ret = subprocess.call(args, env={"CHROME_EXE_PATH":"@WRKSRC@/out/Release/chrome","LD_LIBRARY_PATH":"@WRKSRC@/out/Release"})
 if ret != 0:
   if ret <= -100:
     # Windows error codes such as 0xC0000005 and 0xC0000409 are much easier to
