$NetBSD$

--- src/gallium/drivers/i915/i915_fpc_translate.c.orig	2019-03-15 01:02:19.000000000 +0000
+++ src/gallium/drivers/i915/i915_fpc_translate.c
@@ -1095,7 +1095,11 @@ i915_init_compile(struct i915_context *i
    p->decl = p->declarations;
    p->decl_s = 0;
    p->decl_t = 0;
+#if defined(STRICT_XSRC_NETBSD)
+   p->temp_flag = ~0x0U << I915_MAX_TEMPORARY;
+#else
    p->temp_flag = ~0x0 << I915_MAX_TEMPORARY;
+#endif
    p->utemp_flag = ~0x7;
 
    /* initialize the first program word */
