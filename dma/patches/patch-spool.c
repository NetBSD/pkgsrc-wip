$NetBSD$

Rename queue to dma_queue because the struct is already defined in SunOS.

Use st_mtime for the flush interval on macOS.

--- spool.c.orig	2019-08-20 09:52:52.000000000 +0000
+++ spool.c
@@ -72,7 +72,7 @@
  */
 
 int
-newspoolf(struct queue *queue)
+newspoolf(struct dma_queue *queue)
 {
 	char fn[PATH_MAX+1];
 	struct stat st;
@@ -154,10 +154,10 @@
 }
 
 static struct qitem *
-readqueuef(struct queue *queue, char *queuefn)
+readqueuef(struct dma_queue *queue, char *queuefn)
 {
 	char line[1000];
-	struct queue itmqueue;
+	struct dma_queue itmqueue;
 	FILE *queuef = NULL;
 	char *s;
 	char *queueid = NULL, *sender = NULL, *addr = NULL;
@@ -232,7 +232,7 @@
 }
 
 int
-linkspool(struct queue *queue)
+linkspool(struct dma_queue *queue)
 {
 	struct stat st;
 	struct qitem *it;
@@ -279,7 +279,7 @@
 }
 
 int
-load_queue(struct queue *queue)
+load_queue(struct dma_queue *queue)
 {
 	struct stat sb;
 	struct qitem *it;
@@ -385,7 +385,7 @@
 }
 
 void
-dropspool(struct queue *queue, struct qitem *keep)
+dropspool(struct dma_queue *queue, struct qitem *keep)
 {
 	struct qitem *it;
 
@@ -419,7 +419,7 @@
 		return (0);
 
 	/* Did the flush file get touched within the last period seconds? */
-	if (st.st_mtim.tv_sec + period >= now.tv_sec)
+	if (st.st_mtime + period >= now.tv_sec)
 		return (1);
 	else
 		return (0);
