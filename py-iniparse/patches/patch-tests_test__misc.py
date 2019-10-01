$NetBSD$

--- tests/test_misc.py.orig	2010-05-05 05:15:39.000000000 +0000
+++ tests/test_misc.py
@@ -1,9 +1,9 @@
 import re
 import unittest
 import pickle
-import ConfigParser
+from six.moves import configparser
+from six import StringIO
 from textwrap import dedent
-from StringIO import StringIO
 from iniparse import compat, ini
 
 class CaseSensitiveConfigParser(compat.ConfigParser):
