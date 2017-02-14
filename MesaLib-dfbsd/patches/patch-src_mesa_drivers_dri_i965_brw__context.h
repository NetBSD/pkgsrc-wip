$NetBSD$

Use added MESA_ALIGN to ensure no clash if OS had one-argument defined ALIGN.

--- src/mesa/drivers/dri/i965/brw_context.h.orig	2017-02-13 11:55:49.000000000 +0000
+++ src/mesa/drivers/dri/i965/brw_context.h
@@ -1595,7 +1595,7 @@ brw_program_const(const struct gl_progra
 static inline int
 brw_register_blocks(int reg_count)
 {
-   return ALIGN(reg_count, 16) / 16 - 1;
+   return MESA_ALIGN(reg_count, 16) / 16 - 1;
 }
 
 static inline uint32_t
