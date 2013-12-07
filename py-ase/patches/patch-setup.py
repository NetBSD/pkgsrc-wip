$NetBSD: patch-setup.py,v 1.1 2013/12/07 16:12:38 jihbed Exp $

--- setup.py.orig	2013-12-07 16:44:39.000000000 +0100
+++ setup.py	2013-12-07 16:51:19.000000000 +0100
@@ -142,8 +142,8 @@
 else:
     version = version_base
 
-scripts = ['tools/ase-gui', 'tools/ase-db', 'tools/ase-info',
-           'tools/ase-build', 'tools/ase-run']
+scripts = ['tools/ase-gui'+sys.version[0:3], 'tools/ase-db'+sys.version[0:3], 'tools/ase-info'+sys.version[0:3],
+           'tools/ase-build'+sys.version[0:3], 'tools/ase-run'+sys.version[0:3]]
 # provide bat executables in the tarball and always for Win
 if 'sdist' in sys.argv or os.name in ['ce', 'nt']:
     for s in scripts[:]:
