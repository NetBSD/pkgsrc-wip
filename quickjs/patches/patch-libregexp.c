$NetBSD$

Fix issue found on 32-bit ports, where pointers could end up
as negative values when cast to intptr_t.

--- libregexp.c.orig	2019-07-09 17:49:47.000000000 +0000
+++ libregexp.c
@@ -2027,6 +2027,7 @@ static int push_state(REExecContext *s,
     return 0;
 }
 
+/* Comment is misleading: can also return int'ed pointer */
 /* return 1 if match, 0 if not match or -1 if error. */
 static intptr_t lre_exec_backtrack(REExecContext *s, uint8_t **capture,
                                    StackInt *stack, int stack_len,
@@ -2407,7 +2408,7 @@ static intptr_t lre_exec_backtrack(REExe
                 for(;;) {
                     res = lre_exec_backtrack(s, capture, stack, stack_len,
                                              pc1, cptr, TRUE);
-                    if (res < 0)
+                    if (res == -1)
                         return res;
                     if (!res)
                         break;
