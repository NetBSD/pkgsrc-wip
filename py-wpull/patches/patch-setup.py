$NetBSD$

dnspython3 has been superseded by the regular dnspython

--- setup.py.orig	2017-10-27 15:51:42.000000000 +0000
+++ setup.py
@@ -100,7 +100,7 @@ setup_kwargs = dict(
 # See also requirements.txt
 setup_kwargs['install_requires'] = [
     'chardet',
-    'dnspython3',
+    'dnspython',
     'html5lib',
     'namedlist',
     'sqlalchemy',
