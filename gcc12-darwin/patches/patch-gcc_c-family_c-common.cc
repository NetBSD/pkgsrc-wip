$NetBSD$

Fix https://github.com/iains/gcc-darwin-arm64/issues/142
Patch from https://github.com/iains/gcc-14-branch/commit/efb88eb

--- gcc/c-family/c-common.cc.orig	2025-04-04 11:17:31.901763147 +0000
+++ gcc/c-family/c-common.cc
@@ -380,8 +380,8 @@ static bool nonnull_check_p (tree, unsig
 */
 const struct c_common_resword c_common_reswords[] =
 {
-  { "_Alignas",		RID_ALIGNAS,   D_CONLY },
-  { "_Alignof",		RID_ALIGNOF,   D_CONLY },
+  { "_Alignas",		RID_ALIGNAS,   D_EXT_C_IN_CXX },
+  { "_Alignof",		RID_ALIGNOF,   D_EXT_C_IN_CXX },
   { "_Atomic",		RID_ATOMIC,    D_CONLY },
   { "_Bool",		RID_BOOL,      D_CONLY },
   { "_Complex",		RID_COMPLEX,	0 },
