$NetBSD$

--- test/sanitizer_common/print_address.h.orig	2017-06-03 23:53:55.000000000 +0000
+++ test/sanitizer_common/print_address.h
@@ -8,7 +8,7 @@ void print_address(const char *str, int 
   while (n--) {
     void *p = va_arg(ap, void *);
 #if defined(__x86_64__) || defined(__aarch64__) || defined(__powerpc64__)
-    // On FreeBSD, the %p conversion specifier works as 0x%x and thus does not
+    // On FreeBSD/NetBSD, the %p conversion specifier works as 0x%x and thus does not
     // match to the format used in the diagnotic message.
     fprintf(stderr, "0x%012lx ", (unsigned long) p);
 #elif defined(__i386__) || defined(__arm__)
