$NetBSD: patch-hacklocaledir.c,v 1.1.1.1 2004/05/10 15:13:13 arved Exp $
--- hacklocaledir.c.orig	Tue Jul  8 14:23:53 2003
+++ hacklocaledir.c	Mon May 10 14:03:36 2004
@@ -40,12 +40,21 @@
     static size_t matchlen;
     char *newpath = 0;
     int r;
-
+#ifdef RTLD_NEXT
     if (!open && !(open = dlsym(RTLD_NEXT, "open")))
     {
 	fprintf(stderr, PRELOAD ": can't find open(): %s\n", dlerror());
 	return -1;
     }
+#else
+    void *handle = dlopen(NULL, DL_LAZY);
+    if (!open && !(open = dlsym(handle, "open")))
+    {
+        fprintf(stderr, PRELOAD ": can't find open(): %s\n", dlerror());
+        return -1;
+    }
+    dlclose(handle);
+#endif
 
     if (textdomain || (textdomain = getenv("TEXTDOMAIN")))
     {
