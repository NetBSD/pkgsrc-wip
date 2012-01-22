$NetBSD: patch-sw_Module_sw.mk,v 1.3 2012/01/22 08:47:00 ftigeot Exp $

--- sw/Module_sw.mk.orig	2012-01-09 22:08:58.000000000 +0000
+++ sw/Module_sw.mk
@@ -40,11 +40,13 @@ $(eval $(call gb_Module_add_targets,sw,\
     Package_xml \
 ))
 
+ifneq ($(OS),NETBSD)
 $(eval $(call gb_Module_add_check_targets,sw,\
     CppunitTest_sw_filters_test \
     CppunitTest_sw_macros_test \
     CppunitTest_sw_swdoc_test \
 ))
+endif
 
 $(eval $(call gb_Module_add_subsequentcheck_targets,sw,\
     JunitTest_sw_complex \
