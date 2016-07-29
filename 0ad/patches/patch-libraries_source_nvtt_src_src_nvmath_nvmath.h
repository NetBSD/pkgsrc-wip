$NetBSD$

--- libraries/source/nvtt/src/src/nvmath/nvmath.h.orig	2012-06-10 22:39:26.000000000 +0000
+++ libraries/source/nvtt/src/src/nvmath/nvmath.h
@@ -115,7 +115,7 @@ inline bool isFinite(const float f)
 {
 #if NV_OS_WIN32
 	return _finite(f) != 0;
-#elif NV_OS_DARWIN || NV_OS_FREEBSD || NV_OS_OPENBSD
+#elif NV_OS_DARWIN || NV_OS_FREEBSD || NV_OS_NETBSD || NV_OS_OPENBSD
 	return isfinite(f);
 #elif NV_OS_LINUX
 	return finitef(f);
@@ -130,7 +130,7 @@ inline bool isNan(const float f)
 {
 #if NV_OS_WIN32
 	return _isnan(f) != 0;
-#elif NV_OS_DARWIN || NV_OS_FREEBSD || NV_OS_OPENBSD
+#elif NV_OS_DARWIN || NV_OS_FREEBSD || NV_OS_NETBSD || NV_OS_OPENBSD
 	return isnan(f);
 #elif NV_OS_LINUX
 	return isnanf(f);
