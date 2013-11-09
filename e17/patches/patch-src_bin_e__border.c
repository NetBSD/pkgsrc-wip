$NetBSD: patch-src_bin_e__border.c,v 1.1 2013/11/09 14:56:29 roelants Exp $

Try to fix a crash that occurs when the pointer is being warped to a
window that is being destroyed. See https://phab.enlightenment.org/T322

--- src/bin/e_border.c.orig
+++ src/bin/e_border.c
@@ -5006,6 +5006,19 @@
 
         focused = NULL;
      }
+
+   if (warp_timer_border == bd)
+     {
+        warp_to = 0;
+        warp_timer_border = NULL;
+        if (warp_timer)
+          {
+             ecore_timer_del(warp_timer);
+             warp_timer = NULL;
+             e_border_focus_lock_set(EINA_FALSE);
+          }
+     }
+
    E_FREE_LIST(bd->handlers, ecore_event_handler_del);
    if (bd->remember)
      {
@@ -5114,6 +5127,7 @@
    E_Event_Border_Remove *ev;
    E_Border *child;
 
+   bd->take_focus = bd->want_focus = 0;
    if (bd == focused)
      {
         focused = NULL;
@@ -5124,6 +5138,18 @@
 
    focus_next = eina_list_remove(focus_next, bd);
 
+   if (warp_timer_border == bd)
+     {
+        warp_to = 0;
+        warp_timer_border = NULL;
+        if (warp_timer)
+          {
+             ecore_timer_del(warp_timer);
+             warp_timer = NULL;
+             e_border_focus_lock_set(EINA_FALSE);
+          }
+     }
+
    if (bd->fullscreen) bd->desk->fullscreen_borders--;
 
    if ((drag_border) && (drag_border->data == bd))
