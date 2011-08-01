$NetBSD: patch-common.mk,v 1.4 2011/08/01 13:03:36 pallegra Exp $

--- common.mk.orig	2011-07-31 21:53:54.000000000 +0000
+++ common.mk
@@ -68,8 +68,8 @@ LIBS += $(call ldflags_for_lib, xcb-rand
 LIBS += $(call ldflags_for_lib, xcb, xcb)
 LIBS += $(call ldflags_for_lib, xcursor, Xcursor)
 LIBS += $(call ldflags_for_lib, x11, X11)
-LIBS += $(call ldflags_for_lib, yajl, yajl)
-LIBS += $(call ldflags_for_lib, libev, ev)
+LIBS += -lyajl
+LIBS += -lev
 
 ifeq ($(UNAME),NetBSD)
 # We need -idirafter instead of -I to prefer the system’s iconv over GNU libiconv
