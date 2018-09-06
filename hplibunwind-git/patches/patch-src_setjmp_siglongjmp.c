$NetBSD$

--- src/setjmp/siglongjmp.c.orig	2018-09-04 09:38:02.000000000 +0000
+++ src/setjmp/siglongjmp.c
@@ -103,7 +103,7 @@ siglongjmp (sigjmp_buf env, int val)
                 || (_NSIG > 8 * sizeof (unw_word_t)
                     && unw_set_reg (&c, UNW_REG_EH + 3, wp[JB_MASK + 1]) < 0))
               abort ();
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__NetBSD__)
           if (unw_set_reg (&c, UNW_REG_EH + 2, &wp[JB_MASK]) < 0)
               abort();
 #else
