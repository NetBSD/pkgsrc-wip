$NetBSD$

Fix https://github.com/iains/gcc-darwin-arm64/issues/142
Patch from https://github.com/iains/gcc-14-branch/commit/efb88eb

--- gcc/cp/lex.cc.orig	2025-04-04 11:34:36.276372485 +0000
+++ gcc/cp/lex.cc
@@ -253,6 +253,9 @@ init_reswords (void)
     {
       if (c_common_reswords[i].disable & D_CONLY)
 	continue;
+      if (!flag_allow_extra_keywords
+          && c_common_reswords[i].disable & D_EXT_C_IN_CXX)
+        continue;
       id = get_identifier (c_common_reswords[i].word);
       C_SET_RID_CODE (id, c_common_reswords[i].rid);
       ridpointers [(int) c_common_reswords[i].rid] = id;
