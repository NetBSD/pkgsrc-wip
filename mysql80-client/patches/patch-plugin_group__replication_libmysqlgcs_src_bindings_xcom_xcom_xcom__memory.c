$NetBSD$

workaround netbsd prototype of xdrproc_t being 2 arguments.

--- plugin/group_replication/libmysqlgcs/src/bindings/xcom/xcom/xcom_memory.c.orig	2019-12-09 19:53:17.000000000 +0000
+++ plugin/group_replication/libmysqlgcs/src/bindings/xcom/xcom/xcom_memory.c
@@ -50,7 +50,14 @@ void my_xdr_free(xdrproc_t proc, char *o
     is the case). This will keep this code cross-platform
     and cross-version compatible.
   */
+#ifdef __NetBSD__
+  /* NetBSD doesn't have variadic xdrproc_t...
+   * see https://bugzilla.redhat.com/show_bug.cgi?is=1128820#c24
+   * for a similar problem */
+  (*proc)(&x, objp);
+#else
   (*proc)(&x, objp, 0);
+#endif
 }
 
 void xcom_xdr_free(xdrproc_t f, char *p) {
