$NetBSD$

Bump default timeout to 60 seconds.

--- lib/ansible/module_utils/junos.py.orig	2017-06-01 17:00:04.000000000 +0000
+++ lib/ansible/module_utils/junos.py
@@ -43,7 +43,7 @@ junos_argument_spec = {
 
 # Add argument's default value here
 ARGS_DEFAULT_VALUE = {
-    'timeout': 10
+    'timeout': 60
 }
 
 def check_args(module, warnings):
