$NetBSD: patch-setup.py,v 1.1 2014/03/21 10:54:22 jihbed Exp $

--- setup.py.orig	2014-03-21 11:37:24.000000000 +0100
+++ setup.py	2014-03-21 11:42:25.000000000 +0100
@@ -72,7 +72,7 @@
         'Topic :: System :: Distributed Computing',
         'Topic :: Utilities',
         ],
-    scripts = ['fjd/scripts/fjd-dispatcher', 'fjd/scripts/fjd-worker',
-              'fjd/scripts/fjd-recruiter', 'fjd/scripts/bgscreen']
+    scripts = ['fjd/scripts/fjd-dispatcher'+sys.version[0:3], 'fjd/scripts/fjd-worker'+sys.version[0:3],
+              'fjd/scripts/fjd-recruiter'+sys.version[0:3], 'fjd/scripts/bgscreen'+sys.version[0:3]]
 )
 
