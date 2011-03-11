$NetBSD: patch-common.mk,v 1.1 2011/03/11 12:16:10 pallegra Exp $

--- common.mk.orig	2011-03-07 19:24:40.000000000 +0000
+++ common.mk
@@ -1,11 +1,11 @@
 UNAME=$(shell uname)
-DEBUG=1
+DEBUG?=1
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
 GIT_VERSION:="tree-pr2 (2011-03-07, branch \\\"tree\\\")"
@@ -52,8 +52,8 @@ LDFLAGS += $(call ldflags_for_lib, xcb-r
 LDFLAGS += $(call ldflags_for_lib, xcb, xcb)
 LDFLAGS += $(call ldflags_for_lib, xcursor, Xcursor)
 LDFLAGS += $(call ldflags_for_lib, x11, X11)
-LDFLAGS += $(call ldflags_for_lib, yajl, yajl)
-LDFLAGS += $(call ldflags_for_lib, libev, ev)
+LDFLAGS += -lyajl
+LDFLAGS += -lev
 LDFLAGS += -L/usr/local/lib -L/usr/pkg/lib
 
 ifeq ($(UNAME),NetBSD)
