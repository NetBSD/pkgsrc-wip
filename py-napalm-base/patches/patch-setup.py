$NetBSD$

Don't use pip in setup.py, it's not best practice.
Also, using requirements.txt to define install_reqs is
also dubious.

--- setup.py.orig	2017-11-23 10:23:04.000000000 +0000
+++ setup.py
@@ -2,12 +2,12 @@
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
