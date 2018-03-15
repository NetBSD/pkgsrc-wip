$NetBSD$

--- gum/backend-netbsd/gummemory-netbsd.c.orig	2018-03-15 03:53:19.204426671 +0000
+++ gum/backend-netbsd/gummemory-netbsd.c
@@ -0,0 +1,71 @@
+/*
+ * Copyright (C) 2008-2011 Ole André Vadla Ravnås <ole.andre.ravnas@tillitech.com>
+ *
+ * Licence: wxWindows Library Licence, Version 3.1
+ */
+
+#include "gummemory.h"
+
+#include "gummemory-priv.h"
+//#include "valgrind.h"
+
+#include <stdio.h>
+#include <string.h>
+#include <sys/mman.h>
+#include <unistd.h>
+
+static gboolean gum_memory_get_protection (GumAddress address, gsize n,
+    gsize * size, GumPageProtection * prot);
+
+gboolean
+gum_memory_is_readable (GumAddress address,
+                        gsize len)
+{
+  return FALSE;
+}
+
+static gboolean
+gum_memory_is_writable (GumAddress address,
+                        gsize len)
+{
+  return FALSE;
+}
+
+guint8 *
+gum_memory_read (GumAddress address,
+                 gsize len,
+                 gsize * n_bytes_read)
+{
+  return NULL;
+}
+
+gboolean
+gum_memory_write (GumAddress address,
+                  const guint8 * bytes,
+                  gsize len)
+{
+  return FALSE;
+}
+
+gboolean
+gum_try_mprotect (gpointer address,
+                  gsize size,
+                  GumPageProtection page_prot)
+{
+  return FALSE;
+}
+
+void
+gum_clear_cache (gpointer address,
+                 gsize size)
+{
+}
+
+static gboolean
+gum_memory_get_protection (GumAddress address,
+                           gsize n,
+                           gsize * size,
+                           GumPageProtection * prot)
+{
+  return FALSE;
+}
