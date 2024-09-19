$NetBSD: patch-setup.py,v 1.1 2013/12/07 16:17:32 jihbed Exp $

--- setup.py.orig	2013-12-07 16:15:22.000000000 +0100
+++ setup.py	2013-12-07 16:22:09.000000000 +0100
@@ -220,8 +220,8 @@
     extensions.append(hdf5_extension)
 
 scripts = [join('tools', script)
-           for script in ('gpaw', 'gpaw-test', 'gpaw-setup', 'gpaw-basis',
-                          'gpaw-mpisim')]
+           for script in ('gpaw'+sys.version[0:3], 'gpaw-setup'+sys.version[0:3], 'gpaw-basis'+sys.version[0:3],
+                          'gpaw-mpisim'+sys.version[0:3])]
 
 write_configuration(define_macros, include_dirs, libraries, library_dirs,
                     extra_link_args, extra_compile_args,
