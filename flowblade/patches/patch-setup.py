$NetBSD$

Support PKGMANDIR.

--- setup.py.orig	2019-08-26 07:46:04.000000000 +0000
+++ setup.py
@@ -29,7 +29,7 @@ install_data = [('share/applications', [
                 ('share/icons/hicolor/128x128/apps', ['installdata/io.github.jliljebl.Flowblade.png']),
                 ('share/mime/packages',['installdata/io.github.jliljebl.Flowblade.xml']),
                 ('lib/mime/packages',['installdata/flowblade']),
-                ('share/man/man1',['installdata/flowblade.1'])]
+                ('@PKGMANDIR@/man1',['installdata/flowblade.1'])]
 
 flowblade_package_data = ['res/filters/*.xml','res/filters/wipes/*','res/img/*',
                           'res/profiles/*','res/render/renderencoding.xml',
