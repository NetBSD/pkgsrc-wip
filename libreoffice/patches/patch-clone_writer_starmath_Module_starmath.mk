$NetBSD: patch-clone_writer_starmath_Module_starmath.mk,v 1.2 2011/06/15 17:20:21 ftigeot Exp $

--- clone/writer/starmath/Module_starmath.mk.orig	2011-06-14 15:12:29 +0000
+++ clone/writer/starmath/Module_starmath.mk
@@ -29,12 +29,6 @@ $(eval $(call gb_Module_add_targets,sm,\
     Package_uiconfig \
 ))
 
-ifneq ($(OS),OPENBSD)
-$(eval $(call gb_Module_add_check_targets,sm,\
-    CppunitTest_starmath_qa_cppunit \
-))
-endif
-
 $(eval $(call gb_Module_add_subsequentcheck_targets,sm,\
     JunitTest_starmath_unoapi \
 ))
