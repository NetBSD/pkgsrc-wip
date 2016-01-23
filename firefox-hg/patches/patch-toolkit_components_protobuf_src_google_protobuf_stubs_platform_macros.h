# see upstream pull request #780 : not all __sparc__ are running Solaris
# https://github.com/google/protobuf/pull/780

--- toolkit/components/protobuf/src/google/protobuf/stubs/platform_macros.h.orig	2016-01-21 15:05:05.000000000 +0100
+++ toolkit/components/protobuf/src/google/protobuf/stubs/platform_macros.h	2016-01-21 16:17:05.000000000 +0100
@@ -67,11 +67,20 @@
 #define GOOGLE_PROTOBUF_ARCH_32_BIT 1
 #elif defined(sparc)
 #define GOOGLE_PROTOBUF_ARCH_SPARC 1
+#ifdef sun
 #ifdef SOLARIS_64BIT_ENABLED
 #define GOOGLE_PROTOBUF_ARCH_64_BIT 1
 #else
 #define GOOGLE_PROTOBUF_ARCH_32_BIT 1
 #endif
+#else
+// sparc, but not solaris
+# if __LP64__
+#  define GOOGLE_PROTOBUF_ARCH_64_BIT 1
+# else
+#  define GOOGLE_PROTOBUF_ARCH_32_BIT 1
+# endif
+#endif
 #elif defined(__GNUC__)
 # if (((__GNUC__ == 4) && (__GNUC_MINOR__ >= 7)) || (__GNUC__ > 4))
 // We fallback to the generic Clang/GCC >= 4.7 implementation in atomicops.h
