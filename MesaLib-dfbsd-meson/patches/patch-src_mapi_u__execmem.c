$NetBSD$

Option from OpenBSD xenocara

2016-07-25

Disable the code that allocates W|X memory.  There is fallback code that
gets used if allocating W|X memory fails, which is probably a bit slower.
However, that is much better than commit a W^X violation which currently
gets you killed.

--- src/mapi/u_execmem.c.orig	2019-03-23 16:29:21.000000000 +0000
+++ src/mapi/u_execmem.c
@@ -45,8 +45,15 @@ static unsigned int head = 0;
 
 static unsigned char *exec_mem = (unsigned char *)0;
 
+#if defined(DISABLE_WX_MEMORY)
 
-#if defined(__linux__) || defined(__OpenBSD__) || defined(_NetBSD__) || defined(__sun) || defined(__HAIKU__)
+static int
+init_map(void)
+{
+   return 0;
+}
+
+#elif defined(__linux__) || defined(__OpenBSD__) || defined(_NetBSD__) || defined(__sun) || defined(__HAIKU__)
 
 #include <unistd.h>
 #include <sys/mman.h>
