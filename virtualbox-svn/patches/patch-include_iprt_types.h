$NetBSD$

--- include/iprt/types.h.orig	2016-08-12 18:06:06.000000000 +0000
+++ include/iprt/types.h
@@ -222,13 +222,16 @@ typedef uint8_t bool;
 typedef _Bool bool;
 #   endif
 #  elif defined(RT_OS_NETBSD)
-#   if !defined(_KERNEL)
-     /*
-      * For the kernel code <stdbool.h> is not available, but bool is
-      * provided by <sys/types.h> included above.
-      */
-#    include <stdbool.h>
+#   ifndef __bool_true_false_are_defined
+typedef _Bool bool;
 #   endif
+//#   if !defined(_KERNEL)
+//     *
+//      * For the kernel code <stdbool.h> is not available, but bool is
+//      * provided by <sys/types.h> included above.
+//      *
+//#    include <stdbool.h>
+//#   endif
 #  else
 #   if (defined(RT_OS_DARWIN) || defined(RT_OS_HAIKU)) && (defined(_STDBOOL_H) || defined(__STDBOOL_H))
 #    undef bool
@@ -2796,4 +2799,3 @@ public:
 /** @} */
 
 #endif
-
