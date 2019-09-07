$NetBSD$

Rename queue to dma_queue because the struct is already defined in SunOS. 
Include strings.h for bzero and bcopy function.

--- mail.c.orig	2019-08-20 09:52:52.000000000 +0000
+++ mail.c
@@ -46,7 +46,7 @@
 void
 bounce(struct qitem *it, const char *reason)
 {
-	struct queue bounceq;
+	struct dma_queue bounceq;
 	char line[1000];
 	size_t pos;
 	int error;
@@ -162,7 +162,7 @@ struct parse_state {
  * XXX local addresses will need treatment
  */
 static int
-parse_addrs(struct parse_state *ps, char *s, struct queue *queue)
+parse_addrs(struct parse_state *ps, char *s, struct dma_queue *queue)
 {
 	char *addr;
 
@@ -344,7 +344,7 @@ newaddr:
 }
 
 int
-readmail(struct queue *queue, int nodot, int recp_from_header)
+readmail(struct dma_queue *queue, int nodot, int recp_from_header)
 {
 	struct parse_state parse_state;
 	char line[1000];	/* by RFC2822 */
