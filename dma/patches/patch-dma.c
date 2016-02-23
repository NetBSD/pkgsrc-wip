$NetBSD$

Rename queue to dma_queue because the struct is already defined in SunOS.

--- dma.c.orig	2016-02-07 12:41:49.000000000 +0000
+++ dma.c
@@ -54,6 +54,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <strings.h>
 #include <syslog.h>
 #include <unistd.h>
 
@@ -94,7 +95,7 @@ sighup_handler(int signo)
 }
 
 static char *
-set_from(struct queue *queue, const char *osender)
+set_from(struct dma_queue *queue, const char *osender)
 {
 	const char *addr;
 	char *sender;
@@ -153,7 +154,7 @@ read_aliases(void)
 }
 
 static int
-do_alias(struct queue *queue, const char *addr)
+do_alias(struct dma_queue *queue, const char *addr)
 {
 	struct alias *al;
         struct stritem *sit;
@@ -173,7 +174,7 @@ do_alias(struct queue *queue, const char
 }
 
 int
-add_recp(struct queue *queue, const char *str, int expand)
+add_recp(struct dma_queue *queue, const char *str, int expand)
 {
 	struct qitem *it, *tit;
 	struct passwd *pw;
@@ -240,7 +241,7 @@ out:
 }
 
 static struct qitem *
-go_background(struct queue *queue)
+go_background(struct dma_queue *queue)
 {
 	struct sigaction sa;
 	struct qitem *it;
@@ -372,7 +373,7 @@ bounce:
 }
 
 void
-run_queue(struct queue *queue)
+run_queue(struct dma_queue *queue)
 {
 	struct qitem *it;
 
@@ -385,7 +386,7 @@ run_queue(struct queue *queue)
 }
 
 static void
-show_queue(struct queue *queue)
+show_queue(struct dma_queue *queue)
 {
 	struct qitem *it;
 	int locked = 0;	/* XXX */
@@ -421,7 +422,7 @@ main(int argc, char **argv)
 {
 	struct sigaction act;
 	char *sender = NULL;
-	struct queue queue;
+	struct dma_queue queue;
 	int i, ch;
 	int nodot = 0, showq = 0, queue_only = 0;
 	int recp_from_header = 0;
