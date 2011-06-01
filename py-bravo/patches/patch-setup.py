$NetBSD: patch-setup.py,v 1.1.1.1 2011/06/01 03:51:46 schnoebe Exp $

# remove unneeded attempt to list twisted plugins?

--- setup.py.orig	2011-05-08 16:36:35.000000000 +0000
+++ setup.py
@@ -22,9 +22,3 @@ setup(
     license="MIT/X11",
     url="http://github.com/MostAwesomeDude/bravo",
 )
-
-try:
-    from twisted.plugin import getPlugins, IPlugin
-    list(getPlugins(IPlugin))
-except:
-    pass
