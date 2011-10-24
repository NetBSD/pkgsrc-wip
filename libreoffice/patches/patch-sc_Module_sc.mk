$NetBSD: patch-sc_Module_sc.mk,v 1.2 2011/10/24 14:17:46 ftigeot Exp $

--- sc/Module_sc.mk.orig	2011-10-17 16:49:48.000000000 +0000
+++ sc/Module_sc.mk
@@ -34,12 +34,4 @@ $(eval $(call gb_Module_add_targets,sc,\
 	Package_xml \
 ))
 
-$(eval $(call gb_Module_add_check_targets,sc,\
-	CppunitTest_sc_filters_test \
-	CppunitTest_sc_ucalc \
-	RdbTarget_sc_filters_test \
-	RdbTarget_sc_ucalc \
-))
-
-
 # vim: set noet sw=4 ts=4:
