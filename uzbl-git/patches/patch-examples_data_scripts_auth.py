$NetBSD$

Port to Python 3

--- examples/data/scripts/auth.py.orig	2016-07-07 11:51:48.000000000 +0000
+++ examples/data/scripts/auth.py
@@ -3,6 +3,13 @@
 from __future__ import print_function
 
 import os
+try:
+    import pygtkcompat
+except ImportError:
+    pygtkcompat = None
+if not (pygtkcompat is None):
+    pygtkcompat.enable()
+    pygtkcompat.enable_gtk()
 import gtk
 import sys
 import argparse
