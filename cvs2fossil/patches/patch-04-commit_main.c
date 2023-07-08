$NetBSD$

Add missing header.

--- 04-commit/main.c.orig	2014-05-02 21:04:50.000000000 +0000
+++ 04-commit/main.c
@@ -8,6 +8,7 @@
 #include <string.h>
 #include <sqlite3.h>
 #include <time.h>
+#include <unistd.h>
 #include <zlib.h>
 
 #include <openssl/md5.h>
@@ -672,6 +673,7 @@ add_time(const char *input, char *output
 	strftime(output, output_len, "%Y-%m-%d %H:%M:%S", &tm);
 }
 
+static int merge_limit_seconds = 600;
 static struct buf *
 flush_manifest(struct buf *bp)
 {
@@ -688,7 +690,7 @@ flush_manifest(struct buf *bp)
 	bp = prepare_manifest((const char *)sqlite3_column_text(stmt, 3),
 	    date, (const char *)sqlite3_column_text(stmt, 1));
 
-	add_time(date, date_limit, sizeof(date_limit), 600);
+	add_time(date, date_limit, sizeof(date_limit), merge_limit_seconds);
 
 	++cur_commit;
 	return bp;
@@ -1019,7 +1021,7 @@ tracef(void *unused, const char *sql)
 static void
 usage(void)
 {
-	fprintf(stderr, "Usage: %s [-b 40-byte-hash] database repository\n",
+	fprintf(stderr, "Usage: %s [-b 40-byte-hash] [-l queue_limit] [-s merge_limit_seconds] database repository\n",
 	    getprogname());
 	exit(1);
 }
@@ -1066,7 +1068,7 @@ main(int argc, char **argv)
 	delta_stmt_thread = calloc(sizeof(*delta_stmt_thread), ncpu);
 	threads = calloc(sizeof(*threads), 2 * ncpu);
 
-	while ((ch = getopt(argc, argv, "b:l:")) != -1) {
+	while ((ch = getopt(argc, argv, "b:l:s:")) != -1) {
 		switch (ch) {
 		case 'b':
 			if (strlen(optarg) != 40)
@@ -1077,6 +1079,9 @@ main(int argc, char **argv)
 			compress_queue_limit = atoi(optarg);
 			delta_queue_limit = atoi(optarg);
 			break;
+		case 's':
+			merge_limit_seconds = atoi(optarg);
+			break;
 		default:
 			usage();
 		}
