$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/lzma_sdk/C/Alloc.c.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/lzma_sdk/C/Alloc.c
@@ -1,38 +1,53 @@
 /* Alloc.c -- Memory allocation functions
-2021-07-13 : Igor Pavlov : Public domain */
+2024-02-18 : Igor Pavlov : Public domain */
 
 #include "Precomp.h"
 
-#include <stdio.h>
-
 #ifdef _WIN32
-#include <Windows.h>
+#include "7zWindows.h"
 #endif
 #include <stdlib.h>
 
 #include "Alloc.h"
 
-/* #define _SZ_ALLOC_DEBUG */
+#if defined(Z7_LARGE_PAGES) && defined(_WIN32) && \
+    (!defined(Z7_WIN32_WINNT_MIN) || Z7_WIN32_WINNT_MIN < 0x0502)  // < Win2003 (xp-64)
+  #define Z7_USE_DYN_GetLargePageMinimum
+#endif
+
+// for debug:
+#if 0
+#if defined(__CHERI__) && defined(__SIZEOF_POINTER__) && (__SIZEOF_POINTER__ == 16)
+// #pragma message("=== Z7_ALLOC_NO_OFFSET_ALLOCATOR === ")
+#define Z7_ALLOC_NO_OFFSET_ALLOCATOR
+#endif
+#endif
 
-/* use _SZ_ALLOC_DEBUG to debug alloc/free operations */
-#ifdef _SZ_ALLOC_DEBUG
+// #define SZ_ALLOC_DEBUG
+/* #define SZ_ALLOC_DEBUG */
 
+/* use SZ_ALLOC_DEBUG to debug alloc/free operations */
+#ifdef SZ_ALLOC_DEBUG
+
+#include <string.h>
 #include <stdio.h>
-int g_allocCount = 0;
-int g_allocCountMid = 0;
-int g_allocCountBig = 0;
+static int g_allocCount = 0;
+#ifdef _WIN32
+static int g_allocCountMid = 0;
+static int g_allocCountBig = 0;
+#endif
 
 
 #define CONVERT_INT_TO_STR(charType, tempSize) \
-  unsigned char temp[tempSize]; unsigned i = 0; \
-  while (val >= 10) { temp[i++] = (unsigned char)('0' + (unsigned)(val % 10)); val /= 10; } \
+  char temp[tempSize]; unsigned i = 0; \
+  while (val >= 10) { temp[i++] = (char)('0' + (unsigned)(val % 10)); val /= 10; } \
   *s++ = (charType)('0' + (unsigned)val); \
   while (i != 0) { i--; *s++ = temp[i]; } \
   *s = 0;
 
 static void ConvertUInt64ToString(UInt64 val, char *s)
 {
-  CONVERT_INT_TO_STR(char, 24);
+  CONVERT_INT_TO_STR(char, 24)
 }
 
 #define GET_HEX_CHAR(t) ((char)(((t < 10) ? ('0' + t) : ('A' + (t - 10)))))
@@ -77,7 +92,7 @@ static void PrintAligned(const char *s, 
   Print(s);
 }
 
-static void PrintLn()
+static void PrintLn(void)
 {
   Print("\n");
 }
@@ -89,10 +104,10 @@ static void PrintHex(UInt64 v, size_t al
   PrintAligned(s, align);
 }
 
-static void PrintDec(UInt64 v, size_t align)
+static void PrintDec(int v, size_t align)
 {
   char s[32];
-  ConvertUInt64ToString(v, s);
+  ConvertUInt64ToString((unsigned)v, s);
   PrintAligned(s, align);
 }
 
@@ -102,12 +117,19 @@ static void PrintAddr(void *p)
 }
 
 
-#define PRINT_ALLOC(name, cnt, size, ptr) \
+#define PRINT_REALLOC(name, cnt, size, ptr) { \
+    Print(name " "); \
+    if (!ptr) PrintDec(cnt++, 10); \
+    PrintHex(size, 10); \
+    PrintAddr(ptr); \
+    PrintLn(); }
+
+#define PRINT_ALLOC(name, cnt, size, ptr) { \
     Print(name " "); \
     PrintDec(cnt++, 10); \
     PrintHex(size, 10); \
     PrintAddr(ptr); \
-    PrintLn();
+    PrintLn(); }
  
 #define PRINT_FREE(name, cnt, ptr) if (ptr) { \
     Print(name " "); \
