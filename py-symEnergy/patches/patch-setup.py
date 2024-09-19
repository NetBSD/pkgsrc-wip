$NetBSD$

--- setup.py.orig	2020-04-08 12:33:37.000000000 +0000
+++ setup.py
@@ -2,9 +2,6 @@ import fnmatch
 from setuptools import find_packages, setup
 from setuptools.command.build_py import build_py as build_py_orig
 
-with open("description_pypi.rst", "r") as fh:
-    long_description = fh.read()
-
 setup(
     name="SymEnergy",
     version="1.0.7",
@@ -12,8 +9,6 @@ setup(
     author_email="m.c.soini@posteo.de",
     description=("Lagrange multiplier based energy market toy "
                  "modeling framework"),
-    long_description=long_description,
-    long_description_content_type="text/x-rst",
     url="https://github.com/mcsoini/symenergy",
     packages=find_packages(),
     install_requires=['pandas', 'orderedset', 'sympy', 'numpy', 'wrapt',
