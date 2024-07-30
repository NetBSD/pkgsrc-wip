$NetBSD: patch-include_safe-ctype.h,v 1.3 2020/12/06 18:07:53 fcambus Exp $

--- include/safe-ctype.h.orig	2020-07-24 09:12:20.000000000 +0000
+++ include/safe-ctype.h
@@ -120,6 +120,8 @@ extern const unsigned char  _sch_tolower
    So we include ctype.h here and then immediately redefine its macros.  */
 
 #include <ctype.h>
+
+#ifndef __cplusplus
 #undef isalpha
 #define isalpha(c) do_not_use_isalpha_with_safe_ctype
 #undef isalnum
@@ -146,5 +148,6 @@ extern const unsigned char  _sch_tolower
 #define toupper(c) do_not_use_toupper_with_safe_ctype
 #undef tolower
 #define tolower(c) do_not_use_tolower_with_safe_ctype
+#endif
 
 #endif /* SAFE_CTYPE_H */
