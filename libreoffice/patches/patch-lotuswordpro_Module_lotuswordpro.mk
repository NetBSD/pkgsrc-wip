$NetBSD: patch-lotuswordpro_Module_lotuswordpro.mk,v 1.1 2011/10/24 14:34:36 ftigeot Exp $

--- lotuswordpro/Module_lotuswordpro.mk.orig	2011-10-17 16:49:48.000000000 +0000
+++ lotuswordpro/Module_lotuswordpro.mk
@@ -32,9 +32,11 @@ $(eval $(call gb_Module_add_targets,lotu
     Library_lwpft \
 ))
 
+ifneq ($(OS),NETBSD)
 $(eval $(call gb_Module_add_check_targets,lotuswordpro,\
     CppunitTest_lotuswordpro_test_lotuswordpro \
     RdbTarget_lotuswordpro_test_lotuswordpro \
 ))
+endif
 
 # vim: set noet sw=4 ts=4:
