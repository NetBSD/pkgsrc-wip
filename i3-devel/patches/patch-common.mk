$NetBSD: patch-common.mk,v 1.3 2011/07/21 18:39:17 pallegra Exp $

--- common.mk.orig	2011-07-15 17:22:09.000000000 +0000
+++ common.mk
@@ -1,12 +1,12 @@
 UNAME=$(shell uname)
-DEBUG=1
+DEBUG?=1
 COVERAGE=0
 INSTALL=install
-PREFIX=/usr
+PREFIX?=/usr
 ifeq ($(PREFIX),/usr)
-SYSCONFDIR=/etc
+SYSCONFDIR?=/etc
 else
-SYSCONFDIR=$(PREFIX)/etc
+SYSCONFDIR?=$(PREFIX)/etc
 endif
 TERM_EMU=xterm
 # The escaping is absurd, but we need to escape for shell, sed, make, define
@@ -64,8 +64,8 @@ LIBS += $(call ldflags_for_lib, xcb-rand
 LIBS += $(call ldflags_for_lib, xcb, xcb)
 LIBS += $(call ldflags_for_lib, xcursor, Xcursor)
 LIBS += $(call ldflags_for_lib, x11, X11)
-LIBS += $(call ldflags_for_lib, yajl, yajl)
-LIBS += $(call ldflags_for_lib, libev, ev)
+LIBS += -lyajl
+LIBS += -lev
 
 ifeq ($(UNAME),NetBSD)
 # We need -idirafter instead of -I to prefer the system’s iconv over GNU libiconv
