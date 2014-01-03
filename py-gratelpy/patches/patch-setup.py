$NetBSD: patch-setup.py,v 1.1 2014/01/03 00:29:25 jihbed Exp $

--- setup.py.orig	2013-12-07 10:28:31.000000000 +0100
+++ setup.py	2014-01-03 01:03:56.000000000 +0100
@@ -92,12 +92,12 @@
 
 version = get_version()
 
-gratelpy_scripts = [join('bin', 'gratelpy_subclient'), 
-                    join('bin', 'gratelpy_fragment_server'), 
-                    join('bin', 'gratelpy_check_data'), 
-                    join('bin', 'gratelpy_benchmark'),
-                    join('bin', 'gratelpy_test'),
-                    join('bin', 'gratelpy_time')]
+gratelpy_scripts = [join('bin', 'gratelpy_subclient'+sys.version[0:3]), 
+                    join('bin', 'gratelpy_fragment_server'+sys.version[0:3]), 
+                    join('bin', 'gratelpy_check_data'+sys.version[0:3]), 
+                    join('bin', 'gratelpy_benchmark'+sys.version[0:3]),
+                    join('bin', 'gratelpy_test'+sys.version[0:3]),
+                    join('bin', 'gratelpy_time'+sys.version[0:3])]
                         
 def windows_prepare(gratelpy_scripts):
     bat = ['@echo off\n',
