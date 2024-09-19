$NetBSD: patch-setup.py,v 1.1 2012/10/02 00:10:26 jihbed Exp $

--- setup.py.orig	2012-10-01 23:14:43.000000000 +0100
+++ setup.py	2012-10-01 23:20:38.000000000 +0100
@@ -29,9 +29,7 @@
       long_description='Python interface to Loggly.',
       author = 'Mike Babineau',
       author_email = 'michael.babineau@gmail.com',
-      scripts = ['scripts/loggly-create-input', 'scripts/loggly-delete-input',
-                 'scripts/loggly-add-device', 'scripts/loggly-remove-device',
-		 'scripts/loggly-describe-input'],
+      scripts = ['scripts/loggly-create-input'+sys.version[0:3], 'scripts/loggly-delete-input'+sys.version[0:3],'scripts/loggly-add-device'+sys.version[0:3], 'scripts/loggly-remove-device'+sys.version[0:3],'scripts/loggly-describe-input'+sys.version[0:3]],
       install_requires = ['simplejson'],
       url = 'http://github.com/EA2D/loggly-python',
       packages = ['loggly'],
