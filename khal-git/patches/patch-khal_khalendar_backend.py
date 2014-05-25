$NetBSD: patch-khal_khalendar_backend.py,v 1.3 2014/05/25 15:57:26 thomasklausner Exp $

Python-3.x compatibility.

--- khal/khalendar/backend.py.orig	2014-05-25 12:16:08.000000000 +0000
+++ khal/khalendar/backend.py
@@ -128,7 +128,7 @@ class SQLiteDb(object):
         if not path.isdir(dbdir):
             try:
                 logger.debug('trying to create the directory for the db')
-                makedirs(dbdir, mode=0770)
+                makedirs(dbdir, mode=0o770)
                 logger.debug('success')
             except OSError as error:
                 logger.fatal('failed to create {0}: {1}'.format(dbdir, error))
