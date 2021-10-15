$NetBSD$

Do not install tests.

Also shared upstream via <https://github.com/jorgebastida/awslogs/pull/324>.

--- setup.py.orig	2020-07-10 07:01:23.000000000 +0000
+++ setup.py
@@ -19,7 +19,7 @@ setup(
     description='awslogs is a simple command line tool to read aws cloudwatch logs.',
     long_description='awslogs is a simple command line tool to read aws cloudwatch logs.',
     keywords="aws logs cloudwatch",
-    packages=find_packages(),
+    packages=find_packages(exclude=('tests',)),
     platforms='any',
     python_requires=">=3.5.*",
     install_requires=install_requires,
