$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/lzma_sdk/C/Alloc.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/lzma_sdk/C/Alloc.h
@@ -1,31 +1,49 @@
 /* Alloc.h -- Memory allocation functions
-2021-07-13 : Igor Pavlov : Public domain */
+2024-01-22 : Igor Pavlov : Public domain */
 
-#ifndef __COMMON_ALLOC_H
-#define __COMMON_ALLOC_H
+#ifndef ZIP7_INC_ALLOC_H
+#define ZIP7_INC_ALLOC_H
 
 #include "7zTypes.h"
 
 EXTERN_C_BEGIN
 
+/*
+  MyFree(NULL)        : is allowed, as free(NULL)
+  MyAlloc(0)          : returns NULL : but malloc(0)        is allowed to return NULL or non_NULL
+  MyRealloc(NULL, 0)  : returns NULL : but realloc(NULL, 0) is allowed to return NULL or non_NULL
+MyRealloc() is similar to realloc() for the following cases:
+  MyRealloc(non_NULL, 0)         : returns NULL and always calls MyFree(ptr)
+  MyRealloc(NULL, non_ZERO)      : returns NULL, if allocation failed
+  MyRealloc(non_NULL, non_ZERO)  : returns NULL, if reallocation failed
+*/
+
 void *MyAlloc(size_t size);
 void MyFree(void *address);
+void *MyRealloc(void *address, size_t size);
+
+void *z7_AlignedAlloc(size_t size);
+void  z7_AlignedFree(void *p);
 
 #ifdef _WIN32
 
+#ifdef Z7_LARGE_PAGES
 void SetLargePageSize(void);
+#endif
 
 void *MidAlloc(size_t size);
 void MidFree(void *address);
 void *BigAlloc(size_t size);
 void BigFree(void *address);
 
+/* #define Z7_BIG_ALLOC_IS_ZERO_FILLED */
+
 #else
 
-#define MidAlloc(size) MyAlloc(size)
-#define MidFree(address) MyFree(address)
-#define BigAlloc(size) MyAlloc(size)
-#define BigFree(address) MyFree(address)
+#define MidAlloc(size)    z7_AlignedAlloc(size)
+#define MidFree(address)  z7_AlignedFree(address)
+#define BigAlloc(size)    z7_AlignedAlloc(size)
+#define BigFree(address)  z7_AlignedFree(address)
 
 #endif
 
