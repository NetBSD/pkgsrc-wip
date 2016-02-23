$NetBSD$

Rename queue to dma_queue because the struct is already defined in SunOS. 

--- spool.c.orig	2016-02-07 12:41:49.000000000 +0000
+++ spool.c
@@ -46,6 +46,7 @@
 #include <inttypes.h>
 #include <unistd.h>
 #include <syslog.h>
+#include <strings.h>
 
 #include "dma.h"
 
@@ -69,7 +70,7 @@
  */
 
 int
-newspoolf(struct queue *queue)
+newspoolf(struct dma_queue *queue)
 {
 	char fn[PATH_MAX+1];
 	struct stat st;
@@ -151,10 +152,10 @@ writequeuef(struct qitem *it)
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
@@ -229,7 +230,7 @@ out:
 }
 
 int
-linkspool(struct queue *queue)
+linkspool(struct dma_queue *queue)
 {
 	struct stat st;
 	struct qitem *it;
@@ -276,7 +277,7 @@ delfiles:
 }
 
 int
-load_queue(struct queue *queue)
+load_queue(struct dma_queue *queue)
 {
 	struct stat sb;
 	struct qitem *it;
@@ -382,7 +383,7 @@ fail:
 }
 
 void
-dropspool(struct queue *queue, struct qitem *keep)
+dropspool(struct dma_queue *queue, struct qitem *keep)
 {
 	struct qitem *it;
 
