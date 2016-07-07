$NetBSD$

--- src/VBox/Devices/EFI/Firmware/AppPkg/Applications/Python/PyMod-2.7.1/Include/pyport.h.orig	2016-03-04 19:25:48.000000000 +0000
+++ src/VBox/Devices/EFI/Firmware/AppPkg/Applications/Python/PyMod-2.7.1/Include/pyport.h
@@ -455,7 +455,7 @@ extern "C" {
  *    This isn't reliable.  See Py_OVERFLOWED comments.
  *    X is evaluated more than once.
  */
-#if defined(__FreeBSD__) || defined(__OpenBSD__) || (defined(__hpux) && defined(__ia64))
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || (defined(__hpux) && defined(__ia64)) || defined(__NetBSD__)
 #define _Py_SET_EDOM_FOR_NAN(X) if (isnan(X)) errno = EDOM;
 #else
 #define _Py_SET_EDOM_FOR_NAN(X) ;
@@ -671,6 +671,9 @@ extern int fdatasync(int);
 #endif
 #endif
 
+#ifdef __NetBSD__
+# define _PY_PORT_CTYPE_UTF8_ISSUE
+#endif
 
 #if defined(__APPLE__)
 # define _PY_PORT_CTYPE_UTF8_ISSUE
