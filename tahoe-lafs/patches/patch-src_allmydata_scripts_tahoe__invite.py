$NetBSD$

--- src/allmydata/scripts/tahoe_invite.py.orig	2021-02-02 19:56:32.000000000 +0000
+++ src/allmydata/scripts/tahoe_invite.py
@@ -6,7 +6,7 @@ from os.path import join
 from twisted.python import usage
 from twisted.internet import defer, reactor
 
-from wormhole import wormhole
+#from wormhole import wormhole
 
 from allmydata.util import configutil
 from allmydata.util.encodingutil import argv_to_abspath
