$NetBSD: patch-sw_Module_sw.mk,v 1.2 2011/10/24 14:17:46 ftigeot Exp $

--- sw/Module_sw.mk.orig	2011-10-17 16:49:48.000000000 +0000
+++ sw/Module_sw.mk
@@ -40,12 +40,14 @@ $(eval $(call gb_Module_add_targets,sw,\
     Package_xml \
 ))
 
+ifneq ($(OS),NETBSD)
 $(eval $(call gb_Module_add_check_targets,sw,\
     CppunitTest_sw_filters_test \
     CppunitTest_sw_swdoc_test \
     RdbTarget_sw_filters_test \
     RdbTarget_sw_swdoc_test \
 ))
+endif
 
 $(eval $(call gb_Module_add_subsequentcheck_targets,sw,\
     JunitTest_sw_complex \
