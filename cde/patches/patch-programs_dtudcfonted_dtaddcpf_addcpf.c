$NetBSD: patch-programs_dtudcfonted_dtaddcpf_addcpf.c,v 1.1 2012/10/03 19:25:55 jellehermsen Exp $

--- programs/dtudcfonted/dtaddcpf/addcpf.c.orig	2012-09-29 10:34:25.000000000 +0000
+++ programs/dtudcfonted/dtaddcpf/addcpf.c
@@ -86,7 +86,7 @@ static	char	*util_locale ;
 
 static	pid_t	gtob_pid = 0;
 static	pid_t	btop_pid = 0;
-#if defined( SVR4 ) || defined( SYSV ) || defined(__osf__) || defined(__FreeBSD__)
+#if defined( SVR4 ) || defined( SYSV ) || defined(__osf__) || defined(CSRG_BASED)
 static	int	chld_stat ;
 #else
 static	union	wait	chld_stat ;
