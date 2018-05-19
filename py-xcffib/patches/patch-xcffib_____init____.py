$NetBSD$

Use a portable soname.

--- xcffib/__init__.py.orig	2018-03-07 02:32:37.000000000 +0000
+++ xcffib/__init__.py
@@ -26,7 +26,7 @@ try:
 except ImportError:
     from xcffib.ffi_build import ffi
 
-soname = "libxcb.so.1"
+soname = "libxcb.so"
 if platform.system() == "Darwin":
     soname = "libxcb.dylib"
 elif platform.system() == "Windows":
