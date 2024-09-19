$NetBSD: patch-setup.py,v 1.1 2012/11/09 17:43:06 jihbed Exp $

--- setup.py.orig	2012-11-09 18:34:45.000000000 +0100
+++ setup.py	2012-11-09 18:36:02.000000000 +0100
@@ -102,7 +102,7 @@
        packages = ['Forthon'],
        package_dir = {'Forthon': 'Lib'},
        data_files = [('Forthon', ['License.txt','Src/Forthon.h','Src/Forthon.c'])],
-       scripts = [Forthon],
+       scripts = [Forthon+sys.version[0:3]],
        cmdclass = {'build_py':build_py}
        )
 
