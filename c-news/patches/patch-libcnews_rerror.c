$NetBSD: patch-libcnews_rerror.c,v 1.1 2011/06/09 16:22:57 hfath Exp $

Resolve conflict with math.h::log() by renaming log() to cnews_log().
GC 'register'.

--- libcnews/rerror.c.orig	1994-09-19 03:26:08.000000000 +0000
+++ libcnews/rerror.c
@@ -19,12 +19,12 @@
 
 /* common log reporting */
 static
-log(stream, art, code, fmt, arg, sverrno)
-register FILE *stream;
-register struct article *art;
+cnews_log(stream, art, code, fmt, arg, sverrno)
+FILE *stream;
+struct article *art;
 int code;
 char *fmt, *arg;
-register int sverrno;
+int sverrno;
 {
 	time_t now;
 
@@ -60,7 +60,7 @@ struct article *art;
 int code;
 char *fmt, *arg;
 {
-	log(stdout, art, code, fmt, arg, 0);
+	cnews_log(stdout, art, code, fmt, arg, 0);
 }
 
 /*
@@ -68,11 +68,11 @@ char *fmt, *arg;
  * set ST_REFUSED in article status
  */
 transient(art, code, fmt, arg)
-register struct article *art;
+struct article *art;
 int code;
 char *fmt, *arg;
 {
-	log(stdout, art, code, fmt, arg, 0);
+	cnews_log(stdout, art, code, fmt, arg, 0);
 	if (art != NULL)
 		art->a_status |= ST_REFUSED;
 }
@@ -82,11 +82,11 @@ char *fmt, *arg;
  * sets ST_NEEDATTN and ST_DROPPED in article status
  */
 persistent(art, code, fmt, arg)
-register struct article *art;
+struct article *art;
 int code;
 char *fmt, *arg;
 {
-	log(stderr, art, code, fmt, arg, errno);
+	cnews_log(stderr, art, code, fmt, arg, errno);
 	if (art != NULL)
 		art->a_status |= ST_NEEDATTN|ST_DROPPED;
 }
@@ -107,7 +107,7 @@ char *fmt, *arg;
 
 void
 fulldisk(art, file)			/* complain once & set status bits */
-register struct article *art;
+struct article *art;
 char *file;
 {
 	if (!(art->a_status&ST_DISKFULL))
