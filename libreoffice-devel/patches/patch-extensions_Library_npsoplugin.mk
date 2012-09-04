$NetBSD: patch-extensions_Library_npsoplugin.mk,v 1.1 2012/09/04 16:52:14 ftigeot Exp $

libdl doesn't exist on NetBSD.

--- extensions/Library_npsoplugin.mk.orig	2012-08-21 17:01:59.000000000 +0000
+++ extensions/Library_npsoplugin.mk
@@ -39,9 +39,11 @@ $(eval $(call gb_Library_use_static_libr
 
 ifeq ($(GUI),UNX)
 
+ifneq ($(OS),NETBSD)
 $(eval $(call gb_Library_add_libs,npsoplugin,\
 	-ldl \
 ))
+endif
 
 $(eval $(call gb_Library_use_external,npsoplugin,gtk))
 
