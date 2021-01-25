$NetBSD$

--- libr/anal/p/wasm.mk.orig	2021-01-25 12:08:12.000000000 +0000
+++ libr/anal/p/wasm.mk
@@ -1,4 +1,5 @@
 OBJ_WASM=anal_wasm.o
+WASM_ROOT=../asm/arch/wasm
 CFLAGS+=-I$(WASM_ROOT)
 
 STATIC_OBJ+=${OBJ_WASM}
