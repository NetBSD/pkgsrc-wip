$NetBSD: patch-setup.py,v 1.2 2011/04/10 15:09:49 ryo-on Exp $

* Support NetBSD

--- setup.py.orig	2011-04-09 09:12:39.000000000 +0000
+++ setup.py
@@ -76,7 +76,7 @@ for language in languages:
     setupOptions['classifiers'].append('Natural Language :: %s'%language)
 
 system = platform.system()
-if system == 'Linux':
+if (system == 'Linux') or (system == 'NetBSD'):
     setupOptions['package_data'] = {'taskcoachlib': ['bin.in/linux/_pysyncml.so']}
     # Add data files for Debian-based systems:
     current_dist = [dist.lower() for dist in platform.dist()]
