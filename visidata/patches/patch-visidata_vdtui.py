$NetBSD$

- Make curses(3) mouse support optional

--- visidata/vdtui.py.orig	2019-01-13 00:28:25.000000000 +0000
+++ visidata/vdtui.py
@@ -2817,9 +2817,13 @@ colors = ColorMaker()
 def setupcolors(stdscr, f, *args):
     curses.raw()    # get control keys instead of signals
     curses.meta(1)  # allow "8-bit chars"
-    curses.mousemask(-1) # even more than curses.ALL_MOUSE_EVENTS
-    curses.mouseinterval(0) # very snappy but does not allow for [multi]click
-    curses.mouseEvents = {}
+
+    try:
+        curses.mousemask(-1) # even more than curses.ALL_MOUSE_EVENTS
+        curses.mouseinterval(0) # very snappy but does not allow for [multi]click
+        curses.mouseEvents = {}
+    except:
+        pass
 
     for k in dir(curses):
         if k.startswith('BUTTON') or k == 'REPORT_MOUSE_POSITION':
