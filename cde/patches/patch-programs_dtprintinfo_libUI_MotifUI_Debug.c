$NetBSD: patch-programs_dtprintinfo_libUI_MotifUI_Debug.c,v 1.2 2014/07/23 10:07:43 obache Exp $

--- programs/dtprintinfo/libUI/MotifUI/Debug.c.orig	2014-03-01 22:48:49.000000000 +0000
+++ programs/dtprintinfo/libUI/MotifUI/Debug.c
@@ -105,7 +105,7 @@ SysErrorMsg(
    int n
    )
 {
-#if !defined(linux) && !defined(__FreeBSD__) && !defined(__NetBSD__)
+#if !defined(linux) && !defined(CSRG_BASED)
     extern char *sys_errlist[];
     extern int sys_nerr;
 #endif
