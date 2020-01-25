$NetBSD$

Fix syntax errors with Python 3.7 and 3.8.

--- zipline/testing/core.py.orig	2018-03-12 17:33:52.000000000 +0000
+++ zipline/testing/core.py
@@ -914,10 +914,10 @@ class SubTestFailures(AssertionError):
 
     def __str__(self):
         return 'failures:\n  %s' % '\n  '.join(
-            '\n    '.join((
-                ', '.join('%s=%r' % item for item in scope.items()),
+            ('\n    '.join((
+                ', '.join(('%s=%r' % item for item in scope.items())),
                 self._format_exc(exc_info),
-            )) for scope, exc_info in self.failures,
+            )) for scope, exc_info in self.failures),
         )
 
 
