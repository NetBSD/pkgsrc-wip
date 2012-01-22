$NetBSD: patch-sd_Module_sd.mk,v 1.3 2012/01/22 08:47:00 ftigeot Exp $

--- sd/Module_sd.mk.orig	2012-01-09 22:08:58.000000000 +0000
+++ sd/Module_sd.mk
@@ -40,7 +40,7 @@ $(eval $(call gb_Module_add_targets,sd,\
     Package_xml \
 ))
 
-ifneq ($(OS),DRAGONFLY)
+ifeq (,$(filter DRAGONFLY NETBSD,$(OS)))
 $(eval $(call gb_Module_add_check_targets,sd,\
     CppunitTest_sd_uimpress \
 ))
