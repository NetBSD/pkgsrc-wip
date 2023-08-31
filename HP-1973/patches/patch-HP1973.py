$NetBSD$

Add faux pythone #!, so we can REPLACE_PYTHON.

Not yet reported upstream.

--- HP1973.py.orig	2023-07-24 11:27:23.000000000 +0000
+++ HP1973.py
@@ -1,3 +1,5 @@
+#!/usr/bin/env python
+
 # ----------------------------------------------------------------------------------------
 # HP-1973 (A 50th Anniversary Electronic Slide Rule)
 #          a simulator of HP-35, HP-45 and HP-80 calculators
