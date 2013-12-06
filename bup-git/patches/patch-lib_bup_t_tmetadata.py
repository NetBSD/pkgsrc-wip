$NetBSD: patch-lib_bup_t_tmetadata.py,v 1.1 2013/12/06 00:24:44 thomasklausner Exp $

Fix test failure as non-root on NetBSD.
Sent upstream.

--- lib/bup/t/tmetadata.py.orig	2013-12-06 00:00:37.000000000 +0000
+++ lib/bup/t/tmetadata.py
@@ -172,6 +172,7 @@ def test_from_path_error():
             WVPASS(errmsg.startswith('read Linux attr'))
             clear_errors()
     finally:
+        subprocess.call(['chmod', '-R', 'u+rwX', tmpdir])
         subprocess.call(['rm', '-rf', tmpdir])
 
 
