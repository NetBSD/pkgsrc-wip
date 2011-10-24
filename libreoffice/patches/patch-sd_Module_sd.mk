$NetBSD: patch-sd_Module_sd.mk,v 1.2 2011/10/24 14:17:46 ftigeot Exp $

--- sd/Module_sd.mk.orig	2011-10-17 16:49:48.000000000 +0000
+++ sd/Module_sd.mk
@@ -40,7 +40,7 @@ $(eval $(call gb_Module_add_targets,sd,\
     Package_xml \
 ))
 
-ifneq ($(OS),DRAGONFLY)
+ifeq (,$(filter DRAGONFLY NETBSD,$(OS)))
 $(eval $(call gb_Module_add_check_targets,sd,\
     CppunitTest_sd_uimpress \
     RdbTarget_sd_uimpress \
