$NetBSD: patch-common.mk,v 1.1 2011/03/11 12:17:34 pallegra Exp $

--- common.mk.orig	2010-12-23 15:39:53.000000000 +0000
+++ common.mk
@@ -1,6 +1,6 @@
 INSTALL=install
-DEBUG=1
-PREFIX=/usr
+DEBUG?=1
+PREFIX?=/usr
 
 # The escaping is absurd, but we need to escape for shell, sed, make, define
 GIT_VERSION:="$(shell git describe --tags --always) ($(shell git log --pretty=format:%cd --date=short -n1), branch $(shell [ -f .git/HEAD ] && sed 's/ref: refs\/heads\/\(.*\)/\\\\\\"\1\\\\\\"/g' .git/HEAD || echo 'unknown'))"
@@ -9,7 +9,7 @@ CFLAGS += -Wall
 CFLAGS += -pipe
 CFLAGS += -Iinclude
 CFLAGS += -g
-CFLAGS += -DI3BAR_VERSION=\"${GIT_VERSION}\"
+CFLAGS += -DI3BAR_VERSION=\"${I3BAR_VERSION}\"
 
 LDFLAGS += -lev
 LDFLAGS += -lyajl
