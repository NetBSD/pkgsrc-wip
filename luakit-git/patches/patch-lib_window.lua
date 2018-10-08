$NetBSD$

Do not destroy() the view.

When just one tab is present it leads to an high CPU usage and luakit completely
stuck (although start luakit via `--log=DEBUG' option shows that it responds to
events).

Reported uptsream via:

 <https://github.com/luakit/luakit/pull/726>

--- lib/window.lua.orig	2018-09-22 23:42:41.000000000 +0000
+++ lib/window.lua
@@ -481,7 +481,6 @@ _M.methods = {
         view = view or w.view
         w:emit_signal("close-tab", view)
         w:detach_tab(view, blank_last)
-        view:destroy()
     end,
 
     attach_tab = function (w, view, switch, order)
