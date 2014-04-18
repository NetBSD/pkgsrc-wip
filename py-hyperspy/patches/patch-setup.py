$NetBSD: patch-setup.py,v 1.1 2014/04/18 21:26:21 jihbed Exp $

--- setup.py.orig	2014-04-18 22:04:23.000000000 +0100
+++ setup.py	2014-04-18 22:05:03.000000000 +0100
@@ -45,7 +45,7 @@
         if 'wininst' in arg:
             return True
 
-scripts = ['bin/hyperspy', ]
+scripts = ['bin/hyperspy'+sys.version[0:3], ]
 
 if are_we_building4windows() or os.name in ['nt', 'dos']:
     # In the Windows command prompt we can't execute Python scripts
