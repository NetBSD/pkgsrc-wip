$NetBSD: patch-include_system.h,v 1.1.1.1 2011/06/07 20:14:13 rhialto Exp $

Add NetBSD.

--- include/system.h.orig	2010-10-10 12:46:00.000000000 +0000
+++ include/system.h
@@ -94,10 +94,10 @@ typedef long	off_t;
 # if !defined(__SC__) && !defined(LINUX)
 E  long NDECL(random);
 # endif
-# if (!defined(SUNOS4) && !defined(bsdi) && !defined(__FreeBSD__)) || defined(RANDOM)
+# if (!defined(SUNOS4) && !defined(bsdi) && !defined(__FreeBSD__) && !defined(__NetBSD__)) || defined(RANDOM)
 E void FDECL(srandom, (unsigned int));
 # else
-#  if !defined(bsdi) && !defined(__FreeBSD__)
+#  if !defined(bsdi) && !defined(__FreeBSD__) && !defined(__NetBSD__)
 E int FDECL(srandom, (unsigned int));
 #  endif
 # endif
