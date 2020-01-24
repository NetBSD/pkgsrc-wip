$NetBSD$

Compatibility with Python 3.7 and 3.8

--- zipline/assets/assets.py.orig	2017-12-11 17:11:41.000000000 +0000
+++ zipline/assets/assets.py
@@ -605,13 +605,13 @@ class AssetFinder(object):
         symbols = {
             row.sid: {c: row[c] for c in symbol_columns}
             for row in concat(
-                self.engine.execute(
+                (self.engine.execute(
                     self._select_most_recent_symbols_chunk(sid_group),
                 ).fetchall()
                 for sid_group in partition_all(
                     SQLITE_MAX_VARIABLE_NUMBER,
                     sids
-                ),
+                )),
             )
         }
 
