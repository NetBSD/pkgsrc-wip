$NetBSD$

--- src/main.mk.orig	2020-08-03 07:31:39.000000000 +0000
+++ src/main.mk
@@ -1,8 +1,8 @@
 ifeq "$(strip ${BUILD_DIR})" ""
-  BUILD_DIR    := ../$(OSTYPE)-$(MACHINETYPE)/obj
+  BUILD_DIR    := ../obj
 endif
 ifeq "$(strip ${TARGET_DIR})" ""
-  TARGET_DIR   := ../$(OSTYPE)-$(MACHINETYPE)/bin
+  TARGET_DIR   := ../bin
 endif
 
 TARGET       := libontcns.a
