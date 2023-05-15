$NetBSD$

Allow to override build date with SOURCE_DATE_EPOCH
in order to make build reproducible.
For more information see https://reproducible-builds.org, and
https://reproducible-builds.org/specs/source-date-epoch/
for the definition of this variable.

--- python/mozbuild/mozbuild/action/langpack_manifest.py.orig	2023-05-13 02:22:29.641354307 +0200
+++ python/mozbuild/mozbuild/action/langpack_manifest.py	2023-05-13 02:24:00.832424983 +0200
@@ -16,6 +16,7 @@
 import json
 import io
 import datetime
+import time
 import requests
 import mozversioncontrol
 import mozpack.path as mozpath
@@ -105,7 +106,7 @@
         dt = get_dt_from_hg(path)
 
     if dt is None:
-        dt = datetime.datetime.utcnow()
+        dt = datetime.datetime.utcfromtimestamp(int(os.environ.get('SOURCE_DATE_EPOCH', time.time())))
 
     dt = dt.replace(microsecond=0)
     return dt.strftime("%Y%m%d%H%M%S")
