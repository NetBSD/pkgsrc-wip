$NetBSD$

* Add support to NetBSD and FreeBSD
* Use heimdal on NetBSD, heimdal has krb5_get_err_text()

--- node_modules/kerberos/src/unix/kerberos_gss.cc.orig	2026-10-30 16:03:08.319215758 +0000
+++ node_modules/kerberos/src/unix/kerberos_gss.cc
@@ -65,10 +65,17 @@ struct DLOpenHandle {
   DLOpenHandle& operator=(DLOpenHandle&) = delete;
 };
 
+#ifndef __FreeBSD__
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
@@ -120,9 +127,11 @@ bool kerberos_libraries_available(std::s
 
 namespace node_kerberos {
 
+#if !defined(__NetBSD__)
 const char* krb5_get_err_text(const krb5_context&, krb5_error_code code) {
     return COMERR_CALL(error_message)(code);
 }
+#endif
 
 static gss_result gss_success_result(int ret);
 static gss_result gss_error_result(OM_uint32 err_maj, OM_uint32 err_min);
@@ -138,7 +147,12 @@ gss_result server_principal_details(cons
     int code;
     krb5_context kcontext;
     krb5_keytab kt = NULL;
+#if defined(__NetBSD__)
+    krb5_kt_cursor cursor;
+    bool cursor_open = false;
+#else
     krb5_kt_cursor cursor = NULL;
+#endif
     krb5_keytab_entry entry;
     char* pname = NULL;
 
@@ -162,6 +176,10 @@ gss_result server_principal_details(cons
         result =
             gss_error_result_with_message_and_code("Cannot get sequence cursor from keytab", code);
         goto end;
+#if defined(__NetBSD__)
+    } else {
+       cursor_open = true;
+#endif
     }
 
     while ((code = KRB5_CALL(krb5_kt_next_entry)(kcontext, kt, &entry, &cursor)) == 0) {
@@ -189,7 +207,11 @@ gss_result server_principal_details(cons
         result.data = std::move(details);
     }
 end:
+#if defined(__NetBSD__)
+    if (cursor_open)
+#else
     if (cursor)
+#endif
         KRB5_CALL(krb5_kt_end_seq_get)(kcontext, kt, &cursor);
     if (kt)
         KRB5_CALL(krb5_kt_close)(kcontext, kt);
@@ -698,6 +720,7 @@ gss_result authenticate_user_krb5pwd(con
     gss_result result {};
     int ret = 0;
     char* name = NULL;
+    const char* text = NULL;
     char* p = NULL;
 
     // for verify
@@ -715,13 +738,15 @@ gss_result authenticate_user_krb5pwd(con
 
     ret = KRB5_CALL(krb5_parse_name)(kcontext, service, &server);
     if (ret) {
-        result = gss_error_result_with_message_and_code(krb5_get_err_text(kcontext, ret), ret);
+        text = krb5_get_err_text(kcontext, ret);
+        result = gss_error_result_with_message_and_code(text ? text : "Unknown Kerberos5 error", ret);
         goto end;
     }
 
     code = KRB5_CALL(krb5_unparse_name)(kcontext, server, &name);
     if (code) {
-        result = gss_error_result_with_message_and_code(krb5_get_err_text(kcontext, code), code);
+        text = krb5_get_err_text(kcontext, code);
+        result = gss_error_result_with_message_and_code(text ? text : "Unknown Kerberos5 error", code);
         goto end;
     }
 
@@ -742,7 +767,8 @@ gss_result authenticate_user_krb5pwd(con
 
     code = KRB5_CALL(krb5_parse_name)(kcontext, name, &client);
     if (code) {
-        result = gss_error_result_with_message_and_code(krb5_get_err_text(kcontext, code), code);
+        text = krb5_get_err_text(kcontext, code);
+        result = gss_error_result_with_message_and_code(text ? text : "Unknown Kerberos5 error", code);
         goto end;
     }
 
@@ -758,8 +784,8 @@ gss_result authenticate_user_krb5pwd(con
     verifyRet = KRB5_CALL(krb5_get_init_creds_password)(
         kcontext, &creds, client, (char*)pswd, NULL, NULL, 0, NULL, &gic_options);
     if (verifyRet) {
-        result = gss_error_result_with_message_and_code(krb5_get_err_text(kcontext, verifyRet),
-                                                        verifyRet);
+        text = krb5_get_err_text(kcontext, verifyRet);
+        result = gss_error_result_with_message_and_code(text ? text : "Unknown Kerberos5 error", verifyRet);
         KRB5_CALL(krb5_free_cred_contents)(kcontext, &creds);
         goto end;
     }
@@ -777,6 +803,11 @@ end:
     if (server) {
         KRB5_CALL(krb5_free_principal)(kcontext, server);
     }
+#if defined(__NetBSD__)
+    if (text) {
+        krb5_free_error_message(kcontext, text);
+    }
+#endif
     KRB5_CALL(krb5_free_context)(kcontext);
 
     return result;
