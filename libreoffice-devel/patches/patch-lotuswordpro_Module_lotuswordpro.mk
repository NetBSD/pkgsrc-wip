$NetBSD: patch-lotuswordpro_Module_lotuswordpro.mk,v 1.2 2012/09/02 16:48:11 ftigeot Exp $

Disable unit tests crashing on NetBSD

--- lotuswordpro/Module_lotuswordpro.mk.orig	2012-01-09 22:08:58.000000000 +0000
+++ lotuswordpro/Module_lotuswordpro.mk
@@ -31,8 +31,10 @@ $(eval $(call gb_Module_add_targets,lotu
     Library_lwpft \
 ))
 
+ifneq ($(OS),NETBSD)
 $(eval $(call gb_Module_add_check_targets,lotuswordpro,\
     CppunitTest_lotuswordpro_test_lotuswordpro \
 ))
+endif
 
 # vim: set noet sw=4 ts=4:
