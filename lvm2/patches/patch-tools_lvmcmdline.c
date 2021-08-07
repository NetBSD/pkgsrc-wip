$NetBSD$

Guard GNU libc-ism (assignable stdin/stdout/stderr).

--- tools/lvmcmdline.c.orig	2021-05-07 21:14:09.000000000 +0000
+++ tools/lvmcmdline.c
@@ -3341,6 +3341,7 @@ static int _check_standard_fds(void)
 {
 	int err = is_valid_fd(STDERR_FILENO);
 
+#ifdef __GNU_LIBARY__	/* on glibc std* are assignable */
 	if (!is_valid_fd(STDIN_FILENO) &&
 	    !(stdin = fopen(_PATH_DEVNULL, "r"))) {
 		if (err)
@@ -3365,6 +3366,14 @@ static int _check_standard_fds(void)
 		       strerror(errno));
 		return 0;
 	}
+#else
+	if (!is_valid_fd(STDIN_FILENO))
+		return 0;
+	if (!is_valid_fd(STDOUT_FILENO))
+		return 0;
+	if (!is_valid_fd(STDERR_FILENO))
+		return 0;
+#endif
 
 	return 1;
 }
