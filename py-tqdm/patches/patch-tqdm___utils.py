$NetBSD$

NetBSD support.
https://github.com/tqdm/tqdm/commit/a379e330d013cf5f7cec8e9460d1d5e03b543444

--- tqdm/_utils.py.orig	2017-01-23 23:53:53.000000000 +0000
+++ tqdm/_utils.py
@@ -5,7 +5,7 @@ CUR_OS = _curos()
 IS_WIN = CUR_OS in ['Windows', 'cli']
 IS_NIX = (not IS_WIN) and any(
     CUR_OS.startswith(i) for i in
-    ['CYGWIN', 'MSYS', 'Linux', 'Darwin', 'SunOS', 'FreeBSD'])
+    ['CYGWIN', 'MSYS', 'Linux', 'Darwin', 'SunOS', 'FreeBSD', 'NetBSD'])
 
 
 # Py2/3 compat. Empty conditional to avoid coverage
