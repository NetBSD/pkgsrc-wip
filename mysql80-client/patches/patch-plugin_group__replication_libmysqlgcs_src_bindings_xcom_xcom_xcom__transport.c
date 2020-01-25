$NetBSD$

workaround netbsd prototype of xdrproc_t being 2 arguments.

--- plugin/group_replication/libmysqlgcs/src/bindings/xcom/xcom/xcom_transport.c.orig	2019-12-09 19:53:17.000000000 +0000
+++ plugin/group_replication/libmysqlgcs/src/bindings/xcom/xcom/xcom_transport.c
@@ -383,7 +383,11 @@ int apply_xdr(xcom_proto x_proto, void *
   if (xdr.x_ops) {
     xdr.x_public =
         (caddr_t)&x_proto; /* Supply protocol version in user field of xdr */
+#ifdef __NetBSD__
+    s = xdrfunc(&xdr, xdrdata);
+#else
     s = xdrfunc(&xdr, xdrdata, 0);
+#endif
   }
   xdr_destroy(&xdr);
   return s;
@@ -595,7 +599,11 @@ static uint64_t xdr_proto_sizeof(xcom_pr
     is the case). This will keep this code cross-platform
     and cross-version compatible.
   */
+#ifdef __NetBSD__
+  stat = func(&x, data);
+#else
   stat = func(&x, data, 0);
+#endif
   free(x.x_private);
   // x_handy is int type for old XDR
   return stat == TRUE ? (uint64_t)x.x_handy : 0;
