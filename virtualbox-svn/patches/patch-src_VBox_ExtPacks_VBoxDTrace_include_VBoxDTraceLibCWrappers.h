$NetBSD$

--- src/VBox/ExtPacks/VBoxDTrace/include/VBoxDTraceLibCWrappers.h.orig	2016-08-05 16:45:20.000000000 +0000
+++ src/VBox/ExtPacks/VBoxDTrace/include/VBoxDTraceLibCWrappers.h
@@ -29,7 +29,7 @@
 #else
 # include <sys/types.h>
 # include <limits.h>        /* Workaround for syslimit.h bug in gcc 4.8.3 on gentoo. */
-# ifdef RT_OS_DARWIN
+# if defined(RT_OS_DARWIN) || defined(RT_OS_NETBSD)
 #  include <sys/syslimits.h> /* PATH_MAX */
 # elif !defined(RT_OS_SOLARIS)
 #  include <syslimits.h>    /* PATH_MAX */
@@ -95,4 +95,3 @@
 #define bcmp(a_p1, a_p2, a_cb)      (memcmp(a_p1, a_p2, a_cb))
 
 #endif
-
