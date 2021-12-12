$NetBSD$

--- src/nvim/vim.h.orig	2021-11-30 17:20:42.000000000 +0000
+++ src/nvim/vim.h
@@ -213,6 +213,11 @@ enum { FOLD_TEXT_LEN = 51, };  //!< buff
 // (vim_strchr() is now in strings.c)
 
 #define STRLEN(s)           strlen((char *)(s))
+#ifdef HAVE_STRNLEN
+#  define STRNLEN(s, n)     strnlen((char *)(s), (size_t)(n))
+#else
+#  define STRNLEN(s, n)     xstrnlen((char *)(s), (size_t)(n))
+#endif
 #define STRCPY(d, s)        strcpy((char *)(d), (char *)(s))
 #define STRNCPY(d, s, n)    strncpy((char *)(d), (char *)(s), (size_t)(n))
 #define STRLCPY(d, s, n)    xstrlcpy((char *)(d), (char *)(s), (size_t)(n))
