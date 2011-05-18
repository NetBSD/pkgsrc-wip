$NetBSD: patch-clone_calc_sc_Module_sc.mk,v 1.1.1.1 2011/05/18 11:50:18 ftigeot Exp $

--- clone/calc/sc/Module_sc.mk.orig	2011-05-11 12:36:55 +0000
+++ clone/calc/sc/Module_sc.mk
@@ -33,9 +33,4 @@ $(eval $(call gb_Module_add_targets,sc,\
 	Package_xml \
 ))
 
-$(eval $(call gb_Module_add_check_targets,sc,\
-	CppunitTest_sc_ucalc \
-))
-
-
 # vim: set noet ts=4 sw=4:
