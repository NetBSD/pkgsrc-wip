$NetBSD$

--- setup.py.orig	2020-09-02 20:39:33.000000000 +0000
+++ setup.py
@@ -3,9 +3,6 @@ from setuptools import setup, find_packa
 with open('README.md') as readme_file:
     README = readme_file.read()
 
-with open('HISTORY.md') as history_file:
-    HISTORY = history_file.read()
-
 setup_args = dict(
     name='quhep',
     version='0.0.3',
@@ -20,7 +17,6 @@ setup_args = dict(
     },
     description='Quantum Machine Learning Framework for High Energy Physics',
     long_description_content_type="text/markdown",
-    long_description=README + '\n\n' + HISTORY,
     license='MIT',
     packages=find_packages(),
     author='Rui Zhang',
