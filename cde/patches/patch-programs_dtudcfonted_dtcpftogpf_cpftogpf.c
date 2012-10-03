$NetBSD: patch-programs_dtudcfonted_dtcpftogpf_cpftogpf.c,v 1.1 2012/10/03 19:25:55 jellehermsen Exp $

--- programs/dtudcfonted/dtcpftogpf/cpftogpf.c.orig	2012-09-29 10:35:02.000000000 +0000
+++ programs/dtudcfonted/dtcpftogpf/cpftogpf.c
@@ -102,7 +102,7 @@ char	*argv[];
 	char	*style ;	/* style */
 	int 	chk_fd;
 	pid_t	chld_pid = 0;
-#if defined( SVR4 ) || defined( SYSV ) || defined(__FreeBSD__)
+#if defined( SVR4 ) || defined( SYSV ) || defined(CSRG_BASED)
 	int	chld_stat ;
 #else
 	union	wait	chld_stat ;
