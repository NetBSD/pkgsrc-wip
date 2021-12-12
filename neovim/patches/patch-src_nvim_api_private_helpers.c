$NetBSD$

--- src/nvim/api/private/helpers.c.orig	2021-11-30 17:20:42.000000000 +0000
+++ src/nvim/api/private/helpers.c
@@ -513,7 +513,7 @@ String cbuf_to_string(const char *buf, s
 String cstrn_to_string(const char *str, size_t maxsize)
   FUNC_ATTR_NONNULL_ALL
 {
-  return cbuf_to_string(str, strnlen(str, maxsize));
+  return cbuf_to_string(str, STRNLEN(str, maxsize));
 }
 
 /// Creates a String using the given C string. Unlike
