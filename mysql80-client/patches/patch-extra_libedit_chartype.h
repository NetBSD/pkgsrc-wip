$NetBSD$

Exclude DragonFly & OpenBSD

--- extra/libedit/chartype.h.orig	2019-12-09 19:53:17.000000000 +0000
+++ extra/libedit/chartype.h
@@ -49,7 +49,8 @@
   TODO : Verify if FreeBSD & AIX stores ISO 10646 in wchar_t. */
 #if !defined(__NetBSD__) && !defined(__sun) \
   && !(defined(__APPLE__) && defined(__MACH__)) \
-  && !defined(__FreeBSD__) && !defined(_AIX)
+  && !defined(__FreeBSD__) && !defined(_AIX) \
+  && !defined(__DragonFly__) && !defined(__OpenBSD__)
 #ifndef __STDC_ISO_10646__
 /* In many places it is assumed that the first 127 code points are ASCII
  * compatible, so ensure wchar_t indeed does ISO 10646 and not some other
