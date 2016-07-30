$NetBSD$

Fix manual page directory.

--- setup.py.orig	2016-06-01 18:57:35.000000000 +0000
+++ setup.py
@@ -48,7 +48,7 @@ setup(name='Canto',
       download_url='http://codezen.org/static/canto-daemon-' + string_version + '.tar.gz',
       packages=['canto_next'],
       scripts=['bin/canto-daemon','bin/canto-remote'],
-      data_files = [("share/man/man1/", ["man/canto-daemon.1", "man/canto-remote.1"]),
+      data_files = [(os.getenv("PKGMANDIR")+"/man1/", ["man/canto-daemon.1", "man/canto-remote.1"]),
                     ("lib/systemd/user", ["systemd/user/canto-daemon.service"]),
                     ("lib/canto/plugins", glob.glob("plugins/*.py"))],
       cmdclass = {  'install_data' : canto_next_install_data,
