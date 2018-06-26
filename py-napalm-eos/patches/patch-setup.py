$NetBSD$

Avoid use of "pip" in setup.py.

--- setup.py.orig	2017-03-17 11:55:29.000000000 +0000
+++ setup.py
@@ -3,12 +3,12 @@
 import uuid
 
 from setuptools import setup, find_packages
-from pip.req import parse_requirements
 
 __author__ = 'David Barroso <dbarrosop@dravetech.com>'
 
-install_reqs = parse_requirements('requirements.txt', session=uuid.uuid1())
-reqs = [str(ir.req) for ir in install_reqs]
+with open("requirements.txt") as reqs_file:
+    install_reqs = reqs_file.readlines()
+reqs = install_reqs
 
 setup(
     name="napalm-eos",
