$NetBSD$

Disable interactive install.  Not yet addressed upstream; the issue of
compatibility with packaging systems is quite large.

--- setup.py.orig	2020-05-30 23:41:13.000000000 +0000
+++ setup.py
@@ -55,7 +55,7 @@ class weewx_install(install):
 
     def initialize_options(self, *args, **kwargs):
          install.initialize_options(self, *args, **kwargs)
-         self.no_prompt = None
+         self.no_prompt = True
 
     def finalize_options(self):
         # Call my superclass's version
