$NetBSD: patch-coreconf_OpenBSD.mk,v 1.2 2014/10/05 20:12:38 thomasklausner Exp $

PLIST unification (see nspr)?

--- coreconf/OpenBSD.mk.orig	2016-04-25 00:47:19.000000000 +0000
+++ coreconf/OpenBSD.mk
@@ -24,7 +24,7 @@ OS_LIBS			+= -pthread
 DSO_LDOPTS		+= -pthread
 endif
 
-DLL_SUFFIX		= so.1.0
+DLL_SUFFIX		= so
 
 OS_CFLAGS		= $(DSO_CFLAGS) $(OS_REL_CFLAGS) -Wall -Wno-switch -pipe -DOPENBSD
 
