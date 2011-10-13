$NetBSD: patch-setup.py,v 1.4 2011/10/13 11:31:48 ryo-on Exp $

* Support NetBSD

--- setup.py.orig	2011-09-18 19:48:34.000000000 +0000
+++ setup.py
@@ -64,7 +64,7 @@ for language in languages:
     setupOptions['classifiers'].append('Natural Language :: %s'%language)
 
 system = platform.system()
-if system == 'Linux':
+if system == 'Linux' or (system == 'NetBSD') or (system == 'DragonFly'):
     # Add data files for Debian-based systems:
     current_dist = [dist.lower() for dist in platform.dist()]
     if 'debian' in current_dist or 'ubuntu' in current_dist:
