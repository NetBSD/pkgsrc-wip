$NetBSD$

- Be more liberal about requirements
- Do not install tests.
  Also shared upstream via <https://github.com/jorgebastida/awslogs/pull/324>.
- Remove no longer valid `python_requires'. We already specify that it is only
  for Python 3.x in pkgsrc.

--- setup.py.orig	2020-07-10 07:01:23.000000000 +0000
+++ setup.py
@@ -3,7 +3,7 @@ from setuptools import setup, find_packa
 
 install_requires = [
     'boto3>=1.5.0',
-    'jmespath>=0.7.1,<1.0.0',
+    'jmespath>=0.7.1',
     'termcolor>=1.1.0',
     'python-dateutil>=2.4.0'
 ]
@@ -19,9 +19,8 @@ setup(
     description='awslogs is a simple command line tool to read aws cloudwatch logs.',
     long_description='awslogs is a simple command line tool to read aws cloudwatch logs.',
     keywords="aws logs cloudwatch",
-    packages=find_packages(),
+    packages=find_packages(exclude=('tests',)),
     platforms='any',
-    python_requires=">=3.5.*",
     install_requires=install_requires,
     test_suite='tests',
     classifiers=[
