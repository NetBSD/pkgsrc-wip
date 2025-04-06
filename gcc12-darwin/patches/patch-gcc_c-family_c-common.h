$NetBSD$

Fix https://github.com/iains/gcc-darwin-arm64/issues/142
Patch from https://github.com/iains/gcc-14-branch/commit/efb88eb

--- gcc/c-family/c-common.h.orig	2025-04-04 11:19:44.492019121 +0000
+++ gcc/c-family/c-common.h
@@ -442,19 +442,23 @@ extern machine_mode c_default_pointer_mo
 #define D_CONLY		0x0001	/* C only (not in C++).  */
 #define D_CXXONLY	0x0002	/* C++ only (not in C).  */
 #define D_C99		0x0004	/* In C, C99 only.  */
-#define D_CXX11         0x0008	/* In C++, C++11 only.  */
-#define D_EXT		0x0010	/* GCC extension.  */
-#define D_EXT89		0x0020	/* GCC extension incorporated in C99.  */
-#define D_ASM		0x0040	/* Disabled by -fno-asm.  */
-#define D_OBJC		0x0080	/* In Objective C and neither C nor C++.  */
-#define D_CXX_OBJC	0x0100	/* In Objective C, and C++, but not C.  */
-#define D_CXXWARN	0x0200	/* In C warn with -Wcxx-compat.  */
-#define D_CXX_CONCEPTS  0x0400	/* In C++, only with concepts.  */
-#define D_TRANSMEM	0X0800	/* C++ transactional memory TS.  */
-#define D_CXX_CHAR8_T	0X1000	/* In C++, only with -fchar8_t.  */
-#define D_CXX20		0x2000  /* In C++, C++20 only.  */
-#define D_CXX_COROUTINES 0x4000  /* In C++, only with coroutines.  */
-#define D_CXX_MODULES	0x8000  /* In C++, only with modules.  */
+#define D_C23           0x0008  /* In C, C23 only.  */
+#define D_CXX11         0x0010	/* In C++, C++11 only.  */
+#define D_EXT		0x0020	/* GCC extension.  */
+#define D_EXT89		0x0040	/* GCC extension incorporated in C99.  */
+#define D_EXT11         0x0080  /* GCC extension incorporated in C23.  */
+#define D_ASM		0x0100	/* Disabled by -fno-asm.  */
+#define D_OBJC		0x0200	/* In Objective C and neither C nor C++.  */
+#define D_CXX_OBJC	0x0400	/* In Objective C, and C++, but not C.  */
+#define D_CXXWARN	0x0800	/* In C warn with -Wcxx-compat.  */
+#define D_CXX_CONCEPTS  0x1000	/* In C++, only with concepts.  */
+#define D_TRANSMEM	0X2000	/* C++ transactional memory TS.  */
+#define D_CXX_CHAR8_T	0X4000	/* In C++, only with -fchar8_t.  */
+#define D_CXX20		0x8000  /* In C++, C++20 only.  */
+#define D_CXX_COROUTINES 0x10000  /* In C++, only with coroutines.  */
+#define D_CXX_MODULES	0x20000  /* In C++, only with modules.  */
+#define D_EXT_C_IN_CXX  0x40000  /* In C++, allow additional C keywords.  */
+#define D_EXT_CXX_IN_C  0x80000  /* In C, allow additional C++ keywords.  */
 
 #define D_CXX_CONCEPTS_FLAGS D_CXXONLY | D_CXX_CONCEPTS
 #define D_CXX_CHAR8_T_FLAGS D_CXXONLY | D_CXX_CHAR8_T
