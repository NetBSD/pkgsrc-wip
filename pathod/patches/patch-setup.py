$NetBSD$

Avoid too strict version requirements (trying to be a bit saner as the comment
suggest).

--- setup.py.orig	2015-12-03 17:13:24.000000000 +0000
+++ setup.py
@@ -49,9 +49,9 @@ setup(
         # It's INSANE that we have to do this, but...
         # FIXME: Requirement to be removed at next release
         "pip>=1.5.6",
-        "requests>=2.8.1, <2.9",
-        "Flask>=0.10.1, <0.11",
-        "pyparsing>=2.0.5, <2.1"
+        "requests>=2.8.1",
+        "Flask>=0.10.1",
+        "pyparsing>=2.0.5"
     ],
     extras_require={
         'dev': [
