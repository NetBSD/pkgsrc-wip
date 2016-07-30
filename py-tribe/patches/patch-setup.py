$NetBSD$

--- setup.py.orig	2016-07-06 17:48:56.000000000 +0000
+++ setup.py
@@ -20,6 +20,7 @@ See http://bbengfort.github.io/programme
 ##########################################################################
 
 import os
+import sys
 import re
 import codecs
 
@@ -125,7 +126,7 @@ config = {
     "classifiers": CLASSIFIERS,
     "keywords": KEYWORDS,
     "zip_safe": False,
-    "scripts": ['tribe-admin.py'],
+    "scripts": ['tribe-admin.py'+sys.version[0:3]],
 }
 
 ##########################################################################
