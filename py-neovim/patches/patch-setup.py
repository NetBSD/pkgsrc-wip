$NetBSD: patch-setup.py,v 1.1 2015/06/23 21:41:02 jonthn Exp $

Remove installation of experimental pynvim

--- setup.py.orig	2015-06-23 21:22:56.000000000 +0000
+++ setup.py
@@ -29,11 +29,6 @@ if platform.python_implementation() != '
         except ImportError:
             pass
 
-if sys.version_info < (3, 0):
-    # Experimental GUI only supported for Python 2.
-    extras_require['GUI'] = ['click>=3.0', 'pygobject']
-    entry_points['console_scripts'] = ['pynvim=neovim.ui.cli:main [GUI]']
-
 setup(name='neovim',
       version='0.0.36',
       description='Python client to neovim',
