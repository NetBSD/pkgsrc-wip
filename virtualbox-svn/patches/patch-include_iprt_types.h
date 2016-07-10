$NetBSD$

--- include/iprt/types.h.orig	2016-03-04 19:23:02.000000000 +0000
+++ include/iprt/types.h
@@ -203,12 +203,12 @@ RT_C_DECLS_END
 # if defined(__GNUC__)
 #  if defined(RT_OS_LINUX) && __GNUC__ < 3
 typedef uint8_t bool;
-#  elif defined(RT_OS_FREEBSD)
+#  elif defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
 #   ifndef __bool_true_false_are_defined
 typedef _Bool bool;
 #   endif
 #  else
-#   if (defined(RT_OS_DARWIN) || defined(RT_OS_HAIKU)) && (defined(_STDBOOL_H) || defined(__STDBOOL_H))
+#   if (defined(RT_OS_DARWIN) || defined(RT_OS_HAIKU)) && (defined(_STDBOOL_H) || defined(__STDBOOL_H)) || defined(_SYS_STDBOOL_H_) || defined(_SYS_STDBOOL_H_)
 #    undef bool
 #   endif
 typedef _Bool bool;
@@ -2617,4 +2617,3 @@ public:
 /** @} */
 
 #endif
-
