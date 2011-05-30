$NetBSD: patch-common.mk,v 1.2 2011/05/30 20:22:51 pallegra Exp $

--- common.mk.orig	2011-05-28 20:13:18.000000000 +0000
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
 # The escaping is absurd, but we need to escape for shell, sed, make, define
 GIT_VERSION:="tree-pr3 (2011-05-28, branch \\\"tree\\\")"
@@ -62,8 +62,8 @@ LDFLAGS += $(call ldflags_for_lib, xcb-r
 LDFLAGS += $(call ldflags_for_lib, xcb, xcb)
 LDFLAGS += $(call ldflags_for_lib, xcursor, Xcursor)
 LDFLAGS += $(call ldflags_for_lib, x11, X11)
-LDFLAGS += $(call ldflags_for_lib, yajl, yajl)
-LDFLAGS += $(call ldflags_for_lib, libev, ev)
+LDFLAGS += -lyajl
+LDFLAGS += -lev
 
 ifeq ($(UNAME),NetBSD)
 # We need -idirafter instead of -I to prefer the system’s iconv over GNU libiconv
