$NetBSD: patch-src_mesa_drivers_dri_common_xmlconfig.c,v 1.3 2016/02/23 11:16:55 jperkin Exp $

PR pkg/50202.
Provide compat strndup for older Darwin.

Remove patches for FreeBSD and DragonFly since code covers those cases.

--- src/util/xmlconfig.c.orig	2017-12-21 17:31:22.000000000 +0000
+++ src/util/xmlconfig.c
@@ -113,6 +113,24 @@ __getProgramName()
 #    endif
 #endif
 
+#if (defined(__APPLE__) && __ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__-0 < 1070)
+static char *
+strndup(const char *str, size_t n)
+{
+  size_t len;
+  char *copy;
+
+  for (len = 0; len < n && str[len]; len++)
+    continue;
+
+  if ((copy = (char *)malloc(len + 1)) == NULL)
+    return (NULL);
+  memcpy(copy, str, len);
+  copy[len] = '\0';
+  return (copy);
+}
+#endif
+
 /** \brief Find an option in an option cache with the name as key */
 static uint32_t
 findOption(const driOptionCache *cache, const char *name)
