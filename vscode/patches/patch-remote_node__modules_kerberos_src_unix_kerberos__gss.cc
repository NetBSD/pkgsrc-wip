$NetBSD$

* Add support to NetBSD and FreeBSD

--- remote/node_modules/kerberos/src/unix/kerberos_gss.cc.orig	2026-10-24 14:37:41.000000000 +0000
+++ remote/node_modules/kerberos/src/unix/kerberos_gss.cc
@@ -65,10 +65,17 @@ struct DLOpenHandle {
   DLOpenHandle& operator=(DLOpenHandle&) = delete;
 };
 
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 #define DYLIBS(V) \
     V(gssapi, "libgssapi_krb5.so.2") \
     V(krb5, "libkrb5.so.3") \
     V(comerr, "libcom_err.so.2")
+#else
+#define DYLIBS(V) \
+    V(gssapi, "libgssapi_krb5.so.2") \
+    V(krb5, "libkrb5.so.3") \
+    V(comerr, "libcom_err.so.3")
+#endif
 
 #define LIBRARY_HANDLE_GETTER(name, lib) \
     static const DLOpenHandle& name ## _handle() { \
