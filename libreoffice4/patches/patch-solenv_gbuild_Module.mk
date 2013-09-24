$NetBSD: patch-solenv_gbuild_Module.mk,v 1.1 2013/09/24 12:51:50 ryo-on Exp $

--- solenv/gbuild/Module.mk.orig	2013-08-21 11:40:03.000000000 +0000
+++ solenv/gbuild/Module.mk
@@ -91,7 +91,7 @@ $(call gb_Module_get_target,%) :
 .PHONY : all build unitcheck slowcheck subsequentcheck clean check debugrun help showmodules translations
 .DEFAULT_GOAL := all
 
-all : build $(if $(CROSS_COMPILING),,unitcheck $(if $(gb_PARTIAL_BUILD),,slowcheck))
+all : build
 
 build-tools : $(gb_BUILD_TOOLS)
 	$(call gb_Output_announce,loaded tools: $(gb_BUILD_TOOLS),$(true),ALL,6)
