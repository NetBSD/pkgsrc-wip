$NetBSD$

--- tests/test_ini.py.orig	2019-10-01 14:22:20.483058991 +0000
+++ tests/test_ini.py
@@ -1,5 +1,5 @@
 import unittest
-from StringIO import StringIO
+from six import StringIO
 
 from iniparse import ini
 from iniparse import compat
@@ -195,13 +195,13 @@ but = also me
         self.assertEqual(p._data.find('section2').find('just').value, 'kidding')
 
         itr = p._data.finditer('section1')
-        v = itr.next()
+        v = next(itr)
         self.assertEqual(v.find('help').value, 'yourself')
         self.assertEqual(v.find('but').value, 'also me')
-        v = itr.next()
+        v = next(itr)
         self.assertEqual(v.find('help').value, 'me')
         self.assertEqual(v.find('I\'m').value, 'desperate')
-        self.assertRaises(StopIteration, itr.next)
+        self.assertRaises(StopIteration, next, itr)
 
         self.assertRaises(KeyError, p._data.find, 'section')
         self.assertRaises(KeyError, p._data.find('section2').find, 'ahem')
