$NetBSD: patch-lib_bup_hashsplit.py,v 1.1 2015/07/03 13:07:49 thomasklausner Exp $

--- lib/bup/hashsplit.py.orig	2015-07-03 06:59:44.000000000 +0000
+++ lib/bup/hashsplit.py
@@ -1,13 +1,9 @@
 import math, os
 
-from bup import _helpers
+from bup import _helpers, helpers
+from bup.helpers import sc_page_size
 
-try:
-    _fmincore = _helpers.fmincore
-except AttributeError, e:
-    _fmincore = None
-
-_page_size = os.sysconf("SC_PAGE_SIZE")
+_fmincore = getattr(helpers, 'fmincore', None)
 
 BLOB_MAX = 8192*4   # 8192 is the "typical" blob size for bupsplit
 BLOB_READ_SIZE = 1024*1024
@@ -52,7 +48,9 @@ def _fadvise_pages_done(fd, first_page, 
     assert(first_page >= 0)
     assert(count >= 0)
     if count > 0:
-        _helpers.fadvise_done(fd, first_page * _page_size, count * _page_size)
+        _helpers.fadvise_done(fd,
+                              first_page * sc_page_size,
+                              count * sc_page_size)
 
 
 def _nonresident_page_regions(status_bytes, max_region_len=None):
@@ -63,7 +61,7 @@ def _nonresident_page_regions(status_byt
     assert(max_region_len is None or max_region_len > 0)
     start = None
     for i, x in enumerate(status_bytes):
-        in_core = ord(x) & 1
+        in_core = x & helpers.MINCORE_INCORE
         if start is None:
             if not in_core:
                 start = i
@@ -85,7 +83,7 @@ def _uncache_ours_upto(fd, offset, first
     (start_page, count) pair.  The final region must have a start_page
     of None."""
     rstart, rlen = first_region
-    while rstart is not None and (rstart + rlen) * _page_size <= offset:
+    while rstart is not None and (rstart + rlen) * sc_page_size <= offset:
         _fadvise_pages_done(fd, rstart, rlen)
         rstart, rlen = next(remaining_regions, (None, None))
     return (rstart, rlen)
@@ -98,8 +96,8 @@ def readfile_iter(files, progress=None):
         fd = rpr = rstart = rlen = None
         if _fmincore and hasattr(f, 'fileno'):
             fd = f.fileno()
-            max_chunk = max(1, (8 * 1024 * 1024) / _page_size)
-            rpr = _nonresident_page_regions(_helpers.fmincore(fd), max_chunk)
+            max_chunk = max(1, (8 * 1024 * 1024) / sc_page_size)
+            rpr = _nonresident_page_regions(_fmincore(fd), max_chunk)
             rstart, rlen = next(rpr, (None, None))
         while 1:
             if progress:
