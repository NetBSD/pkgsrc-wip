$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/lzma_sdk/C/7zAlloc.c.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/lzma_sdk/C/7zAlloc.c
@@ -1,5 +1,5 @@
-/* 7zAlloc.c -- Allocation functions
-2017-04-03 : Igor Pavlov : Public domain */
+/* 7zAlloc.c -- Allocation functions for 7z processing
+2023-03-04 : Igor Pavlov : Public domain */
 
 #include "Precomp.h"
 
@@ -7,74 +7,83 @@
 
 #include "7zAlloc.h"
 
-/* #define _SZ_ALLOC_DEBUG */
-/* use _SZ_ALLOC_DEBUG to debug alloc/free operations */
+/* #define SZ_ALLOC_DEBUG */
+/* use SZ_ALLOC_DEBUG to debug alloc/free operations */
 
-#ifdef _SZ_ALLOC_DEBUG
+#ifdef SZ_ALLOC_DEBUG
 
+/*
 #ifdef _WIN32
-#include <windows.h>
+#include "7zWindows.h"
 #endif
+*/
 
 #include <stdio.h>
-int g_allocCount = 0;
-int g_allocCountTemp = 0;
+static int g_allocCount = 0;
+static int g_allocCountTemp = 0;
 
+static void Print_Alloc(const char *s, size_t size, int *counter)
+{
+  const unsigned size2 = (unsigned)size;
+  fprintf(stderr, "\n%s count = %10d : %10u bytes; ", s, *counter, size2);
+  (*counter)++;
+}
+static void Print_Free(const char *s, int *counter)
+{
+  (*counter)--;
+  fprintf(stderr, "\n%s count = %10d", s, *counter);
+}
 #endif
 
 void *SzAlloc(ISzAllocPtr p, size_t size)
 {
-  UNUSED_VAR(p);
+  UNUSED_VAR(p)
   if (size == 0)
     return 0;
-  #ifdef _SZ_ALLOC_DEBUG
-  fprintf(stderr, "\nAlloc %10u bytes; count = %10d", (unsigned)size, g_allocCount);
-  g_allocCount++;
+  #ifdef SZ_ALLOC_DEBUG
+  Print_Alloc("Alloc", size, &g_allocCount);
   #endif
   return malloc(size);
 }
 
 void SzFree(ISzAllocPtr p, void *address)
 {
-  UNUSED_VAR(p);
-  #ifdef _SZ_ALLOC_DEBUG
-  if (address != 0)
-  {
-    g_allocCount--;
-    fprintf(stderr, "\nFree; count = %10d", g_allocCount);
-  }
+  UNUSED_VAR(p)
+  #ifdef SZ_ALLOC_DEBUG
+  if (address)
+    Print_Free("Free ", &g_allocCount);
   #endif
   free(address);
 }
 
 void *SzAllocTemp(ISzAllocPtr p, size_t size)
 {
-  UNUSED_VAR(p);
+  UNUSED_VAR(p)
   if (size == 0)
     return 0;
-  #ifdef _SZ_ALLOC_DEBUG
-  fprintf(stderr, "\nAlloc_temp %10u bytes;  count = %10d", (unsigned)size, g_allocCountTemp);
-  g_allocCountTemp++;
+  #ifdef SZ_ALLOC_DEBUG
+  Print_Alloc("Alloc_temp", size, &g_allocCountTemp);
+  /*
   #ifdef _WIN32
   return HeapAlloc(GetProcessHeap(), 0, size);
   #endif
+  */
   #endif
   return malloc(size);
 }
 
 void SzFreeTemp(ISzAllocPtr p, void *address)
 {
-  UNUSED_VAR(p);
-  #ifdef _SZ_ALLOC_DEBUG
-  if (address != 0)
-  {
-    g_allocCountTemp--;
-    fprintf(stderr, "\nFree_temp; count = %10d", g_allocCountTemp);
-  }
+  UNUSED_VAR(p)
+  #ifdef SZ_ALLOC_DEBUG
+  if (address)
+    Print_Free("Free_temp ", &g_allocCountTemp);
+  /*
   #ifdef _WIN32
   HeapFree(GetProcessHeap(), 0, address);
   return;
   #endif
+  */
   #endif
   free(address);
 }
