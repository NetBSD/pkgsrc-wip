$NetBSD$

--- src/Native/System.Net.Security.Native/pal_gssapi.h.orig	2016-05-03 12:05:51.000000000 +0000
+++ src/Native/System.Net.Security.Native/pal_gssapi.h
@@ -4,7 +4,7 @@
 
 #pragma once
 
-#if HAVE_GSSFW_HEADERS
+#if HAVE_GSSFW_HEADERS || HAVE_HEIMDAL_HEADERS
 typedef struct gss_name_t_desc_struct GssName;
 typedef struct gss_ctx_id_t_desc_struct GssCtxId;
 typedef struct gss_cred_id_t_desc_struct GssCredId;
