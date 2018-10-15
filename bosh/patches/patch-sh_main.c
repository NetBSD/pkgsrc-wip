$NetBSD$

Ensure that setlocale is called on systems without "/usr/lib/locale".

--- sh/main.c.orig	2018-07-31 22:00:57.000000000 +0000
+++ sh/main.c
@@ -138,10 +138,17 @@ main(c, v, e)
 	mypgid = getpgid(mypid);	/* get process group for this shell */
 	mysid = getsid(mypid);		/* get process group id of leader */
 
+#if	defined(IS_SUN) || defined(DO_SPLIT_ROOT)
 	/*
 	 * Do locale processing only if /usr is mounted.
+	 * This is to help the single user shell to work.
+	 * Since localedir may not be the same for all target architectures
+	 * we just disable this check for a non-Solaris environment.
 	 */
 	localedir_exists = (access(localedir, F_OK) == 0);
+#else
+	localedir_exists = TRUE;
+#endif
 
 	/*
 	 * initialize storage allocation
