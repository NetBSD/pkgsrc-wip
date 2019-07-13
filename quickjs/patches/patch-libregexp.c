$NetBSD$

Fix issue found on 32-bit ports, where pointers could end up
as negative values when cast to intptr_t.

--- libregexp.c.orig	2019-07-09 17:49:47.000000000 +0000
+++ libregexp.c
@@ -2027,8 +2027,9 @@ static int push_state(REExecContext *s,
     return 0;
 }
 
+/* Comment is misleading: can also return int'ed pointer */
 /* return 1 if match, 0 if not match or -1 if error. */
-static intptr_t lre_exec_backtrack(REExecContext *s, uint8_t **capture,
+static uintptr_t lre_exec_backtrack(REExecContext *s, uint8_t **capture,
                                    StackInt *stack, int stack_len,
                                    const uint8_t *pc, const uint8_t *cptr,
                                    BOOL no_recurse)
@@ -2049,7 +2050,7 @@ static intptr_t lre_exec_backtrack(REExe
             {
                 REExecState *rs;
                 if (no_recurse)
-                    return (intptr_t)cptr;
+                    return (uintptr_t)cptr;
                 ret = 1;
                 goto recurse;
             no_match:
@@ -2393,7 +2394,7 @@ static intptr_t lre_exec_backtrack(REExe
             {
                 uint32_t next_pos, quant_min, quant_max;
                 size_t q;
-                intptr_t res;
+                uintptr_t res;
                 const uint8_t *pc1;
                 
                 next_pos = get_u32(pc);
@@ -2407,7 +2408,7 @@ static intptr_t lre_exec_backtrack(REExe
                 for(;;) {
                     res = lre_exec_backtrack(s, capture, stack, stack_len,
                                              pc1, cptr, TRUE);
-                    if (res < 0)
+                    if (res == (uintptr_t)-1)
                         return res;
                     if (!res)
                         break;
@@ -2443,7 +2444,8 @@ int lre_exec(uint8_t **capture,
              int cbuf_type, void *opaque)
 {
     REExecContext s_s, *s = &s_s;
-    int re_flags, i, alloca_size, ret;
+    int re_flags, i, alloca_size;
+    uintptr_t ret;
     StackInt *stack_buf;
     
     re_flags = bc_buf[RE_HEADER_FLAGS];
@@ -2473,7 +2475,9 @@ int lre_exec(uint8_t **capture,
     ret = lre_exec_backtrack(s, capture, stack_buf, 0, bc_buf + RE_HEADER_LEN,
                              cbuf + (cindex << cbuf_type), FALSE);
     lre_realloc(s->opaque, s->state_stack, 0);
-    return ret;
+    if (ret == (uintptr_t)-1)
+	return -1;
+    return (int)ret;
 }
 
 int lre_get_capture_count(const uint8_t *bc_buf)
