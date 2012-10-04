$NetBSD: patch-programs_dtprintinfo_libUI_MotifUI_Debug.c,v 1.1 2012/10/04 04:57:03 jellehermsen Exp $

--- programs/dtprintinfo/libUI/MotifUI/Debug.c.orig	2012-09-29 12:06:55.000000000 +0000
+++ programs/dtprintinfo/libUI/MotifUI/Debug.c
@@ -105,7 +105,7 @@ SysErrorMsg(
    int n
    )
 {
-#if !defined(linux) && !defined(__FreeBSD__)
+#if !defined(linux) && !defined(CSRG_BASED)
     extern char *sys_errlist[];
     extern int sys_nerr;
 #endif