@@ -117,26 +139,45 @@ static void PrintAddr(void *p)
  
 #else
 
+#ifdef _WIN32
 #define PRINT_ALLOC(name, cnt, size, ptr)
+#endif
 #define PRINT_FREE(name, cnt, ptr)
 #define Print(s)
 #define PrintLn()
+#ifndef Z7_ALLOC_NO_OFFSET_ALLOCATOR
 #define PrintHex(v, align)
+#endif
 #define PrintAddr(p)
 
 #endif
 
 
+/*
+by specification:
+  malloc(non_NULL, 0)   : returns NULL or a unique pointer value that can later be successfully passed to free()
+  realloc(NULL, size)   : the call is equivalent to malloc(size)
+  realloc(non_NULL, 0)  : the call is equivalent to free(ptr)
+
+in main compilers:
+  malloc(0)             : returns non_NULL
+  realloc(NULL,     0)  : returns non_NULL
+  realloc(non_NULL, 0)  : returns NULL
+*/
+
 
 void *MyAlloc(size_t size)
 {
   if (size == 0)
     return NULL;
-  PRINT_ALLOC("Alloc    ", g_allocCount, size, NULL);
-  #ifdef _SZ_ALLOC_DEBUG
+  // PRINT_ALLOC("Alloc    ", g_allocCount, size, NULL)
+  #ifdef SZ_ALLOC_DEBUG
   {
     void *p = malloc(size);
-    // PRINT_ALLOC("Alloc    ", g_allocCount, size, p);
+    if (p)
+    {
+      PRINT_ALLOC("Alloc    ", g_allocCount, size, p)
+    }
     return p;
   }
   #else
@@ -146,71 +187,107 @@ void *MyAlloc(size_t size)
 
 void MyFree(void *address)
 {
-  PRINT_FREE("Free    ", g_allocCount, address);
+  PRINT_FREE("Free    ", g_allocCount, address)
   
   free(address);
 }
 
+void *MyRealloc(void *address, size_t size)
+{
+  if (size == 0)
+  {
+    MyFree(address);
+    return NULL;
+  }
+  // PRINT_REALLOC("Realloc  ", g_allocCount, size, address)
+  #ifdef SZ_ALLOC_DEBUG
+  {
+    void *p = realloc(address, size);
+    if (p)
+    {
+      PRINT_REALLOC("Realloc    ", g_allocCount, size, address)
+    }
+    return p;
+  }
+  #else
+  return realloc(address, size);
+  #endif
+}
+
+
 #ifdef _WIN32
 
 void *MidAlloc(size_t size)
 {
   if (size == 0)
     return NULL;
-  
-  PRINT_ALLOC("Alloc-Mid", g_allocCountMid, size, NULL);
-  
+  #ifdef SZ_ALLOC_DEBUG
+  {
+    void *p = VirtualAlloc(NULL, size, MEM_COMMIT, PAGE_READWRITE);
+    if (p)
+    {
+      PRINT_ALLOC("Alloc-Mid", g_allocCountMid, size, p)
+    }
+    return p;
+  }
+  #else
   return VirtualAlloc(NULL, size, MEM_COMMIT, PAGE_READWRITE);
+  #endif
 }
 
 void MidFree(void *address)
 {
-  PRINT_FREE("Free-Mid", g_allocCountMid, address);
+  PRINT_FREE("Free-Mid", g_allocCountMid, address)
 
   if (!address)
     return;
   VirtualFree(address, 0, MEM_RELEASE);
 }
 
-#ifdef _7ZIP_LARGE_PAGES
+#ifdef Z7_LARGE_PAGES
 
 #ifdef MEM_LARGE_PAGES
-  #define MY__MEM_LARGE_PAGES  MEM_LARGE_PAGES
+  #define MY_MEM_LARGE_PAGES  MEM_LARGE_PAGES
 #else
-  #define MY__MEM_LARGE_PAGES  0x20000000
+  #define MY_MEM_LARGE_PAGES  0x20000000
 #endif
 
 extern
 SIZE_T g_LargePageSize;
 SIZE_T g_LargePageSize = 0;
-typedef SIZE_T (WINAPI *GetLargePageMinimumP)(VOID);
+typedef SIZE_T (WINAPI *Func_GetLargePageMinimum)(VOID);
 
-#endif // _7ZIP_LARGE_PAGES
-
-void SetLargePageSize()
+void SetLargePageSize(void)
 {
-  #ifdef _7ZIP_LARGE_PAGES
   SIZE_T size;
-  GetLargePageMinimumP largePageMinimum = (GetLargePageMinimumP)
-        GetProcAddress(GetModuleHandle(TEXT("kernel32.dll")), "GetLargePageMinimum");
-  if (!largePageMinimum)
+#ifdef Z7_USE_DYN_GetLargePageMinimum
+Z7_DIAGNOSTIC_IGNORE_CAST_FUNCTION
+
+  const
+   Func_GetLargePageMinimum fn =
+  (Func_GetLargePageMinimum) Z7_CAST_FUNC_C GetProcAddress(GetModuleHandle(TEXT("kernel32.dll")),
+       "GetLargePageMinimum");
+  if (!fn)
     return;
-  size = largePageMinimum();
+  size = fn();
+#else
+  size = GetLargePageMinimum();
+#endif
   if (size == 0 || (size & (size - 1)) != 0)
     return;
   g_LargePageSize = size;
-  #endif
 }
 
+#endif // Z7_LARGE_PAGES
 
 void *BigAlloc(size_t size)
 {
   if (size == 0)
     return NULL;
 
-  PRINT_ALLOC("Alloc-Big", g_allocCountBig, size, NULL);
-  
-  #ifdef _7ZIP_LARGE_PAGES
+  PRINT_ALLOC("Alloc-Big", g_allocCountBig, size, NULL)
+
+  #ifdef Z7_LARGE_PAGES
   {
     SIZE_T ps = g_LargePageSize;
     if (ps != 0 && ps <= (1 << 30) && size > (ps / 2))
@@ -220,56 +297,43 @@ void *BigAlloc(size_t size)
       size2 = (size + ps) & ~ps;
       if (size2 >= size)
       {
-        void *res = VirtualAlloc(NULL, size2, MEM_COMMIT | MY__MEM_LARGE_PAGES, PAGE_READWRITE);
-        if (res)
-          return res;
+        void *p = VirtualAlloc(NULL, size2, MEM_COMMIT | MY_MEM_LARGE_PAGES, PAGE_READWRITE);
+        if (p)
+        {
+          PRINT_ALLOC("Alloc-BM ", g_allocCountMid, size2, p)
+          return p;
+        }
       }
     }
   }
   #endif
 
-  return VirtualAlloc(NULL, size, MEM_COMMIT, PAGE_READWRITE);
+  return MidAlloc(size);
 }
 
 void BigFree(void *address)
 {
-  PRINT_FREE("Free-Big", g_allocCountBig, address);
-  
-  if (!address)
-    return;
-  VirtualFree(address, 0, MEM_RELEASE);
+  PRINT_FREE("Free-Big", g_allocCountBig, address)
+  MidFree(address);
 }
 
