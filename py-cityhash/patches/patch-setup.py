$NetBSD$

TODO: Figure out how to detect sse4 for PLIST.

--- setup.py.orig	2024-11-10 21:47:10.445879576 +0000
+++ setup.py
@@ -111,7 +111,7 @@ EXT_MODULES = [
     ),
 ]

-if HAVE_SSE42 and (TARGET_ARCH == "x86_64") and (BITS == 64):
+if False and HAVE_SSE42 and (TARGET_ARCH == "x86_64") and (BITS == 64):
     EXT_MODULES.append(
         Extension(
             "cityhashcrc",
