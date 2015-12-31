$NetBSD: patch-setup.py,v 1.2 2015/08/10 22:59:31 jonthn Exp $

Remove installation of experimental pynvim

--- setup.py	2015-12-31 23:24:40.000000000 +0100
+++ setup.py	2015-12-31 23:39:23.000000000 +0100
@@ -29,11 +29,6 @@
         except ImportError:
             pass
 
-if sys.version_info < (3, 0):
-    # Experimental GUI only supported for Python 2.
-    extras_require['GUI'] = ['click>=3.0', 'pygobject']
-    entry_points['console_scripts'] = ['pynvim=neovim.ui.cli:main [GUI]']
-
 setup(name='neovim',
       version='0.1.0',
       description='Python client to neovim',
