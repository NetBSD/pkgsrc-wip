$NetBSD$

--- tests/__init__.py.orig	2010-05-05 21:00:22.000000000 +0000
+++ tests/__init__.py
@@ -1,12 +1,12 @@
 import unittest, doctest
 
-import test_ini
-import test_misc
-import test_fuzz
-import test_compat
-import test_unicode
-import test_tidy
-import test_multiprocessing
+from . import test_ini
+from . import test_misc
+from . import test_fuzz
+from . import test_compat
+from . import test_unicode
+from . import test_tidy
+from . import test_multiprocessing
 from iniparse import config
 from iniparse import ini
 
