$NetBSD$

NetBSD only supports zero-initialized initial-exec tls variables in conjuction
with dlopen(3) at the moment.

--- src/mapi/u_current.c.orig	2021-07-14 20:04:57.831030400 +0000
+++ src/mapi/u_current.c
@@ -107,7 +107,11 @@ __declspec(thread) void *u_current_conte
 #else
 __thread struct _glapi_table *u_current_table
     __attribute__((tls_model("initial-exec")))
+#if defined(__NetBSD__)
+    = NULL; /* non-zero initializers not supported with dlopen */
+#else
     = (struct _glapi_table *) table_noop_array;
+#endif
 
 __thread void *u_current_context
     __attribute__((tls_model("initial-exec")));
@@ -259,7 +263,11 @@ struct _glapi_table *
 u_current_get_table_internal(void)
 {
 #if defined(USE_ELF_TLS)
+#  if defined(__NetBSD__)
+    return (likely(u_current_table) ? u_current_table : (struct _glapi_table *) table_noop_array);
+#  else
    return u_current_table;
+#  endif
 #else
    if (ThreadSafe)
       return (struct _glapi_table *) tss_get(u_current_table_tsd);
