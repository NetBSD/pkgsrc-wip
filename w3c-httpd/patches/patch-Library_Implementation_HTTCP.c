$NetBSD$

Our includes have that.

--- Library/Implementation/HTTCP.c.orig	1996-06-21 15:47:26.000000000 +0000
+++ Library/Implementation/HTTCP.c
@@ -117,8 +117,8 @@ extern int errno;
 #ifndef VMS
 #ifndef NeXT
 #ifndef THINK_C
-extern char *sys_errlist[];		/* see man perror on cernvax */
-extern int sys_nerr;
+/*extern char *sys_errlist[];*/		/* see man perror on cernvax */
+/*extern int sys_nerr;*/
 #endif  /* think c */
 #endif	/* NeXT */
 #endif  /* VMS */
