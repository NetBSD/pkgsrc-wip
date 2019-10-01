$NetBSD$

--- setup.py.orig	2010-06-12 16:15:40.000000000 +0000
+++ setup.py
@@ -1,6 +1,6 @@
 #!/usr/bin/env python
 
-from distutils.core import setup
+from setuptools import setup
 
 VERSION = '0.4'
 
@@ -24,12 +24,16 @@ use.''',
         'License :: OSI Approved :: Python Software Foundation License',
         'Operating System :: OS Independent',
         'Programming Language :: Python',
-        'Programming Language :: Python :: 2.4',
-        'Programming Language :: Python :: 2.5',
+        'Programming Language :: Python :: 2'
         'Programming Language :: Python :: 2.6',
+        'Programming Language :: Python :: 2.7',
+        'Programming Language :: Python :: 3',
+        'Programming Language :: Python :: 3.3',
+        'Programming Language :: Python :: 3.4'
         'Topic :: Software Development :: Libraries :: Python Modules',
       ],
       packages = ['iniparse'],
+      install_requires=['six'],
       data_files = [
         ('share/doc/iniparse-%s' % VERSION, ['README', 'LICENSE-PSF',
                                              'LICENSE', 'Changelog',
