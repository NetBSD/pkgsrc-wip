$NetBSD$

--- gcc/d/d-system.h.orig	2019-01-01 12:31:55.000000000 +0000
+++ gcc/d/d-system.h
@@ -24,7 +24,8 @@
 
 /* Used by the dmd front-end to determine if we have POSIX-style IO.  */
 #define POSIX (__linux__ || __GLIBC__ || __gnu_hurd__ || __APPLE__ \
-	       || __FreeBSD__ || __OpenBSD__ || __DragonFly__ || __sun)
+	       || __FreeBSD__ || __NetBSD__ || __OpenBSD__ || __DragonFly__ \
+	       || __sun)
 
 /* Forward assert invariants to gcc_assert.  */
 #undef assert
