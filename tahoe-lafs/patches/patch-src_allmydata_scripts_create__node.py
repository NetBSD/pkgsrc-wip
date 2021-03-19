$NetBSD$

--- src/allmydata/scripts/create_node.py.orig	2021-02-02 19:56:32.000000000 +0000
+++ src/allmydata/scripts/create_node.py
@@ -10,7 +10,7 @@ from allmydata.scripts.default_nodedir i
 from allmydata.util.assertutil import precondition
 from allmydata.util.encodingutil import listdir_unicode, argv_to_unicode, quote_local_unicode_path, get_io_encoding
 from allmydata.util import fileutil, i2p_provider, iputil, tor_provider
-from wormhole import wormhole
+#from wormhole import wormhole
 
 
 dummy_tac = """
