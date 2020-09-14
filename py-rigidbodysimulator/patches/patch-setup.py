$NetBSD$

--- setup.py.orig	2019-12-15 18:14:46.000000000 +0000
+++ setup.py
@@ -8,11 +8,7 @@ from subprocess import check_call
 with open("README.md", "r") as fh:
     long_description = fh.read()
 
-
 directory = os.path.dirname(os.path.abspath(__file__))
-requirements_path = (os.path.join(directory,'requirements.txt'))
-with open(requirements_path,mode = 'r') as file:
-    requirements = file.readlines()
 
 extras = {
     'dev': [
@@ -38,8 +34,6 @@ setuptools.setup(
     ],
     python_requires='>=3.5',
 
-    install_requires=requirements,
-    tests_require = test_requirements,
     extras_require=extras,
 
     package_data={
@@ -47,4 +41,4 @@ setuptools.setup(
       },
     scripts=[]
 
-)
\ No newline at end of file
+)
