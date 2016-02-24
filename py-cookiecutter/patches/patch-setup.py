$NetBSD$

Set encoding for history file to make this build in C locales.

--- setup.py.orig	2016-02-24 08:53:51.329247880 +0000
+++ setup.py
@@ -23,7 +23,7 @@ if sys.argv[-1] == 'tag':
 with open('README.rst') as readme_file:
     readme = readme_file.read()
 
-with open('HISTORY.rst') as history_file:
+with open('HISTORY.rst', encoding="utf-8") as history_file:
     history = history_file.read().replace('.. :changelog:', '')
 
 requirements = [
