$NetBSD$

Conditionalize mousemask.

Not all curses support mouse, e.g. NetBSD curses(3).

Related to upstream #2851.

Shared upstream via:

 <https://github.com/saulpw/visidata/pull/2913>

--- visidata/_input.py.orig	2025-12-15 11:55:26.043085221 +0000
+++ visidata/_input.py
@@ -60,16 +60,18 @@ def acceptThenFunc(*longnames):
 class EnableCursor:
     def __enter__(self):
         with suppress(curses.error):
-            curses.mousemask(0)
+            if hasattr(curses, 'mousemask'):
+                curses.mousemask(0)
             curses.curs_set(1)
 
     def __exit__(self, exc_type, exc_val, tb):
         with suppress(curses.error):
             curses.curs_set(0)
-            if vd.options.mouse_interval:
-                curses.mousemask(curses.MOUSE_ALL if hasattr(curses, "MOUSE_ALL") else 0xffffffff)
-            else:
-                curses.mousemask(0)
+            if hasattr(curses, 'mousemask'):
+                if vd.options.mouse_interval:
+                    curses.mousemask(curses.MOUSE_ALL if hasattr(curses, "MOUSE_ALL") else 0xffffffff)
+                else:
+                    curses.mousemask(0)
 
 
 def until_get_wch(scr):
