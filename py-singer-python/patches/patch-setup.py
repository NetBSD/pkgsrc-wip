$NetBSD$

Relax too strict version requirements.

--- setup.py.orig	2024-03-19 17:58:03.000000000 +0000
+++ setup.py
@@ -11,11 +11,11 @@ setup(name="singer-python",
       url="http://singer.io",
       install_requires=[
           'pytz>=2018.4',
-          'jsonschema>=2.6.0,==2.*',
-          'simplejson>=3.13.2,==3.*',
-          'python-dateutil>=2.7.3,==2.*',
-          'backoff>=2.2.1,==2.*',
-          'ciso8601>=2.3.1,==2.*',
+          'jsonschema>=2.6.0',
+          'simplejson>=3.13.2',
+          'python-dateutil>=2.7.3',
+          'backoff>=2.2.1',
+          'ciso8601>=2.3.1',
       ],
       extras_require={
           'dev': [
