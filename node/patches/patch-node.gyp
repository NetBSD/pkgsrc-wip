$NetBSD: patch-node.gyp,v 1.1 2012/07/03 08:49:00 fhajny Exp $

Fix Python binary reference.
--- node.gyp.orig	2012-06-25 14:37:20.000000000 +0000
+++ node.gyp
@@ -281,14 +281,14 @@
           'conditions': [
             [ 'node_use_dtrace=="true" or node_use_etw=="true"', {
               'action': [
-                'python',
+                '@PYTHONBIN@',
                 'tools/js2c.py',
                 '<@(_outputs)',
                 '<@(_inputs)',
               ],
             }, { # No Dtrace
               'action': [
-                'python',
+                '@PYTHONBIN@',
                 'tools/js2c.py',
                 '<@(_outputs)',
                 '<@(_inputs)',
