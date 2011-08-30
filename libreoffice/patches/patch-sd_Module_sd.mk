$NetBSD: patch-sd_Module_sd.mk,v 1.1 2011/08/30 20:41:34 ftigeot Exp $

--- sd/Module_sd.mk.orig	2011-08-23 13:05:22.000000000 +0000
+++ sd/Module_sd.mk
@@ -40,10 +40,6 @@ $(eval $(call gb_Module_add_targets,sd,\
     Package_xml \
 ))
 
-$(eval $(call gb_Module_add_check_targets,sd,\
-    CppunitTest_sd_uimpress \
-))
-
 $(eval $(call gb_Module_add_subsequentcheck_targets,sd,\
     JunitTest_sd_unoapi \
 ))
