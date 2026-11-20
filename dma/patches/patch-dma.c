$NetBSD$

Rename queue to dma_queue because the struct is already defined in SunOS.

Use st_mtime for the queue timeout on macOS.

--- dma.c.orig	2016-02-07 12:41:49.000000000 +0000
+++ dma.c
@@ -55,6 +55,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <strings.h>
 #include <syslog.h>
 #include <unistd.h>
 
@@ -96,7 +97,7 @@
 }
 
 static char *
-set_from(struct queue *queue, const char *osender)
+set_from(struct dma_queue *queue, const char *osender)
 {
 	const char *addr;
 	const char *from_user = NULL;
@@ -181,7 +182,7 @@
 }
 
 static int
-do_alias(struct queue *queue, const char *addr)
+do_alias(struct dma_queue *queue, const char *addr)
 {
 	struct alias *al;
         struct stritem *sit;
@@ -201,7 +202,7 @@
 }
 
 int
-add_recp(struct queue *queue, const char *str, int expand)
+add_recp(struct dma_queue *queue, const char *str, int expand)
 {
 	struct qitem *it, *tit;
 	struct passwd *pw;
@@ -268,7 +269,7 @@
 }
 
 static struct qitem *
-go_background(struct queue *queue)
+go_background(struct dma_queue *queue)
 {
 	struct sigaction sa;
 	struct qitem *it;
@@ -368,7 +369,7 @@
 			exit(EX_SOFTWARE);
 		}
 		if (gettimeofday(&now, NULL) == 0 &&
-		    (now.tv_sec - st.st_mtim.tv_sec > MAX_TIMEOUT)) {
+		    (now.tv_sec - st.st_mtime > MAX_TIMEOUT)) {
 			snprintf(errmsg, sizeof(errmsg),
 				 "Could not deliver for the last %d seconds. Giving up.",
 				 MAX_TIMEOUT);
@@ -400,7 +401,7 @@
 }
 
 void
-run_queue(struct queue *queue)
+run_queue(struct dma_queue *queue)
 {
 	struct qitem *it;
 
@@ -413,7 +414,7 @@
 }
 
 static void
-show_queue(struct queue *queue)
+show_queue(struct dma_queue *queue)
 {
 	struct qitem *it;
 	int locked = 0;	/* XXX */
@@ -450,7 +451,7 @@
 	struct sigaction act;
 	char *sender = NULL;
 	char *own_name = NULL;
-	struct queue queue;
+	struct dma_queue queue;
 	int i, ch;
 	int nodot = 0, showq = 0, queue_only = 0, newaliases = 0;
 	int recp_from_header = 0;
