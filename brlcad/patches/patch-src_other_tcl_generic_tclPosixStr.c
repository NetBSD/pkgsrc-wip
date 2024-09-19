$NetBSD$

Baskport patch from TCL 8.6.

--- src/other/tcl/generic/tclPosixStr.c.orig	2016-08-09 06:47:08.000000000 +0000
+++ src/other/tcl/generic/tclPosixStr.c
@@ -337,7 +337,7 @@ Tcl_ErrnoId(void)
 #if defined(EOPNOTSUPP) &&  (!defined(ENOTSUP) || (ENOTSUP != EOPNOTSUPP))
     case EOPNOTSUPP: return "EOPNOTSUPP";
 #endif
-#if defined(EOVERFLOW) && (!defined(EFBIG) || (EOVERFLOW != EFBIG)) && (!defined(EINVAL) || (EOVERFLOW != EINVAL))
+#if defined(EOVERFLOW) && (!defined(EFBIG) || (EOVERFLOW != EFBIG)) && (!defined(EINVAL) || (EOVERFLOW != EINVAL)) && (!defined(ERANGE) || (EOVERFLOW != ERANGE))
     case EOVERFLOW: return "EOVERFLOW";
 #endif
 #ifdef EPERM
@@ -785,7 +785,7 @@ Tcl_ErrnoMsg(
 #if defined(EOPNOTSUPP) &&  (!defined(ENOTSUP) || (ENOTSUP != EOPNOTSUPP))
     case EOPNOTSUPP: return "operation not supported on socket";
 #endif
-#if defined(EOVERFLOW) && (!defined(EFBIG) || (EOVERFLOW != EFBIG)) && (!defined(EINVAL) || (EOVERFLOW != EINVAL))
+#if defined(EOVERFLOW) && (!defined(EFBIG) || (EOVERFLOW != EFBIG)) && (!defined(EINVAL) || (EOVERFLOW != EINVAL)) && (!defined(ERANGE) || (EOVERFLOW != ERANGE))
     case EOVERFLOW: return "file too big";
 #endif
 #ifdef EPERM
