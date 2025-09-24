$NetBSD$

--- src/util-fmemopen.c.orig	2025-09-16 02:07:13.000000000 +0000
+++ src/util-fmemopen.c
@@ -33,6 +33,10 @@
 #define USE_FMEM_WRAPPER 1
 #endif
 
+#ifdef __NetBSD__
+#define USE_FMEM_WRAPPER 1
+#endif
+
 #ifdef __OpenBSD__
 #define USE_FMEM_WRAPPER 1
 #endif
@@ -76,6 +80,10 @@ typedef struct SCFmem_ {
     char *buffer;
 } SCFmem;
 
+#ifdef __NetBSD__
+#define fpos_t off_t
+#endif
+
 /**
  * \brief Seek the mem file from offset and whence
  * \param handler pointer to the memfile
