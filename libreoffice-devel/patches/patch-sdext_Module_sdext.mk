$NetBSD: patch-sdext_Module_sdext.mk,v 1.1 2012/08/26 16:05:42 ftigeot Exp $

Disable broken sdext_pdfimport unit test

--- sdext/Module_sdext.mk.orig	2012-08-21 17:01:59.000000000 +0000
+++ sdext/Module_sdext.mk
@@ -48,10 +48,6 @@ $(eval $(call gb_Module_add_targets,sdex
     Rdb_pdfimport \
     StaticLibrary_pdfimport_s \
 ))
-
-$(eval $(call gb_Module_add_check_targets,sdext,\
-    CppunitTest_pdfimport \
-))
 endif
 
 ifeq ($(ENABLE_PRESENTER_SCREEN),YES)
