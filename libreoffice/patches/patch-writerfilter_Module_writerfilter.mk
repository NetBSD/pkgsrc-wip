$NetBSD: patch-writerfilter_Module_writerfilter.mk,v 1.2 2012/01/22 08:47:00 ftigeot Exp $

--- writerfilter/Module_writerfilter.mk.orig	2012-01-09 22:08:58.000000000 +0000
+++ writerfilter/Module_writerfilter.mk
@@ -37,10 +37,12 @@ $(eval $(call gb_Module_add_targets,writ
     Package_writerfilter_generated \
 ))
 
+ifneq ($(OS),NETBSD)
 $(eval $(call gb_Module_add_check_targets,writerfilter,\
     CppunitTest_writerfilter_doctok \
     CppunitTest_writerfilter_rtftok \
 ))
+endif
 
 $(eval $(call gb_Module_add_subsequentcheck_targets,writerfilter,\
     JunitTest_writerfilter_complex \
