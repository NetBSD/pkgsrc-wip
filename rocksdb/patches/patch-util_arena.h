$NetBSD$

--- util/arena.h.orig	2018-01-03 03:02:00.000000000 +0000
+++ util/arena.h
@@ -23,6 +23,30 @@
 #include "util/allocator.h"
 #include "util/mutexlock.h"
 
+/* Some platforms lack max_align_t.  The check for _GCC_MAX_ALIGN_T is
+ *    a hack in case the configure-time test was done with g++ even though
+ *       we are currently compiling with gcc.  */
+#if ! (0 || defined _GCC_MAX_ALIGN_T)
+/* On the x86, the maximum storage alignment of double, long, etc. is 4,
+ *    but GCC's C11 ABI for x86 says that max_align_t has an alignment of 8,
+ *       and the C11 standard allows this.  Work around this problem by
+ *          using __alignof__ (which returns 8 for double) rather than _Alignof
+ *             (which returns 4), and align each union member accordingly.  */
+# ifdef __GNUC__
+#  define _GL_STDDEF_ALIGNAS(type) \
+	    __attribute__ ((__aligned__ (__alignof__ (type))))
+# else
+#  define _GL_STDDEF_ALIGNAS(type) /* */
+# endif
+typedef union
+{
+	  char *__p _GL_STDDEF_ALIGNAS (char *);
+	    double __d _GL_STDDEF_ALIGNAS (double);
+	      long double __ld _GL_STDDEF_ALIGNAS (long double);
+	        long int __i _GL_STDDEF_ALIGNAS (long int);
+} max_align_t;
+#endif
+
 namespace rocksdb {
 
 class Arena : public Allocator {
