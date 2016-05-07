$NetBSD$

--- src/Native/System.Net.Security.Native/pal_gssapi.cpp.orig	2016-05-03 12:05:51.000000000 +0000
+++ src/Native/System.Net.Security.Native/pal_gssapi.cpp
@@ -9,9 +9,14 @@
 #if HAVE_GSSFW_HEADERS
 #include <GSS/GSS.h>
 #else
+#if HAVE_HEIMDAL_HEADERS
+#include <gssapi/gssapi.h>
+#include <gssapi/gssapi_krb5.h>
+#else
 #include <gssapi/gssapi_ext.h>
 #include <gssapi/gssapi_krb5.h>
 #endif
+#endif
 
 #include <assert.h>
 #include <string.h>
