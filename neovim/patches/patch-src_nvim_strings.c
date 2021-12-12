$NetBSD$

--- src/nvim/strings.c.orig	2021-12-11 11:25:29.501010627 +0000
+++ src/nvim/strings.c
@@ -394,6 +394,18 @@ void del_trailing_spaces(char_u *ptr)
   }
 }
 
+#if !defined(HAVE_STRNLEN)
+size_t xstrnlen(const char *s, size_t n)
+  FUNC_ATTR_NONNULL_ALL FUNC_ATTR_PURE
+{
+  const char *end = memchr(s, '\0', n);
+  if (end == NULL) {
+    return n;
+  }
+  return end - s;
+}
+#endif
+
 #if (!defined(HAVE_STRCASECMP) && !defined(HAVE_STRICMP))
 /*
  * Compare two strings, ignoring case, using current locale.
