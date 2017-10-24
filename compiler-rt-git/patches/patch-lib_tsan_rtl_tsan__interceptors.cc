$NetBSD$

--- lib/tsan/rtl/tsan_interceptors.cc.orig	2017-10-20 11:21:05.000000000 +0000
+++ lib/tsan/rtl/tsan_interceptors.cc
@@ -43,8 +43,16 @@ using namespace __tsan;  // NOLINT
 #if SANITIZER_NETBSD
 #define dirfd(dirp) (*(int *)(dirp))
 #define fileno_unlocked fileno
-#define stdout __sF[1]
-#define stderr __sF[2]
+
+#if _LP64
+#define __sF_size 152
+#else
+#define __sF_size 88
+#endif
+
+#define stdout ((char*)&__sF + (__sF_size * 1))
+#define stderr ((char*)&__sF + (__sF_size * 2))
+
 #endif
 
 #if SANITIZER_ANDROID
@@ -99,7 +107,7 @@ extern "C" int dirfd(void *dirp);
 extern "C" int mallopt(int param, int value);
 #endif
 #if SANITIZER_NETBSD
-extern __sanitizer_FILE **__sF;
+extern __sanitizer_FILE __sF[];
 #else
 extern __sanitizer_FILE *stdout, *stderr;
 #endif
