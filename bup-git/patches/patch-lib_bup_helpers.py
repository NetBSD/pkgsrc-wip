$NetBSD: patch-lib_bup_helpers.py,v 1.3 2015/07/03 13:07:49 thomasklausner Exp $

--- lib/bup/helpers.py.orig	2015-07-03 06:59:44.000000000 +0000
+++ lib/bup/helpers.py
@@ -9,6 +9,7 @@ import hashlib, heapq, math, operator, t
 
 from bup import _helpers
 
+sc_page_size = os.sysconf('SC_PAGE_SIZE')
 sc_arg_max = os.sysconf('SC_ARG_MAX')
 
 # This function should really be in helpers, not in bup.options.  But we
@@ -714,6 +715,42 @@ def mmap_readwrite_private(f, sz = 0, cl
                     close)
 
 
+_mincore = getattr(_helpers, 'mincore', None)
+if _mincore:
+    # ./configure ensures that we're on Linux if MINCORE_INCORE isn't defined.
+    MINCORE_INCORE = getattr(_helpers, 'MINCORE_INCORE', 1)
+
+    _fmincore_chunk_size = None
+    def _set_fmincore_chunk_size():
+        global _fmincore_chunk_size
+        pref_chunk_size = 64 * 1024 * 1024
+        chunk_size = sc_page_size
+        if (sc_page_size < pref_chunk_size):
+            chunk_size = sc_page_size * (pref_chunk_size / sc_page_size)
+        _fmincore_chunk_size = chunk_size
+
+    def fmincore(fd):
+        """Return the mincore() data for fd as a bytearray whose values can be
+        tested via MINCORE_INCORE"""
+        st = os.fstat(fd)
+        if (st.st_size == 0):
+            return bytearray(0)
+        if not _fmincore_chunk_size:
+            _set_fmincore_chunk_size()
+        pages_per_chunk = _fmincore_chunk_size / sc_page_size;
+        page_count = (st.st_size + sc_page_size - 1) / sc_page_size;
+        chunk_count = page_count / _fmincore_chunk_size
+        if chunk_count < 1:
+            chunk_count = 1
+        result = bytearray(page_count)
+        for ci in xrange(chunk_count):
+            pos = _fmincore_chunk_size * ci;
+            msize = min(_fmincore_chunk_size, st.st_size - pos)
+            m = mmap.mmap(fd, msize, mmap.MAP_PRIVATE, 0, 0, pos)
+            _mincore(m, msize, 0, result, ci * pages_per_chunk);
+        return result
+
+
 def parse_timestamp(epoch_str):
     """Return the number of nanoseconds since the epoch that are described
 by epoch_str (100ms, 100ns, ...); when epoch_str cannot be parsed,
