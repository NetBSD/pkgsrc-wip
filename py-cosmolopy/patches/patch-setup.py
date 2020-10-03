$NetBSD$

--- setup.py.orig	2019-11-12 05:55:12.000000000 +0000
+++ setup.py
@@ -47,9 +47,6 @@ for name in ext_names:
                              path.join(eh_dir, '%s.c' % (name))])
     ext_mods.append(mod)
 
-# Get the requirements list
-with open(path.join(dirpath, 'requirements.txt'), 'r') as f:
-    requirements = f.read().splitlines()
 
 # Read the __version__.py file
 with open(path.join(dirpath, 'cosmolopy/__version__.py'), 'r') as f:
@@ -62,7 +59,6 @@ setup(
     name = "cosmolopy",
     version = version,
     packages = find_packages(),
-    install_requires = requirements,
 
     ext_modules = ext_mods,
 
