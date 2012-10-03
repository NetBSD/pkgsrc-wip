$NetBSD: patch-programs_dtudcfonted_libfuty_getfname.c,v 1.1 2012/10/03 19:25:55 jellehermsen Exp $

--- programs/dtudcfonted/libfuty/getfname.c.orig	2012-09-29 10:35:38.000000000 +0000
+++ programs/dtudcfonted/libfuty/getfname.c
@@ -1047,7 +1047,7 @@ char	**fontname ;
 {
 	FILE	*fp ;
 	pid_t	chld_pid = 0;
-#if defined( SVR4 ) || defined( SYSV ) || defined(__FreeBSD__)
+#if defined( SVR4 ) || defined( SYSV ) || defined(CSRG_BASED)
 	int	chld_stat ;
 #else
 	union	wait	chld_stat ;
