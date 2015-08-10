$NetBSD: patch-setup.py,v 1.2 2015/08/10 22:59:31 jonthn Exp $

Remove installation of experimental pynvim

--- setup.py.orig	2015-08-06 23:39:20.000000000 +0200
+++ setup.py	2015-08-11 00:28:58.000000000 +0200
@@ -29,11 +29,6 @@
         except ImportError:
             pass
 
-if sys.version_info < (3, 0):
-    # Experimental GUI only supported for Python 2.
-    extras_require['GUI'] = ['click>=3.0', 'pygobject']
-    entry_points['console_scripts'] = ['pynvim=neovim.ui.cli:main [GUI]']
-
 setup(name='neovim',
       version='0.0.38',
       description='Python client to neovim',
