$NetBSD: patch-plugins_chartshape_kdchart_kdablibfakes_src_KDABLibFakes.h,v 1.1 2012/07/02 13:34:33 thomasklausner Exp $

isnan() and isinf() are macros on NetBSD (C99 conformant).
Use same workaround as for Mac OS X and Cygwin.

--- plugins/chartshape/kdchart/kdablibfakes/src/KDABLibFakes.h.orig	2012-06-26 04:18:01.000000000 +0000
+++ plugins/chartshape/kdchart/kdablibfakes/src/KDABLibFakes.h
@@ -52,7 +52,7 @@
 #include <float.h>
 #define ISNAN(x ) _isnan(x )
 #define ISINF(x ) (!(_finite(x ) + _isnan(x ) ) )
-#elif defined (Q_OS_DARWIN) || defined (Q_OS_CYGWIN)
+#elif defined (Q_OS_DARWIN) || defined (Q_OS_CYGWIN) || defined(Q_OS_NETBSD)
 #define ISNAN(x) std::isnan(x)
 #define ISINF(x) std::isinf(x)
 #else
