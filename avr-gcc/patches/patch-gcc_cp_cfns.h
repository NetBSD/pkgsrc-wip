$NetBSD: patch-gcc_cp_cfns.h,v 1.1 2013/08/06 06:44:51 makoto Exp $

date: 2012-11-16 09:38:21 +0900;  author: joerg;  state: Exp;
Fix inline usage.

--- gcc/cp/cfns.h.orig	2012-11-14 17:13:55.000000000 +0000
+++ gcc/cp/cfns.h
@@ -35,7 +35,7 @@
 #endif
 static unsigned int hash (const char *, unsigned int);
 #ifdef __GNUC__
-__inline
+static __inline
 #endif
 const char * libc_name_p (const char *, unsigned int);
 /* maximum key range = 391, duplicates = 0 */
