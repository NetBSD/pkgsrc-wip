$NetBSD$

Test creates file in wrong location

test_zone.ZoneTestCase.testToFileFilename fails with OSError: [Errno 2] No such file or directory

https://github.com/rthalley/dnspython/pull/210/commits/0add1649c91b4f56b32e73c3a6327519c6eb532e

--- tests/test_zone.py.orig	2016-09-20 09:24:02.000000000 +0000
+++ tests/test_zone.py
@@ -177,7 +177,7 @@ class ZoneTestCase(unittest.TestCase):
     def testToFileFilename(self):
         z = dns.zone.from_file(here('example'), 'example')
         try:
-            z.to_file('example3-filename.out')
+            z.to_file(here('example3-filename.out'))
             ok = filecmp.cmp(here('example3-filename.out'),
                              here('example3.good'))
         finally:
