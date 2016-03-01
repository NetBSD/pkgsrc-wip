$NetBSD$

Add an EnableModeException.

--- napalm/exceptions.py.orig	2016-02-08 08:22:24.000000000 +0000
+++ napalm/exceptions.py
@@ -20,3 +20,5 @@ class MergeConfigException(Exception):
 
 class SessionLockedException(Exception):
     pass
+class EnableModeException(Exception):
+    pass
