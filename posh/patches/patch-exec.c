$NetBSD$

The usage of "optind = 0" is undefined behaviour according to POSIX.
Use it only for GNU getopt() and provide a portable replacement.

--- exec.c.orig	2013-05-31 01:14:12.000000000 +0000
+++ exec.c
@@ -413,10 +413,14 @@ comexec(struct op *t, struct tbl *volati
 	while (*arg++)
 		++noargc;
 
+#if PKGSRC_GNU_GETOPT
 	/* We need to set optind to 0 or else +p won't work */
 	optind = 0;
 
 	while ((optc = getopt(noargc, ap, "+p")) != -1) {
+#else  /* PKGSRC_GNU_GETOPT */
+	while ((optc = getopt(noargc, ap, "p")) != -1) {
+#endif  /* PKGSRC_GNU_GETOPT */
 		switch (optc) {
 		case 'p':
 			saw_p = 1;
