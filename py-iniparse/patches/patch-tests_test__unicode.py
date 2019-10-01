$NetBSD$

--- tests/test_unicode.py.orig	2008-12-06 06:44:49.000000000 +0000
+++ tests/test_unicode.py
@@ -1,5 +1,5 @@
 import unittest
-from StringIO import StringIO
+import six
 from iniparse import compat, ini
 
 class test_unicode(unittest.TestCase):
@@ -17,14 +17,14 @@ baz = Marc-Andr\202
     """
 
     def basic_tests(self, s, strable):
-        f = StringIO(s)
+        f = six.StringIO(s)
         i = ini.INIConfig(f)
-        self.assertEqual(unicode(i), s)
-        self.assertEqual(type(i.foo.bar), unicode)
+        self.assertEqual(six.text_type(i), s)
+        self.assertEqual(type(i.foo.bar), six.text_type)
         if strable:
             self.assertEqual(str(i), str(s))
         else:
-            self.assertRaises(UnicodeEncodeError, lambda: str(i))
+            self.assertRaises(UnicodeEncodeError, lambda: six.text_type(i).encode('ascii'))
         return i
 
     def test_ascii(self):
