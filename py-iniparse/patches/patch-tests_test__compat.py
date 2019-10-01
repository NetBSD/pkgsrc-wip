$NetBSD$

--- tests/test_compat.py.orig	2008-12-06 10:15:30.000000000 +0000
+++ tests/test_compat.py
@@ -1,9 +1,16 @@
 from iniparse import compat as ConfigParser
-import StringIO
+from six import StringIO
+try:
+    import UserDict
+except ImportError:
+    import collections as UserDict
 import unittest
-import UserDict
 
-from test import test_support
+import sys
+if sys.version_info[0] < 3:
+    from test import test_support
+else:
+    from test import support as test_support
 
 class SortedDict(UserDict.UserDict):
     def items(self):
@@ -35,7 +42,7 @@ class TestCaseBase(unittest.TestCase):
 
     def fromstring(self, string, defaults=None):
         cf = self.newconfig(defaults)
-        sio = StringIO.StringIO(string)
+        sio = StringIO(string)
         cf.readfp(sio)
         return cf
 
@@ -161,7 +168,7 @@ class TestCaseBase(unittest.TestCase):
                          "No Section!\n")
 
     def parse_error(self, exc, src):
-        sio = StringIO.StringIO(src)
+        sio = StringIO(src)
         self.assertRaises(exc, self.cf.readfp, sio)
 
     def test_query_errors(self):
@@ -181,7 +188,7 @@ class TestCaseBase(unittest.TestCase):
     def get_error(self, exc, section, option):
         try:
             self.cf.get(section, option)
-        except exc, e:
+        except exc as e:
             return e
         else:
             self.fail("expected exception type %s.%s"
@@ -227,7 +234,7 @@ class TestCaseBase(unittest.TestCase):
             "foo: another very\n"
             " long line"
             )
-        output = StringIO.StringIO()
+        output = StringIO()
         cf.write(output)
         self.assertEqual(
             output.getvalue(),
@@ -465,7 +472,7 @@ class SortedTestCase(RawConfigParserTest
                         "o1=4\n"
                         "[a]\n"
                         "k=v\n")
-        output = StringIO.StringIO()
+        output = StringIO()
         self.cf.write(output)
         self.assertEquals(output.getvalue(),
                           "[a]\n"
