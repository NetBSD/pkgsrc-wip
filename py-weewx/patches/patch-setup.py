$NetBSD$

Disable interactive install.  Not yet addressed upstream; the issue of
compatibility with packaging systems is quite large.

--- setup.py.orig	2019-07-28 12:28:27.984188292 +0000
+++ setup.py
@@ -72,7 +72,7 @@ class weewx_install(install):
 
     def initialize_options(self, *args, **kwargs):
         install.initialize_options(self, *args, **kwargs)
-        self.no_prompt = None
+        self.no_prompt = True
 
     def finalize_options(self):
         install.finalize_options(self)
