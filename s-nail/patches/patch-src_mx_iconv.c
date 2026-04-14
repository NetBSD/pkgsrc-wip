$NetBSD$

--- src/mx/iconv.c.orig	2026-04-08 15:18:19.000000000 +0000
+++ src/mx/iconv.c
@@ -293,7 +293,7 @@ n_iconv_reset(iconv_t cd){
 # undef a_X
 # if defined _ICONV_H_ && defined __ICONV_F_HIDE_INVALID
   /* DragonFly 3.2.1 is special TODO newer DragonFly too, but different */
-#  if su_OS_DRAGONFLY
+#  if su_OS_DRAGONFLY || su_OS_NETBSD
 #   define a_X(X) S(char** __restrict__,S(void*,UNCONST(char*,X)))
 #  else
 #   define a_X(X) S(char const**,S(void*,UNCONST(char*,X)))
