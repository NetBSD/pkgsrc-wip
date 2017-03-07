$NetBSD$

Why not add DragonFly to OSes here.

--- src/mesa/x86/assyntax.h.orig	2017-02-13 11:55:50.000000000 +0000
+++ src/mesa/x86/assyntax.h
@@ -977,7 +977,7 @@
 
 #if defined(Lynx) || (defined(SYSV) || defined(SVR4)) \
  || (defined(__linux__) || defined(__OS2ELF__)) && defined(__ELF__) \
- || (defined(__FreeBSD__) && __FreeBSD__ >= 3) \
+ || (defined(__FreeBSD__) && __FreeBSD__ >= 3) || defined(__DragonFly__) \
  || (defined(__NetBSD__) && defined(__ELF__))
 #define GLNAME(a)	a
 #else
