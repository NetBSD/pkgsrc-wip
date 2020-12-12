$NetBSD$

This doesn't work. Just require GNU sed.

--- source/Makefile.mk.orig	2020-09-26 14:38:36.000000000 +0000
+++ source/Makefile.mk
@@ -690,11 +690,7 @@ endif
 # ---------------------------------------------------------------------------------------------------------------------
 # Set arguments used for inline 'sed'
 
-ifeq ($(BSD),true)
-SED_ARGS=-i '' -e
-else
 SED_ARGS=-i -e
-endif
 
 # ---------------------------------------------------------------------------------------------------------------------
 # Set command used for file symlinking
