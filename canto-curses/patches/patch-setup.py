$NetBSD$

Fix manual page directory.

--- setup.py.orig	2016-06-01 18:43:46.000000000 +0000
+++ setup.py
@@ -49,7 +49,7 @@ setup(name='Canto-curses',
               library_dirs = ["/usr/local/lib", "/opt/local/lib"],
               include_dirs = ["/usr/local/include", "/opt/local/include"])],
       scripts=['bin/canto-curses'],
-      data_files = [("share/man/man1/", ["man/canto-curses.1"]),
+      data_files = [(os.getenv("PKGMANDIR")+"/man1/", ["man/canto-curses.1"]),
                     ("lib/canto/plugins/", glob.glob('plugins/*.py'))],
       cmdclass = {  'install_data' : canto_curses_install_data,
                     'build_py' : canto_curses_build_py},
