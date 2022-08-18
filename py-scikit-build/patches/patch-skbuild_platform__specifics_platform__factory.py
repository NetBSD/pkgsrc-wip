$NetBSD$

--- skbuild/platform_specifics/platform_factory.py.orig	2022-05-18 17:52:53.000000000 +0000
+++ skbuild/platform_specifics/platform_factory.py
@@ -31,7 +31,7 @@ def get_platform():
 
         return osx.OSXPlatform()
 
-    if this_platform in {"freebsd", "os400", "openbsd"}:
+    if this_platform in {"freebsd", "netbsd", "os400", "openbsd"}:
         from . import bsd
 
         return bsd.BSDPlatform()
