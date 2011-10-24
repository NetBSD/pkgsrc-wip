$NetBSD: patch-writerfilter_Module_writerfilter.mk,v 1.1 2011/10/24 14:34:36 ftigeot Exp $

--- writerfilter/Module_writerfilter.mk.orig	2011-10-17 16:49:48.000000000 +0000
+++ writerfilter/Module_writerfilter.mk
@@ -38,11 +38,13 @@ $(eval $(call gb_Module_add_targets,writ
     Package_writerfilter_generated \
 ))
 
+ifneq ($(OS),NETBSD)
 $(eval $(call gb_Module_add_check_targets,writerfilter,\
     CppunitTest_writerfilter_doctok \
     CppunitTest_writerfilter_rtftok \
     RdbTarget_writerfilter_rtftok \
 ))
+endif
 
 $(eval $(call gb_Module_add_subsequentcheck_targets,writerfilter,\
     JunitTest_writerfilter_complex \
