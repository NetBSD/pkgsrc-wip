$NetBSD: patch-lib_bup_t_thashsplit.py,v 1.1 2015/07/03 13:07:49 thomasklausner Exp $

--- lib/bup/t/thashsplit.py.orig	2015-07-03 06:59:44.000000000 +0000
+++ lib/bup/t/thashsplit.py
@@ -1,10 +1,12 @@
-from bup import hashsplit, _helpers
-from wvtest import *
 from cStringIO import StringIO
 
+from wvtest import *
+
+from bup import hashsplit, _helpers, helpers
+
+
 def nr_regions(x, max_count=None):
-    return list(hashsplit._nonresident_page_regions(''.join(map(chr, x)),
-                                                    max_count))
+    return list(hashsplit._nonresident_page_regions(bytearray(x), max_count))
 
 @wvtest
 def test_nonresident_page_regions():
@@ -47,7 +49,7 @@ def test_uncache_ours_upto():
         history.append((f, ofs, len))
 
     uncache_upto = hashsplit._uncache_ours_upto
-    page_size = os.sysconf("SC_PAGE_SIZE")
+    page_size = helpers.sc_page_size
     orig_pages_done = hashsplit._fadvise_pages_done
     try:
         hashsplit._fadvise_pages_done = mock_fadvise_pages_done