-#endif
+#endif // _WIN32
 
 
-static void *SzAlloc(ISzAllocPtr p, size_t size) { UNUSED_VAR(p); return MyAlloc(size); }
-static void SzFree(ISzAllocPtr p, void *address) { UNUSED_VAR(p); MyFree(address); }
+static void *SzAlloc(ISzAllocPtr p, size_t size) { UNUSED_VAR(p)  return MyAlloc(size); }
+static void SzFree(ISzAllocPtr p, void *address) { UNUSED_VAR(p)  MyFree(address); }
 const ISzAlloc g_Alloc = { SzAlloc, SzFree };
 
 #ifdef _WIN32
-static void *SzMidAlloc(ISzAllocPtr p, size_t size) { UNUSED_VAR(p); return MidAlloc(size); }
-static void SzMidFree(ISzAllocPtr p, void *address) { UNUSED_VAR(p); MidFree(address); }
-static void *SzBigAlloc(ISzAllocPtr p, size_t size) { UNUSED_VAR(p); return BigAlloc(size); }
-static void SzBigFree(ISzAllocPtr p, void *address) { UNUSED_VAR(p); BigFree(address); }
+static void *SzMidAlloc(ISzAllocPtr p, size_t size) { UNUSED_VAR(p)  return MidAlloc(size); }
+static void SzMidFree(ISzAllocPtr p, void *address) { UNUSED_VAR(p)  MidFree(address); }
+static void *SzBigAlloc(ISzAllocPtr p, size_t size) { UNUSED_VAR(p)  return BigAlloc(size); }
+static void SzBigFree(ISzAllocPtr p, void *address) { UNUSED_VAR(p)  BigFree(address); }
 const ISzAlloc g_MidAlloc = { SzMidAlloc, SzMidFree };
 const ISzAlloc g_BigAlloc = { SzBigAlloc, SzBigFree };
 #endif
 
