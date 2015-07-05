$NetBSD: patch-lib_bup_hashsplit.py,v 1.2 2015/07/05 20:46:45 thomasklausner Exp $

--- lib/bup/hashsplit.py.orig	2015-07-05 20:33:32.000000000 +0000
+++ lib/bup/hashsplit.py
@@ -1,12 +1,9 @@
 import math, os
 
-from bup import _helpers
+from bup import _helpers, helpers
 from bup.helpers import sc_page_size
 
-try:
-    _fmincore = _helpers.fmincore
-except AttributeError, e:
-    _fmincore = None
+_fmincore = getattr(helpers, 'fmincore', None)
 
 BLOB_MAX = 8192*4   # 8192 is the "typical" blob size for bupsplit
 BLOB_READ_SIZE = 1024*1024
@@ -64,7 +61,7 @@ def _nonresident_page_regions(status_byt
     assert(max_region_len is None or max_region_len > 0)
     start = None
     for i, x in enumerate(status_bytes):
-        in_core = ord(x) & 1
+        in_core = x & helpers.MINCORE_INCORE
         if start is None:
             if not in_core:
                 start = i
@@ -100,7 +97,7 @@ def readfile_iter(files, progress=None):
         if _fmincore and hasattr(f, 'fileno'):
             fd = f.fileno()
             max_chunk = max(1, (8 * 1024 * 1024) / sc_page_size)
-            rpr = _nonresident_page_regions(_helpers.fmincore(fd), max_chunk)
+            rpr = _nonresident_page_regions(_fmincore(fd), max_chunk)
             rstart, rlen = next(rpr, (None, None))
         while 1:
             if progress:
