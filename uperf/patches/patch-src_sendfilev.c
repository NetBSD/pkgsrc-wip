$NetBSD$

Fake NetBSD support.

--- src/sendfilev.c.orig	2017-09-11 12:26:20.000000000 +0000
+++ src/sendfilev.c
@@ -159,7 +159,13 @@ sendfile_init(char *dir)
 	return (0);
 }
 
-#ifdef HAVE_SENDFILEV	/* Linux does not have sendfilev */
+#if defined(UPERF_NETBSD)
+static ssize_t
+do_sendfilev_chunked(sfv_list_t *s, int sock, int csize)
+{
+	return -1;
+}
+#elif defined(HAVE_SENDFILEV)	/* Linux does not have sendfilev */
 static ssize_t
 do_sendfilev_chunked(sfv_list_t *s, int sock, int csize)
 {
@@ -212,6 +218,13 @@ do_sendfilev(int sock, char *dir, int nf
 }
 #endif
 
+#if defined(UPERF_NETBSD)
+ssize_t
+do_sendfile(int sock, char *dir, int chunk_size)
+{
+	return -1;
+}
+#else
 ssize_t
 do_sendfile(int sock, char *dir, int chunk_size)
 {
@@ -265,6 +278,7 @@ do_sendfile(int sock, char *dir, int chu
 		return (s->flist[r].size);
 	}
 }
+#endif
 
 #ifdef MAIN
 int