-/*
-  uintptr_t : <stdint.h> C99 (optional)
-            : unsupported in VS6
-*/
-
-#ifdef _WIN32
-  typedef UINT_PTR UIntPtr;
-#else
-  /*
-  typedef uintptr_t UIntPtr;
-  */
-  typedef ptrdiff_t UIntPtr;
-#endif
-
+#ifndef Z7_ALLOC_NO_OFFSET_ALLOCATOR
 
 #define ADJUST_ALLOC_SIZE 0
 /*
@@ -280,14 +344,36 @@ const ISzAlloc g_BigAlloc = { SzBigAlloc
      MyAlloc() can return address that is NOT multiple of sizeof(void *).
 */
 
-
 /*
-#define MY_ALIGN_PTR_DOWN(p, align) ((void *)((char *)(p) - ((size_t)(UIntPtr)(p) & ((align) - 1))))
+  uintptr_t : <stdint.h> C99 (optional)
+            : unsupported in VS6
 */
-#define MY_ALIGN_PTR_DOWN(p, align) ((void *)((((UIntPtr)(p)) & ~((UIntPtr)(align) - 1))))
+typedef
+  #ifdef _WIN32
+    UINT_PTR
+  #elif 1
+    uintptr_t
+  #else
+    ptrdiff_t
+  #endif
+    MY_uintptr_t;
+
+#if 0 \
+    || (defined(__CHERI__) \
+    || defined(__SIZEOF_POINTER__) && (__SIZEOF_POINTER__ > 8))
+// for 128-bit pointers (cheri):
+#define MY_ALIGN_PTR_DOWN(p, align)  \
+    ((void *)((char *)(p) - ((size_t)(MY_uintptr_t)(p) & ((align) - 1))))
+#else
+#define MY_ALIGN_PTR_DOWN(p, align) \
+    ((void *)((((MY_uintptr_t)(p)) & ~((MY_uintptr_t)(align) - 1))))
+#endif
 
+#endif
 
-#if !defined(_WIN32) && defined(_POSIX_C_SOURCE) && (_POSIX_C_SOURCE >= 200112L)
+#if !defined(_WIN32) \
+    && (defined(Z7_ALLOC_NO_OFFSET_ALLOCATOR) \
+        || defined(_POSIX_C_SOURCE) && (_POSIX_C_SOURCE >= 200112L))
   #define USE_posix_memalign
 #endif
 
