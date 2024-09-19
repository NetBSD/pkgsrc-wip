$NetBSD: patch-setup.py,v 1.1 2015/02/21 16:46:10 jihbed Exp $

--- setup.py.orig	2015-02-21 15:23:26.000000000 +0000
+++ setup.py
@@ -7,9 +7,6 @@ import setuptools as st
 sys.path.append(os.path.join('src'))
 import imreg_dft
 
-reqs = open('requirements.txt', 'r').read().strip().splitlines()
-
-longdesc = open(os.path.join('doc', 'description.rst'), 'r').read()
 
 st.setup(
     name="imreg_dft",
@@ -27,7 +24,7 @@ st.setup(
            'ird = imreg_dft.cli:main',
         ],
     },
-    install_requires=reqs,
+    install_requires='',
     extras_require={
         'plotting':  ["matplotlib>=1.2"],
         'loading images': ["pillow>=2.2"],
@@ -42,6 +39,6 @@ st.setup(
         "Operating System :: OS Independent",
         "License :: OSI Approved :: BSD License",
     ],
-    long_description=longdesc,
+    long_description='',
     zip_safe=True,
 )
