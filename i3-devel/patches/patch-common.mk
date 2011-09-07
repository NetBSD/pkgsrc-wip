$NetBSD: patch-common.mk,v 1.6 2011/09/07 09:07:45 pallegra Exp $

--- common.mk.orig	2011-08-28 17:48:21.000000000 +0000
+++ common.mk
@@ -68,8 +68,8 @@ LIBS += $(call ldflags_for_lib, xcb-rand
 LIBS += $(call ldflags_for_lib, xcb, xcb)
 LIBS += $(call ldflags_for_lib, xcursor, Xcursor)
 LIBS += $(call ldflags_for_lib, x11, X11)
-LIBS += $(call ldflags_for_lib, yajl, yajl)
-LIBS += $(call ldflags_for_lib, libev, ev)
+LIBS += -lyajl
+LIBS += -lev
 
 # Please test if -Wl,--as-needed works on your platform and send me a patch.
 # it is known not to work on Darwin (Mac OS X)
