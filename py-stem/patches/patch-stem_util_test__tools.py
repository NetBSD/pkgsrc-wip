$NetBSD$

Fix build with python-3.6+
https://gitweb.torproject.org/stem.git/commit/?id=6c677b6

--- stem/util/test_tools.py.orig	2017-11-02 17:11:48.000000000 +0000
+++ stem/util/test_tools.py
@@ -148,7 +148,6 @@ class AsyncTest(object):
     self._threaded = threaded
 
     self.method = lambda test: self.result(test)  # method that can be mixed into TestCases
-    self.method.async = self
 
     self._process = None
     self._process_pipe = None
