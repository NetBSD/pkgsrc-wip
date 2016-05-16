$NetBSD: patch-src_slurmd_slurmstepd_task.c,v 1.2 2015/04/20 13:08:37 outpaddling Exp $

# Hack for Linux compat
--- src/slurmd/slurmstepd/task.c.orig	2015-03-19 19:38:01.000000000 +0000
+++ src/slurmd/slurmstepd/task.c
@@ -540,6 +540,17 @@ _make_tmpdir(stepd_step_rec_t *job)
 		 * still work with older systems we include this check.
 		 */
 
+/* FIXME: Come up with a real solution for EUID instead of substituting RUID */
+#if defined(__NetBSD__)
+#define eaccess(p,m) (access((p),(m)))
+#define HAVE_EACCESS 1
+#endif
+  
+#if defined(__FreeBSD__) || defined(__NetBSD__)
+#define __GLIBC__               (1) 
+#define __GLIBC_PREREQ(a,b)     (1) 
+#endif
+
 #if defined(HAVE_FACCESSAT)
 		else if (faccessat(AT_FDCWD, tmpdir, X_OK|W_OK, AT_EACCESS))
 #elif defined(HAVE_EACCESS)
