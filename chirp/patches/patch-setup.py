$NetBSD$

This software contains darwin specific tweaks which do not apply to pkgsrc

--- setup.py.orig	2020-07-03 15:51:11.931206711 +1000
+++ setup.py	2020-07-03 15:51:24.114023817 +1000
@@ -150,9 +150,7 @@
     f.close()
 
 
-if sys.platform == "darwin":
-    macos_build()
-elif sys.platform == "win32":
+if sys.platform == "win32":
     win32_build()
 else:
     default_build()
