$NetBSD: patch-khal_khalendar_backend.py,v 1.2 2014/05/20 14:06:47 thomasklausner Exp $

Python-3.x compatibility.

--- khal/khalendar/backend.py.orig	2014-05-11 08:49:28.000000000 +0000
+++ khal/khalendar/backend.py
@@ -126,7 +126,7 @@ class SQLiteDb(object):
         if not path.isdir(dbdir):
             try:
                 logging.debug('trying to create the directory for the db')
-                makedirs(dbdir, mode=0770)
+                makedirs(dbdir, mode=0o770)
                 logging.debug('success')
             except OSError as error:
                 logging.fatal('failed to create {0}: {1}'.format(dbdir, error))
