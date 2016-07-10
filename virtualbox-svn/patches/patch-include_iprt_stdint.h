$NetBSD$

--- include/iprt/stdint.h.orig	2016-07-10 19:43:00.000000000 +0000
+++ include/iprt/stdint.h
@@ -62,7 +62,7 @@
 #  define UINT32_C(Value)   (Value ## U)
 # endif /* 64-bit darwin kludge. */
 
-#elif defined(RT_OS_FREEBSD) && defined(_KERNEL)
+#elif (defined(RT_OS_FREEBSD) && defined(_KERNEL)) || (defined(RT_OS_NETBSD) && defined(_KERNEL))
 
 # ifndef __STDC_CONSTANT_MACROS
 #  define __STDC_CONSTANT_MACROS
@@ -70,6 +70,10 @@
 # ifndef __STDC_LIMIT_MACROS
 #  define __STDC_LIMIT_MACROS
 # endif
+#ifdef __NetBSD__
+# include <sys/param.h>
+# include <sys/types.h>
+#endif
 # include <sys/stdint.h>
 
 #else /* No system stdint.h */
@@ -172,7 +176,8 @@ typedef uint64_t            uintmax_t;
 # if !defined(_MSC_VER) || defined(DOXYGEN_RUNNING)
 #  if ARCH_BITS == 32 \
    || defined(RT_OS_LINUX) \
-   || defined(RT_OS_FREEBSD)
+   || defined(RT_OS_FREEBSD) \
+   || defined(RT_OS_NETBSD)
 #   if !defined(_INTPTR_T_DECLARED)  && !defined(_INTPTR_T)
 typedef signed long         intptr_t;
 #   endif
@@ -263,4 +268,3 @@ typedef uint64_t            uintptr_t;
 #endif
 
 #endif
-
