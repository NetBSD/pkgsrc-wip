$NetBSD$

setresuid/setresguid are not supported on NetBSD.
Do not hard code config file path.

--- doas.c.orig	2020-11-01 09:47:52.740280363 +0000
+++ doas.c
@@ -34,6 +34,11 @@
 #include "includes.h"
 #include "doas.h"
 
+#ifdef __netbsd__
+#define setresgid(a, b, c)	setgid(a)
+#define setresuid(a, b, c)	setuid(a)
+#endif
+
 static void __dead
 usage(void)
 {
@@ -325,7 +330,7 @@ main(int argc, char **argv)
 	if (geteuid())
 		errx(1, "not installed setuid");
 
-	parseconfig("/etc/doas.conf", 1);
+	parseconfig(DOAS_CONF, 1);
 
 	/* cmdline is used only for logging, no need to abort on truncate */
 	(void)strlcpy(cmdline, argv[0], sizeof(cmdline));
