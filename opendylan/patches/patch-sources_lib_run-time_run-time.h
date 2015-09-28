$NetBSD$

--- sources/lib/run-time/run-time.h.orig	2015-09-25 09:55:53.000000000 +0000
+++ sources/lib/run-time/run-time.h
@@ -1426,13 +1426,10 @@ void *primitive_alloc_rt(size_t size,
 
 #ifdef OPEN_DYLAN_PLATFORM_WINDOWS
 #  include <malloc.h>
+#elif defined(OPEN_DYLAN_PLATFORM_FREEBSD) || defined(OPEN_DYLAN_PLATFORM_NETBSD)
+#  include <stdlib.h>
 #else
-#  ifdef OPEN_DYLAN_PLATFORM_FREEBSD
-#     include <sys/types.h>
-      extern void * alloca (size_t size);
-#  else
-#    include <alloca.h>
-#  endif
+#  include <alloca.h>
 #endif
 
 #define primitive_stack_allocate(sz) ((dylan_value)(alloca((int)(sz) * sizeof(dylan_value))))
