$NetBSD$

--- gum/backend-netbsd/gumnetbsd.h.orig	2018-03-15 03:53:19.210983649 +0000
+++ gum/backend-netbsd/gumnetbsd.h
@@ -0,0 +1,29 @@
+/*
+ * Copyright (C) 2012-2015 Ole André Vadla Ravnås <ole.andre.ravnas@tillitech.com>
+ *
+ * Licence: wxWindows Library Licence, Version 3.1
+ */
+
+#ifndef __GUM_NETBSD_H__
+#define __GUM_NETBSD_H__
+
+#include "gumprocess.h"
+
+#include <ucontext.h>
+
+G_BEGIN_DECLS
+
+GUM_API GumCpuType gum_netbsd_cpu_type_from_file (const gchar * path,
+    GError ** error);
+GUM_API GumCpuType gum_netbsd_cpu_type_from_pid (pid_t pid, GError ** error);
+GUM_API void gum_netbsd_enumerate_ranges (pid_t pid, GumPageProtection prot,
+    GumFoundRangeFunc func, gpointer user_data);
+
+GUM_API void gum_netbsd_parse_ucontext (const ucontext_t * uc,
+    GumCpuContext * ctx);
+GUM_API void gum_netbsd_unparse_ucontext (const GumCpuContext * ctx,
+    ucontext_t * uc);
+
+G_END_DECLS
+
+#endif
