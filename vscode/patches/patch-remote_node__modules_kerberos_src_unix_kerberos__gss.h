$NetBSD$

* Use heimdal on NetBSD, heimdal has krb5_get_err_text()

--- remote/node_modules/kerberos/src/unix/kerberos_gss.h.orig	2026-10-30 17:20:19.388982698 +0000
+++ remote/node_modules/kerberos/src/unix/kerberos_gss.h
@@ -19,15 +19,33 @@
 
 extern "C" {
     #include <gssapi/gssapi.h>
+#if defined(__NetBSD__)
+    #include <krb5.h>
+    #include <com_err.h>
+#else
     #include <gssapi/gssapi_generic.h>
+#endif
     #include <gssapi/gssapi_krb5.h>
 }
 
+#if defined(__NetBSD__)
+/* MIT-only names, Heimdal equivalents */
+#ifndef gss_nt_service_name
+#define gss_nt_service_name GSS_C_NT_HOSTBASED_SERVICE
+#endif
+#ifndef krb5_free_keytab_entry_contents
+#define krb5_free_keytab_entry_contents krb5_kt_free_entry
+#endif
+#define krb5_get_err_text krb5_get_error_message
+#endif
+
 #include <string>
 
 namespace node_kerberos {
 
+#if !defined(__NetBSD__)
 const char* krb5_get_err_text(const krb5_context&, krb5_error_code code);
+#endif
 
 #define AUTH_GSS_ERROR -1
 #define AUTH_GSS_COMPLETE 1
