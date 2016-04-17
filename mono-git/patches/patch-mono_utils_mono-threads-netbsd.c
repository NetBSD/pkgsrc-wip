$NetBSD$

--- mono/utils/mono-threads-netbsd.c.orig	2016-04-17 23:53:58.824548513 +0000
+++ mono/utils/mono-threads-netbsd.c
@@ -0,0 +1,21 @@
+#include <config.h>
+
+#if defined(__NetBSD__)
+
+#include <mono/utils/mono-threads.h>
+#include <pthread.h>
+
+void
+mono_threads_core_get_stack_bounds (guint8 **staddr, size_t *stsize)
+{
+       pthread_attr_t attr;
+
+       *staddr = NULL;
+       *stsize = (size_t)-1;
+
+       pthread_attr_init (&attr);
+       pthread_attr_get_np (pthread_self (), &attr);
+
+       pthread_attr_getstack (&attr, (void**)staddr, stsize);
+       pthread_attr_destroy (&attr);
+}
