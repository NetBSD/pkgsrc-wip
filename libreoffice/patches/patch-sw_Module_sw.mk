$NetBSD: patch-sw_Module_sw.mk,v 1.1 2011/09/09 08:21:12 ftigeot Exp $

--- sw/Module_sw.mk.orig	2011-08-30 15:00:33.000000000 +0000
+++ sw/Module_sw.mk
@@ -40,11 +40,6 @@ $(eval $(call gb_Module_add_targets,sw,\
     Package_xml \
 ))
 
-$(eval $(call gb_Module_add_check_targets,sw,\
-    CppunitTest_sw_test_filters \
-    CppunitTest_sw_swdoc_test \
-))
-
 $(eval $(call gb_Module_add_subsequentcheck_targets,sw,\
     JunitTest_sw_complex \
     JunitTest_sw_unoapi \
