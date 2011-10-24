$NetBSD: patch-hwpfilter_Module_hwpfilter.mk,v 1.1 2011/10/24 14:34:36 ftigeot Exp $

--- hwpfilter/Module_hwpfilter.mk.orig	2011-10-17 16:49:48.000000000 +0000
+++ hwpfilter/Module_hwpfilter.mk
@@ -32,9 +32,11 @@ $(eval $(call gb_Module_add_targets,hwpf
     Library_hwp \
 ))
 
+ifneq ($(OS),NETBSD)
 $(eval $(call gb_Module_add_check_targets,hwpfilter,\
     CppunitTest_hwpfilter_test_hwpfilter \
     RdbTarget_hwpfilter_test_hwpfilter \
 ))
+endif
 
 # vim: set noet sw=4 ts=4:
