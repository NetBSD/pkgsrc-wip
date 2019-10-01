$NetBSD$

--- tests/test_tidy.py.orig	2010-05-08 19:36:42.000000000 +0000
+++ tests/test_tidy.py
@@ -1,6 +1,6 @@
 import unittest
 from textwrap import dedent
-from StringIO import StringIO
+from six import StringIO
 
 from iniparse import tidy,INIConfig
 from iniparse.ini import  EmptyLine
