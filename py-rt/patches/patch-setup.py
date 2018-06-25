$NetBSD$

Remove not needed dependency to `nose'.

It is just a leftover needed for upstream CI, no part of code
actually use it.

--- setup.py.orig	2017-12-01 15:48:56.000000000 +0000
+++ setup.py
@@ -17,7 +17,7 @@ setup(name='rt',
     author='Jiri Machalek',
     author_email='edvard.rejthar@nic.cz',
     url='https://github.com/CZ-NIC/python-rt',
-    install_requires=['requests', 'six', 'nose'],
+    install_requires=['requests', 'six'],
     py_modules=['rt'],
     classifiers=[
         'Development Status :: 5 - Production/Stable',
