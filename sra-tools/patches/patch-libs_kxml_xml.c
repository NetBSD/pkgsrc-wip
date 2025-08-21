$NetBSD$

# Unbreak build with libxml 2.14

--- libs/kxml/xml.c.orig	2025-08-21 12:03:05.217095244 +0000
+++ libs/kxml/xml.c
@@ -171,7 +171,7 @@ rc_t KXMLMgrSchemaValidate ( const KXMLM
 }
 #endif
 
-static void s_xmlGenericErrorDefaultFunc(void *ctx ATTRIBUTE_UNUSED,
+static void s_xmlGenericErrorDefaultFunc(void *ctx,
     const char *msg,
     ...)
 {
