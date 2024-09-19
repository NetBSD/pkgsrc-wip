$NetBSD$

--- setup.py.orig	2016-07-09 04:16:14.000000000 +0000
+++ setup.py
@@ -1,3 +1,4 @@
+import sys
 try:
     from setuptools import setup
 except ImportError:
@@ -35,7 +36,7 @@ if __name__ == '__main__':
           url='https://github.com/micheles/plac',
           license="BSD License",
           py_modules=['plac_core', 'plac_ext', 'plac_tk', 'plac'],
-          scripts=['plac_runner.py'],
+          scripts=['plac_runner.py'+sys.version[0:3]],
           install_requires=require('argparse', 'multiprocessing'),
           keywords="command line arguments parser",
           platforms=["All"],
