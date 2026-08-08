$NetBSD$

--- string.c.orig	2026-08-07 10:43:44.947408788 +0000
+++ string.c
@@ -1985,7 +1985,7 @@ static VALUE
 }
 
 static VALUE
-get_arg_pat(pat, quote)
+get_arg_pat(pat)
      VALUE pat;
 {
     return rb_rescue2(get_pat_quoted, pat,
