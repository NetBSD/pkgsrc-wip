--- setup.py.orig	2016-02-16 08:36:10.000000000 +0100
+++ setup.py	2016-02-16 08:34:17.000000000 +0100
@@ -23,9 +23,6 @@
 with open('README.rst') as readme_file:
     readme = readme_file.read()
 
-with open('HISTORY.rst') as history_file:
-    history = history_file.read().replace('.. :changelog:', '')
-
 requirements = [
     'future>=0.15.2',
     'binaryornot>=0.2.0',
@@ -34,7 +31,7 @@
     'whichcraft>=0.1.1'
 ]
 
-long_description = readme + '\n\n' + history
+long_description = readme
 
 if sys.argv[-1] == 'readme':
     print(long_description)
