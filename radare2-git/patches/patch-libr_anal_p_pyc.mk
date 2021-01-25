$NetBSD$

--- libr/anal/p/pyc.mk.orig	2021-01-25 12:08:12.000000000 +0000
+++ libr/anal/p/pyc.mk
@@ -35,6 +35,7 @@ STATIC_OBJ+=${OBJ_PYC}
 TARGET_PYC=anal_pyc.$(EXT_SO)
 
 ALL_TARGETS+=${TARGET_PYC}
+PYC_ROOT=../asm/arch/pyc
 CFLAGS+=-I$(PYC_ROOT)
 
 ${TARGET_PYC}: ${OBJ_PYC}
