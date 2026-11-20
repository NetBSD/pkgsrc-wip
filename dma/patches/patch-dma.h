$NetBSD$

Rename queue to dma_queue because the struct is already defined in SunOS.

Use NS_MAXDNAME for macOS compatibility.

--- dma.h.orig	2016-02-07 12:41:49.000000000 +0000
+++ dma.h
@@ -120,7 +120,7 @@
 };
 LIST_HEAD(queueh, qitem);
 
-struct queue {
+struct dma_queue {
 	struct queueh queue;
 	char *id;
 	FILE *mailf;
@@ -156,7 +156,7 @@
 
 
 struct mx_hostentry {
-	char		host[MAXDNAME];
+	char		host[NS_MAXDNAME];
 	char		addr[INET6_ADDRSTRLEN];
 	int		pref;
 	struct addrinfo	ai;
@@ -218,16 +218,16 @@
 /* dma.c */
 #define EXPAND_ADDR	1
 #define EXPAND_WILDCARD	2
-int add_recp(struct queue *, const char *, int);
-void run_queue(struct queue *);
+int add_recp(struct dma_queue *, const char *, int);
+void run_queue(struct dma_queue *);
 
 /* spool.c */
-int newspoolf(struct queue *);
-int linkspool(struct queue *);
-int load_queue(struct queue *);
+int newspoolf(struct dma_queue *);
+int linkspool(struct dma_queue *);
+int load_queue(struct dma_queue *);
 void delqueue(struct qitem *);
 int acquirespool(struct qitem *);
-void dropspool(struct queue *, struct qitem *);
+void dropspool(struct dma_queue *, struct qitem *);
 int flushqueue_since(unsigned int);
 int flushqueue_signal(void);
 
@@ -236,7 +236,7 @@
 
 /* mail.c */
 void bounce(struct qitem *, const char *);
-int readmail(struct queue *, int, int);
+int readmail(struct dma_queue *, int, int);
 
 /* util.c */
 const char *hostname(void);
