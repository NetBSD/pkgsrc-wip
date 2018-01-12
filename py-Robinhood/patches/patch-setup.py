$NetBSD$

--- setup.py.orig	2017-11-07 15:29:40.000000000 +0000
+++ setup.py
@@ -6,7 +6,7 @@ from setuptools import setup, find_packa
 from setuptools.command.test import test as TestCommand
 
 HERE = path.abspath(path.dirname(__file__))
-__version__ = '1.0.0'
+__version__ = '1.0.1'
 
 REQUIRES = [
     'requests~=2.13.0',
@@ -107,8 +107,6 @@ setup(
     keywords='Robinhood trade API',
     packages=find_packages(),
     data_files=[
-        ('docs', include_all_subfiles('docs')),
-        ('tests', include_all_subfiles('tests'))
     ],
     install_requires=get_requirements(),
     tests_require=get_requirements(True),
