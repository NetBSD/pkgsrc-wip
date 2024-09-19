$NetBSD$

Fix manual page directory.

--- setup.py.orig	2018-12-26 10:06:37.000000000 +0000
+++ setup.py
@@ -1,7 +1,7 @@
 #!/usr/bin/env python
 
 from distutils.core import setup
-import sys
+import sys, os
 
 if sys.version_info < (2, 7) or sys.version_info >= (3,):
 	print("rawdog requires Python 2.7 or later, and not Python 3.")
@@ -14,7 +14,7 @@ setup(name="rawdog",
 	author_email="ats@offog.org",
 	url="http://offog.org/code/rawdog/",
 	scripts=['rawdog'],
-	data_files=[('share/man/man1', ['rawdog.1'])],
+	data_files=[(os.getenv("PKGMANDIR")+'/man1', ['rawdog.1'])],
 	packages=['rawdoglib'],
 	classifiers=[
 		"Development Status :: 5 - Production/Stable",
