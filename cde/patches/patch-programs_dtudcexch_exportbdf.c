$NetBSD: patch-programs_dtudcexch_exportbdf.c,v 1.1 2012/10/03 19:25:55 jellehermsen Exp $

--- programs/dtudcexch/exportbdf.c.orig	2012-09-29 10:31:47.000000000 +0000
+++ programs/dtudcexch/exportbdf.c
@@ -212,7 +212,7 @@ char    **comment_list ;/* pointer to th
 	int 		cnt ;
 	int		comflg ;
 	pid_t		chld_pid = 0;
-#if defined( SVR4 ) || defined( SYSV ) || defined(__FreeBSD__)
+#if defined( SVR4 ) || defined( SYSV ) || defined(CSRG_BASED)
 	int		chld_stat ;
 #else
 	union	wait	chld_stat ;
