$NetBSD: patch-convert-to-python3.sh,v 1.1 2015/08/18 18:36:32 yhardy Exp $

Use the correct converter.

--- convert-to-python3.sh.orig	2015-02-15 08:32:51.000000000 +0000
+++ convert-to-python3.sh
@@ -3,5 +3,5 @@
 
 SOURCES="urlwatch lib/urlwatch/*.py share/urlwatch/examples/hooks.py.example setup.py"
 
-2to3 -w $SOURCES
+2to3-${PYVERSSUFFIX} -w $SOURCES
 
