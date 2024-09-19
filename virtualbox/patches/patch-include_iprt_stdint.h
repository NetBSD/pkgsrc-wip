$NetBSD$

--- include/iprt/stdint.h.orig	2016-03-04 19:23:01.000000000 +0000
+++ include/iprt/stdint.h
@@ -34,6 +34,7 @@
  */
 #if !(defined(RT_OS_LINUX) && defined(__KERNEL__))  \
   && !(defined(RT_OS_FREEBSD) && defined(_KERNEL)) \
+  && !(defined(RT_OS_NETBSD) && defined(_KERNEL)) \
   && !defined(_MSC_VER) \
   && !defined(__IBMC__) \
   && !defined(__IBMCPP__) \
@@ -62,7 +63,7 @@
 #  define UINT32_C(Value)   (Value ## U)
 # endif /* 64-bit darwin kludge. */
 
-#elif defined(RT_OS_FREEBSD) && defined(_KERNEL)
+#elif (defined(RT_OS_FREEBSD) && defined(_KERNEL)) || (defined(RT_OS_NETBSD) && defined(_KERNEL))
 
 # ifndef __STDC_CONSTANT_MACROS
 #  define __STDC_CONSTANT_MACROS
@@ -157,7 +158,8 @@ typedef uint64_t            uintmax_t;
 # if !defined(_MSC_VER) || defined(DOXYGEN_RUNNING)
 #  if ARCH_BITS == 32 \
    || defined(RT_OS_LINUX) \
-   || defined(RT_OS_FREEBSD)
+   || defined(RT_OS_FREEBSD) \
+   || defined(RT_OS_NETBSD)
 #   if !defined(_INTPTR_T_DECLARED)  && !defined(_INTPTR_T)
 typedef signed long         intptr_t;
 #   endif
@@ -241,4 +243,3 @@ typedef uint64_t            uintptr_t;
 #endif
 
 #endif
-
