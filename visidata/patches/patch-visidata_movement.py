$NetBSD$

Conditionalize mousemask.

Not all curses support mouse, e.g. NetBSD curses(3).

Related to upstream #2851.

Shared upstream via:

 <https://github.com/saulpw/visidata/pull/2913>

--- visidata/movement.py.orig	2025-12-15 11:59:00.204848702 +0000
+++ visidata/movement.py
@@ -189,8 +189,8 @@ BaseSheet.addCommand('g^^', 'jump-first'
 
 BaseSheet.addCommand('BUTTON1_RELEASED', 'no-op', 'pass', 'do nothing')
 
-BaseSheet.addCommand(None, 'mouse-enable', 'mm, _ = curses.mousemask(-1); status("mouse "+("ON" if mm else "OFF"))', 'enable mouse events')
-BaseSheet.addCommand(None, 'mouse-disable', 'mm, _ = curses.mousemask(0); status("mouse "+("ON" if mm else "OFF"))', 'disable mouse events')
+BaseSheet.addCommand(None, 'mouse-enable', 'mm, _ = curses.mousemask(-1) if hasattr(curses, "mousemask") else None; status("mouse "+("ON" if mm else "OFF"))', 'enable mouse events')
+BaseSheet.addCommand(None, 'mouse-disable', 'mm, _ = curses.mousemask(0) if hasattr(curses, "mousemask") else None; status("mouse "+("ON" if mm else "OFF"))', 'disable mouse events')
 
 
 vd.addGlobals({'rotateRange': rotateRange})
