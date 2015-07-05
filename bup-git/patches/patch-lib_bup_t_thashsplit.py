$NetBSD: patch-lib_bup_t_thashsplit.py,v 1.2 2015/07/05 20:46:45 thomasklausner Exp $

--- lib/bup/t/thashsplit.py.orig	2015-07-05 20:33:32.000000000 +0000
+++ lib/bup/t/thashsplit.py
@@ -6,8 +6,7 @@ from bup import hashsplit, _helpers, hel
 
 
 def nr_regions(x, max_count=None):
-    return list(hashsplit._nonresident_page_regions(''.join(map(chr, x)),
-                                                    max_count))
+    return list(hashsplit._nonresident_page_regions(bytearray(x), max_count))
 
 @wvtest
 def test_nonresident_page_regions():
