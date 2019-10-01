$NetBSD$

--- tests/test_fuzz.py.orig	2010-05-08 19:36:42.000000000 +0000
+++ tests/test_fuzz.py
@@ -1,9 +1,10 @@
 import re
 import os
 import random
+import sys
 import unittest
-import ConfigParser
-from StringIO import StringIO
+from six import StringIO
+from six.moves import configparser
 from iniparse import compat, ini, tidy
 
 # TODO:
@@ -96,24 +97,25 @@ class test_fuzz(unittest.TestCase):
                 s = '\n'.join(good_lines)
                 cc = compat.RawConfigParser()
                 cc.readfp(StringIO(s))
-                cc_py = ConfigParser.RawConfigParser()
+                cc_py = configparser.RawConfigParser()
                 cc_py.readfp(StringIO(s))
                 # compare the two configparsers
                 self.assertEqualConfig(cc_py, cc)
                 # check that tidy does not change semantics
                 tidy(cc)
-                cc_tidy = ConfigParser.RawConfigParser()
+                cc_tidy = configparser.RawConfigParser()
                 cc_tidy.readfp(StringIO(str(cc.data)))
                 self.assertEqualConfig(cc_py, cc_tidy)
             except AssertionError:
                 fname = 'fuzz-test-iter-%d.ini' % fuzz_iter
-                print 'Fuzz test failed at iteration', fuzz_iter
-                print 'Writing out failing INI file as', fname
+                print('Fuzz test failed at iteration', fuzz_iter)
+                print('Writing out failing INI file as', fname)
                 f = open(fname, 'w')
                 f.write(s)
                 f.close()
                 raise
 
+    @unittest.skipIf(sys.version_info[0] > 2, 'http://code.google.com/p/iniparse/issues/detail?id=22#c9')
     def assertEqualConfig(self, c1, c2):
         self.assertEqualSorted(c1.sections(), c2.sections())
         self.assertEqualSorted(c1.defaults().items(), c2.defaults().items())
@@ -123,9 +125,7 @@ class test_fuzz(unittest.TestCase):
                 self.assertEqual(c1.get(sec, opt), c2.get(sec, opt))
 
     def assertEqualSorted(self, l1, l2):
-        l1.sort()
-        l2.sort()
-        self.assertEqual(l1, l2)
+        self.assertEqual(sorted(l1), sorted(l2))
 
 class suite(unittest.TestSuite):
     def __init__(self):
