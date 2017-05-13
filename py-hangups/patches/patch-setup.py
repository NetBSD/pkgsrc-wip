$NetBSD$

Avoid too strict version requirements.

--- setup.py.orig	2016-12-28 23:16:09.000000000 +0000
+++ setup.py
@@ -65,15 +65,15 @@ with open('README.rst') as f:
 # hangups from breaking when new versions of dependencies are released,
 # especially for end-users (non-developers) who use pip to install hangups.
 install_requires = [
-    'ConfigArgParse==0.11.0',
-    'aiohttp>=1.2,<1.3',
-    'appdirs==1.4.0',
-    'readlike==0.1.2',
-    'requests>=2.6.0,<3',  # uses semantic versioning (after 2.6)
-    'ReParser==1.4.3',
-    'protobuf>=3.1.0,<3.2.0',
-    'urwid==1.3.1',
-    'MechanicalSoup==0.6.0',
+    'ConfigArgParse>=0.11.0',
+    'aiohttp>=1.2',
+    'appdirs>=1.4.0',
+    'readlike>=0.1.2',
+    'requests>=2.6.0',  # uses semantic versioning (after 2.6)
+    'ReParser>=1.4.3',
+    'protobuf>=3.1.0',
+    'urwid>=1.3.1',
+    'MechanicalSoup>=0.6.0',
 ]
 
 
