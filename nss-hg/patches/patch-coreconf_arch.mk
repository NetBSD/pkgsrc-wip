$NetBSD: patch-coreconf_arch.mk,v 1.2 2014/10/05 20:12:38 thomasklausner Exp $

Support DragonFly

--- coreconf/arch.mk.orig	2014-09-28 13:54:02.000000000 +0000
+++ coreconf/arch.mk
@@ -113,7 +113,7 @@ endif
 # IRIX 6.5-ALPHA-1289139620.
 #
 
-ifeq (,$(filter-out Linux FreeBSD IRIX,$(OS_ARCH)))
+ifeq (,$(filter-out Linux DragonFly FreeBSD IRIX,$(OS_ARCH)))
     OS_RELEASE := $(shell echo $(OS_RELEASE) | sed 's/-.*//')
 endif
 
