$NetBSD: patch-src_util_xmlconfig.c,v 1.1 2018/10/07 23:49:31 ryoon Exp $

PR pkg/50202.
Provide compat strndup for older Darwin.

--- src/util/xmlconfig.c.orig	2019-03-05 18:53:12.177053000 +0000
+++ src/util/xmlconfig.c
@@ -47,6 +47,24 @@
 #define PATH_MAX 4096
 #endif
 
+#if (defined(__APPLE__) && __ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__-0 < 1070)
+static char *
+strndup(const char *str, size_t n)
+{
+    size_t len;
+    char *copy;
+
+    for (len = 0; len < n && str[len]; len++)
+        continue;
+
+    if ((copy = (char *)malloc(len + 1)) == NULL)
+        return (NULL);
+    memcpy(copy, str, len);
+    copy[len] = '\0';
+    return (copy);
+}
+#endif
+
 /** \brief Find an option in an option cache with the name as key */
 static uint32_t
 findOption(const driOptionCache *cache, const char *name)
