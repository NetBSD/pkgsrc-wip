$NetBSD: patch-clone_calc_sc_Module_sc.mk,v 1.2 2011/07/21 05:16:36 ftigeot Exp $

--- clone/calc/sc/Module_sc.mk.orig	2011-05-11 12:36:55 +0000
+++ clone/calc/sc/Module_sc.mk
@@ -33,10 +33,4 @@ $(eval $(call gb_Module_add_targets,sc,\
 	Package_xml \
 ))
 
-$(eval $(call gb_Module_add_check_targets,sc,\
-	CppunitTest_sc_ucalc \
-	CppunitTest_sc_test_filters \
-))
-
-
 # vim: set noet ts=4 sw=4:
