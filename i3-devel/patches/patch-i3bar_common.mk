$NetBSD: patch-i3bar_common.mk,v 1.1 2011/08/01 13:03:36 pallegra Exp $

--- i3bar/common.mk.orig	2011-08-01 12:44:19.000000000 +0000
+++ i3bar/common.mk
@@ -2,7 +2,9 @@ INSTALL=install
 ifndef DEBUG
 DEBUG=1
 endif
+ifndef PREFIX
 PREFIX=/usr
+endif
 
 # The escaping is absurd, but we need to escape for shell, sed, make, define
 GIT_VERSION:="0.6-57-gdae847a (2011-07-19, branch \\\"tree\\\")"
@@ -13,16 +15,16 @@ CFLAGS += -idirafter yajl-fallback
 
 CFLAGS += -Wall
 CFLAGS += -pipe
-CFLAGS += -g
+#CFLAGS += -g
 
 CPPFLAGS += -DI3BAR_VERSION=\"${GIT_VERSION}\"
-CPPFLAGS += -Iinclude
+CPPFLAGS += -Iinclude -I../include
 
 LDFLAGS += -lev
 LDFLAGS += -lyajl
 LDFLAGS += -lxcb
 LDFLAGS += -lX11
-LDFLAGS += -L/usr/local/lib
+#LDFLAGS += -L/usr/local/lib
 
 ifeq ($(DEBUG),1)
 CFLAGS += -g3
