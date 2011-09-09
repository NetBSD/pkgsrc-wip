$NetBSD: patch-sc_Module_sc.mk,v 1.1 2011/09/09 08:21:12 ftigeot Exp $

--- sc/Module_sc.mk.orig	2011-08-30 15:00:33.000000000 +0000
+++ sc/Module_sc.mk
@@ -34,10 +34,4 @@ $(eval $(call gb_Module_add_targets,sc,\
 	Package_xml \
 ))
 
-$(eval $(call gb_Module_add_check_targets,sc,\
-	CppunitTest_sc_ucalc \
-	CppunitTest_sc_test_filters \
-))
-
-
 # vim: set noet sw=4 ts=4:
