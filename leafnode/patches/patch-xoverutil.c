$NetBSD$

Accept EEXIST response the same as ENOTEMPTY for rmdir().

--- xoverutil.c.orig	2009-01-30 15:02:52.000000000 +0000
+++ xoverutil.c
@@ -386,7 +386,7 @@ static void killcwd(void) {
 	if (chdir(spooldir)) {
 	    ln_log(LNLOG_SERR, LNLOG_CTOP, "error: cannot chdir(%s): %m", spooldir);
 	}
-	if (rmdir(t) && errno != ENOTEMPTY) {
+	if (rmdir(t) && errno != ENOTEMPTY && errno != EEXIST) {
 	    ln_log(LNLOG_SERR, LNLOG_CTOP, "error: cannot rmdir(%s): %m", t);
 	}
 	free(t);
