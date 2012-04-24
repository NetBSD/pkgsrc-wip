$NetBSD: patch-sc_Module_sc.mk,v 1.1.1.1 2012/04/24 21:38:28 ftigeot Exp $

--- sc/Module_sc.mk.orig	2012-04-22 18:44:29.000000000 +0000
+++ sc/Module_sc.mk
@@ -42,7 +42,6 @@ $(eval $(call gb_Module_add_targets,sc,\
 endif
 
 $(eval $(call gb_Module_add_check_targets,sc,\
-    CppunitTest_sc_ucalc \
     CppunitTest_sc_filters_test \
 ))
 