@@ -327,14 +413,13 @@ static int posix_memalign(void **ptr, si
 
 #define ALLOC_ALIGN_SIZE ((size_t)1 << 7)
 
-static void *SzAlignedAlloc(ISzAllocPtr pp, size_t size)
+void *z7_AlignedAlloc(size_t size)
 {
-  #ifndef USE_posix_memalign
+#ifndef USE_posix_memalign
   
   void *p;
   void *pAligned;
   size_t newSize;
-  UNUSED_VAR(pp);
 
   /* also we can allocate additional dummy ALLOC_ALIGN_SIZE bytes after aligned
      block to prevent cache line sharing with another allocated blocks */
@@ -359,10 +444,9 @@ static void *SzAlignedAlloc(ISzAllocPtr 
 
   return pAligned;
 
-  #else
+#else
 
   void *p;
-  UNUSED_VAR(pp);
   if (posix_memalign(&p, ALLOC_ALIGN_SIZE, size))
     return NULL;
 
@@ -371,19 +455,37 @@ static void *SzAlignedAlloc(ISzAllocPtr 
 
   return p;
 
-  #endif
+#endif
+}
+
+
+void z7_AlignedFree(void *address)
+{
+#ifndef USE_posix_memalign
+  if (address)
+    MyFree(((void **)address)[-1]);
+#else
+  free(address);
+#endif
+}
+
+
+static void *SzAlignedAlloc(ISzAllocPtr pp, size_t size)
+{
+  UNUSED_VAR(pp)
+  return z7_AlignedAlloc(size);
 }
 
 
 static void SzAlignedFree(ISzAllocPtr pp, void *address)
 {
-  UNUSED_VAR(pp);
-  #ifndef USE_posix_memalign
+  UNUSED_VAR(pp)
+#ifndef USE_posix_memalign
   if (address)
     MyFree(((void **)address)[-1]);
-  #else
+#else
   free(address);
-  #endif
+#endif
 }
 
 
@@ -391,17 +493,45 @@ const ISzAlloc g_AlignedAlloc = { SzAlig
 
 
 
-#define MY_ALIGN_PTR_DOWN_1(p) MY_ALIGN_PTR_DOWN(p, sizeof(void *))
-
 /* we align ptr to support cases where CAlignOffsetAlloc::offset is not multiply of sizeof(void *) */
-#define REAL_BLOCK_PTR_VAR(p) ((void **)MY_ALIGN_PTR_DOWN_1(p))[-1]
-/*
-#define REAL_BLOCK_PTR_VAR(p) ((void **)(p))[-1]
-*/
+#ifndef Z7_ALLOC_NO_OFFSET_ALLOCATOR
+#if 1
+  #define MY_ALIGN_PTR_DOWN_1(p)  MY_ALIGN_PTR_DOWN(p, sizeof(void *))
+  #define REAL_BLOCK_PTR_VAR(p)  ((void **)MY_ALIGN_PTR_DOWN_1(p))[-1]
+#else
+  // we can use this simplified code,
+  // if (CAlignOffsetAlloc::offset == (k * sizeof(void *))
+  #define REAL_BLOCK_PTR_VAR(p)  (((void **)(p))[-1])
+#endif
+#endif
+
+
+#if 0
+#ifndef Z7_ALLOC_NO_OFFSET_ALLOCATOR
+#include <stdio.h>
+static void PrintPtr(const char *s, const void *p)
+{
+  const Byte *p2 = (const Byte *)&p;
+  unsigned i;
+  printf("%s %p ", s, p);
+  for (i = sizeof(p); i != 0;)
+  {
+    i--;
+    printf("%02x", p2[i]);
+  }
+  printf("\n");
+}
+#endif
+#endif
+
 
 static void *AlignOffsetAlloc_Alloc(ISzAllocPtr pp, size_t size)
 {
-  CAlignOffsetAlloc *p = CONTAINER_FROM_VTBL(pp, CAlignOffsetAlloc, vt);
+#if defined(Z7_ALLOC_NO_OFFSET_ALLOCATOR)
+  UNUSED_VAR(pp)
+  return z7_AlignedAlloc(size);
+#else
+  const CAlignOffsetAlloc *p = Z7_CONTAINER_FROM_VTBL_CONST(pp, CAlignOffsetAlloc, vt);
   void *adr;
   void *pAligned;
   size_t newSize;
@@ -429,6 +559,12 @@ static void *AlignOffsetAlloc_Alloc(ISzA
   pAligned = (char *)MY_ALIGN_PTR_DOWN((char *)adr +
       alignSize - p->offset + extra + ADJUST_ALLOC_SIZE, alignSize) + p->offset;
 
+#if 0
+  printf("\nalignSize = %6x, offset=%6x, size=%8x \n", (unsigned)alignSize, (unsigned)p->offset, (unsigned)size);
+  PrintPtr("base", adr);
+  PrintPtr("alig", pAligned);
+#endif
+
   PrintLn();
   Print("- Aligned: ");
   Print(" size="); PrintHex(size, 8);
@@ -440,19 +576,25 @@ static void *AlignOffsetAlloc_Alloc(ISzA
   REAL_BLOCK_PTR_VAR(pAligned) = adr;
 
   return pAligned;
+#endif
 }
 
 
 static void AlignOffsetAlloc_Free(ISzAllocPtr pp, void *address)
 {
+#if defined(Z7_ALLOC_NO_OFFSET_ALLOCATOR)
+  UNUSED_VAR(pp)
+  z7_AlignedFree(address);
+#else
   if (address)
   {
-    CAlignOffsetAlloc *p = CONTAINER_FROM_VTBL(pp, CAlignOffsetAlloc, vt);
+    const CAlignOffsetAlloc *p = Z7_CONTAINER_FROM_VTBL_CONST(pp, CAlignOffsetAlloc, vt);
     PrintLn();
     Print("- Aligned Free: ");
     PrintLn();
     ISzAlloc_Free(p->baseAlloc, REAL_BLOCK_PTR_VAR(address));
   }
+#endif
 }
 
 
