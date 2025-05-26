$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/lzma_sdk/C/7zTypes.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/lzma_sdk/C/7zTypes.h
@@ -1,8 +1,8 @@
 /* 7zTypes.h -- Basic types
-2022-04-01 : Igor Pavlov : Public domain */
+2024-01-24 : Igor Pavlov : Public domain */
 
-#ifndef __7Z_TYPES_H
-#define __7Z_TYPES_H
+#ifndef ZIP7_7Z_TYPES_H
+#define ZIP7_7Z_TYPES_H
 
 #ifdef _WIN32
 /* #include <windows.h> */
@@ -52,6 +52,11 @@ typedef int SRes;
     #define MY_ALIGN(n)
   #endif
 #else
+  /*
+  // C11/C++11:
+  #include <stdalign.h>
+  #define MY_ALIGN(n) alignas(n)
+  */
   #define MY_ALIGN(n) __attribute__ ((aligned(n)))
 #endif
 
@@ -62,7 +67,7 @@ typedef int SRes;
 typedef unsigned WRes;
 #define MY_SRes_HRESULT_FROM_WRes(x) HRESULT_FROM_WIN32(x)
 
-// #define MY_HRES_ERROR__INTERNAL_ERROR  MY_SRes_HRESULT_FROM_WRes(ERROR_INTERNAL_ERROR)
+// #define MY_HRES_ERROR_INTERNAL_ERROR  MY_SRes_HRESULT_FROM_WRes(ERROR_INTERNAL_ERROR)
 
 #else // _WIN32
 
@@ -70,13 +75,13 @@ typedef unsigned WRes;
 typedef int WRes;
 
 // (FACILITY_ERRNO = 0x800) is 7zip's FACILITY constant to represent (errno) errors in HRESULT
-#define MY__FACILITY_ERRNO  0x800
-#define MY__FACILITY_WIN32  7
-#define MY__FACILITY__WRes  MY__FACILITY_ERRNO
+#define MY_FACILITY_ERRNO  0x800
+#define MY_FACILITY_WIN32  7
+#define MY_FACILITY_WRes  MY_FACILITY_ERRNO
 
 #define MY_HRESULT_FROM_errno_CONST_ERROR(x) ((HRESULT)( \
           ( (HRESULT)(x) & 0x0000FFFF) \
-          | (MY__FACILITY__WRes << 16)  \
+          | (MY_FACILITY_WRes << 16)  \
           | (HRESULT)0x80000000 ))
 
 #define MY_SRes_HRESULT_FROM_WRes(x) \
@@ -120,17 +125,17 @@ typedef int WRes;
 #define ERROR_INVALID_REPARSE_DATA  ((HRESULT)0x80071128L)
 #define ERROR_REPARSE_TAG_INVALID   ((HRESULT)0x80071129L)
 
-// if (MY__FACILITY__WRes != FACILITY_WIN32),
+// if (MY_FACILITY_WRes != FACILITY_WIN32),
 // we use FACILITY_WIN32 for COM errors:
 #define E_OUTOFMEMORY               ((HRESULT)0x8007000EL)
 #define E_INVALIDARG                ((HRESULT)0x80070057L)
-#define MY__E_ERROR_NEGATIVE_SEEK   ((HRESULT)0x80070083L)
+#define MY_E_ERROR_NEGATIVE_SEEK    ((HRESULT)0x80070083L)
 
 /*
 // we can use FACILITY_ERRNO for some COM errors, that have errno equivalents:
 #define E_OUTOFMEMORY             MY_HRESULT_FROM_errno_CONST_ERROR(ENOMEM)
 #define E_INVALIDARG              MY_HRESULT_FROM_errno_CONST_ERROR(EINVAL)
-#define MY__E_ERROR_NEGATIVE_SEEK MY_HRESULT_FROM_errno_CONST_ERROR(EINVAL)
+#define MY_E_ERROR_NEGATIVE_SEEK  MY_HRESULT_FROM_errno_CONST_ERROR(EINVAL)
 */
 
 #define TEXT(quote) quote
@@ -156,18 +161,18 @@ typedef int WRes;
 
 
 #ifndef RINOK
-#define RINOK(x) { int __result__ = (x); if (__result__ != 0) return __result__; }
+#define RINOK(x) { const int _result_ = (x); if (_result_ != 0) return _result_; }
 #endif
 
 #ifndef RINOK_WRes
-#define RINOK_WRes(x) { WRes __result__ = (x); if (__result__ != 0) return __result__; }
+#define RINOK_WRes(x) { const WRes _result_ = (x); if (_result_ != 0) return _result_; }
 #endif
 
 typedef unsigned char Byte;
 typedef short Int16;
 typedef unsigned short UInt16;
 
-#ifdef _LZMA_UINT32_IS_ULONG
+#ifdef Z7_DECL_Int32_AS_long
 typedef long Int32;
 typedef unsigned long UInt32;
 #else
@@ -206,37 +211,51 @@ typedef size_t SIZE_T;
 #endif //  _WIN32
 
 
-#define MY_HRES_ERROR__INTERNAL_ERROR  ((HRESULT)0x8007054FL)
+#define MY_HRES_ERROR_INTERNAL_ERROR  ((HRESULT)0x8007054FL)
 
 
-#ifdef _SZ_NO_INT_64
-
-/* define _SZ_NO_INT_64, if your compiler doesn't support 64-bit integers.
-   NOTES: Some code will work incorrectly in that case! */
+#ifdef Z7_DECL_Int64_AS_long
 
 typedef long Int64;
 typedef unsigned long UInt64;
 
 #else
 
-#if defined(_MSC_VER) || defined(__BORLANDC__)
+#if (defined(_MSC_VER) || defined(__BORLANDC__)) && !defined(__clang__)
 typedef __int64 Int64;
 typedef unsigned __int64 UInt64;
-#define UINT64_CONST(n) n
+#else
+#if defined(__clang__) || defined(__GNUC__)
+#include <stdint.h>
+typedef int64_t Int64;
+typedef uint64_t UInt64;
 #else
 typedef long long int Int64;
 typedef unsigned long long int UInt64;
-#define UINT64_CONST(n) n ## ULL
+// #define UINT64_CONST(n) n ## ULL
+#endif
 #endif
 
 #endif
 
-#ifdef _LZMA_NO_SYSTEM_SIZE_T
-typedef UInt32 SizeT;
+#define UINT64_CONST(n) n
+
+
+#ifdef Z7_DECL_SizeT_AS_unsigned_int
+typedef unsigned int SizeT;
 #else
 typedef size_t SizeT;
 #endif
 
+/*
+#if (defined(_MSC_VER) && _MSC_VER <= 1200)
+typedef size_t MY_uintptr_t;
+#else
+#include <stdint.h>
+typedef uintptr_t MY_uintptr_t;
+#endif
+*/
+
 typedef int BoolInt;
 /* typedef BoolInt Bool; */
 #define True 1
@@ -244,23 +263,23 @@ typedef int BoolInt;
 
 
 #ifdef _WIN32
-#define MY_STD_CALL __stdcall
+#define Z7_STDCALL __stdcall
 #else
-#define MY_STD_CALL
+#define Z7_STDCALL
 #endif
 
 #ifdef _MSC_VER
 
 #if _MSC_VER >= 1300
-#define MY_NO_INLINE __declspec(noinline)
+#define Z7_NO_INLINE __declspec(noinline)
 #else
-#define MY_NO_INLINE
+#define Z7_NO_INLINE
 #endif
 
-#define MY_FORCE_INLINE __forceinline
+#define Z7_FORCE_INLINE __forceinline
 
-#define MY_CDECL __cdecl
-#define MY_FAST_CALL __fastcall
+#define Z7_CDECL      __cdecl
+#define Z7_FASTCALL  __fastcall
 
 #else //  _MSC_VER
 
@@ -268,27 +287,25 @@ typedef int BoolInt;
     || (defined(__clang__) && (__clang_major__ >= 4)) \
     || defined(__INTEL_COMPILER) \
     || defined(__xlC__)
-#define MY_NO_INLINE __attribute__((noinline))
-// #define MY_FORCE_INLINE __attribute__((always_inline)) inline
+#define Z7_NO_INLINE      __attribute__((noinline))
+#define Z7_FORCE_INLINE   __attribute__((always_inline)) inline
 #else
-#define MY_NO_INLINE
+#define Z7_NO_INLINE
+#define Z7_FORCE_INLINE
 #endif
 
-#define MY_FORCE_INLINE
-
-
-#define MY_CDECL
+#define Z7_CDECL
 
 #if  defined(_M_IX86) \
   || defined(__i386__)
-// #define MY_FAST_CALL __attribute__((fastcall))
-// #define MY_FAST_CALL __attribute__((cdecl))
-#define MY_FAST_CALL
+// #define Z7_FASTCALL __attribute__((fastcall))
+// #define Z7_FASTCALL __attribute__((cdecl))
+#define Z7_FASTCALL
 #elif defined(MY_CPU_AMD64)
-// #define MY_FAST_CALL __attribute__((ms_abi))
-#define MY_FAST_CALL
+// #define Z7_FASTCALL __attribute__((ms_abi))
+#define Z7_FASTCALL
 #else
-#define MY_FAST_CALL
+#define Z7_FASTCALL
 #endif
 
 #endif //  _MSC_VER
@@ -296,41 +313,49 @@ typedef int BoolInt;
 
 /* The following interfaces use first parameter as pointer to structure */
 
-typedef struct IByteIn IByteIn;
-struct IByteIn
+// #define Z7_C_IFACE_CONST_QUAL
+#define Z7_C_IFACE_CONST_QUAL const
+
+#define Z7_C_IFACE_DECL(a) \
+  struct a ## _; \
+  typedef Z7_C_IFACE_CONST_QUAL struct a ## _ * a ## Ptr; \
+  typedef struct a ## _ a; \
+  struct a ## _
+
+
+Z7_C_IFACE_DECL (IByteIn)
 {
-  Byte (*Read)(const IByteIn *p); /* reads one byte, returns 0 in case of EOF or error */
+  Byte (*Read)(IByteInPtr p); /* reads one byte, returns 0 in case of EOF or error */
 };
 #define IByteIn_Read(p) (p)->Read(p)
 
 
-typedef struct IByteOut IByteOut;
-struct IByteOut
+Z7_C_IFACE_DECL (IByteOut)
 {
-  void (*Write)(const IByteOut *p, Byte b);
+  void (*Write)(IByteOutPtr p, Byte b);
 };
 #define IByteOut_Write(p, b) (p)->Write(p, b)
 
 
-typedef struct ISeqInStream ISeqInStream;
-struct ISeqInStream
+Z7_C_IFACE_DECL (ISeqInStream)
 {
-  SRes (*Read)(const ISeqInStream *p, void *buf, size_t *size);
+  SRes (*Read)(ISeqInStreamPtr p, void *buf, size_t *size);
     /* if (input(*size) != 0 && output(*size) == 0) means end_of_stream.
        (output(*size) < input(*size)) is allowed */
 };
 #define ISeqInStream_Read(p, buf, size) (p)->Read(p, buf, size)
 
+/* try to read as much as avail in stream and limited by (*processedSize) */
+SRes SeqInStream_ReadMax(ISeqInStreamPtr stream, void *buf, size_t *processedSize);
 /* it can return SZ_ERROR_INPUT_EOF */
-SRes SeqInStream_Read(const ISeqInStream *stream, void *buf, size_t size);
-SRes SeqInStream_Read2(const ISeqInStream *stream, void *buf, size_t size, SRes errorType);
-SRes SeqInStream_ReadByte(const ISeqInStream *stream, Byte *buf);
+// SRes SeqInStream_Read(ISeqInStreamPtr stream, void *buf, size_t size);
+// SRes SeqInStream_Read2(ISeqInStreamPtr stream, void *buf, size_t size, SRes errorType);
+SRes SeqInStream_ReadByte(ISeqInStreamPtr stream, Byte *buf);
 
 
-typedef struct ISeqOutStream ISeqOutStream;
-struct ISeqOutStream
+Z7_C_IFACE_DECL (ISeqOutStream)
 {
-  size_t (*Write)(const ISeqOutStream *p, const void *buf, size_t size);
+  size_t (*Write)(ISeqOutStreamPtr p, const void *buf, size_t size);
     /* Returns: result - the number of actually written bytes.
        (result < size) means error */
 };
@@ -344,29 +369,26 @@ typedef enum
 } ESzSeek;
 
 
-typedef struct ISeekInStream ISeekInStream;
-struct ISeekInStream
+Z7_C_IFACE_DECL (ISeekInStream)
 {
-  SRes (*Read)(const ISeekInStream *p, void *buf, size_t *size);  /* same as ISeqInStream::Read */
-  SRes (*Seek)(const ISeekInStream *p, Int64 *pos, ESzSeek origin);
+  SRes (*Read)(ISeekInStreamPtr p, void *buf, size_t *size);  /* same as ISeqInStream::Read */
+  SRes (*Seek)(ISeekInStreamPtr p, Int64 *pos, ESzSeek origin);
 };
 #define ISeekInStream_Read(p, buf, size)   (p)->Read(p, buf, size)
 #define ISeekInStream_Seek(p, pos, origin) (p)->Seek(p, pos, origin)
 
 
-typedef struct ILookInStream ILookInStream;
-struct ILookInStream
+Z7_C_IFACE_DECL (ILookInStream)
 {
-  SRes (*Look)(const ILookInStream *p, const void **buf, size_t *size);
+  SRes (*Look)(ILookInStreamPtr p, const void **buf, size_t *size);
     /* if (input(*size) != 0 && output(*size) == 0) means end_of_stream.
        (output(*size) > input(*size)) is not allowed
        (output(*size) < input(*size)) is allowed */
-  SRes (*Skip)(const ILookInStream *p, size_t offset);
+  SRes (*Skip)(ILookInStreamPtr p, size_t offset);
     /* offset must be <= output(*size) of Look */
-
-  SRes (*Read)(const ILookInStream *p, void *buf, size_t *size);
+  SRes (*Read)(ILookInStreamPtr p, void *buf, size_t *size);
     /* reads directly (without buffer). It's same as ISeqInStream::Read */
-  SRes (*Seek)(const ILookInStream *p, Int64 *pos, ESzSeek origin);
+  SRes (*Seek)(ILookInStreamPtr p, Int64 *pos, ESzSeek origin);
 };
 
 #define ILookInStream_Look(p, buf, size)   (p)->Look(p, buf, size)
@@ -375,19 +397,18 @@ struct ILookInStream
 #define ILookInStream_Seek(p, pos, origin) (p)->Seek(p, pos, origin)
 
 
-SRes LookInStream_LookRead(const ILookInStream *stream, void *buf, size_t *size);
-SRes LookInStream_SeekTo(const ILookInStream *stream, UInt64 offset);
+SRes LookInStream_LookRead(ILookInStreamPtr stream, void *buf, size_t *size);
+SRes LookInStream_SeekTo(ILookInStreamPtr stream, UInt64 offset);
 
 /* reads via ILookInStream::Read */
-SRes LookInStream_Read2(const ILookInStream *stream, void *buf, size_t size, SRes errorType);
-SRes LookInStream_Read(const ILookInStream *stream, void *buf, size_t size);
-
+SRes LookInStream_Read2(ILookInStreamPtr stream, void *buf, size_t size, SRes errorType);
+SRes LookInStream_Read(ILookInStreamPtr stream, void *buf, size_t size);
 
 
 typedef struct
 {
   ILookInStream vt;
-  const ISeekInStream *realStream;
+  ISeekInStreamPtr realStream;
  
   size_t pos;
   size_t size; /* it's data size */
@@ -399,13 +420,13 @@ typedef struct
 
 void LookToRead2_CreateVTable(CLookToRead2 *p, int lookahead);
 
-#define LookToRead2_Init(p) { (p)->pos = (p)->size = 0; }
+#define LookToRead2_INIT(p) { (p)->pos = (p)->size = 0; }
 
 
 typedef struct
 {
   ISeqInStream vt;
-  const ILookInStream *realStream;
+  ILookInStreamPtr realStream;
 } CSecToLook;
 
 void SecToLook_CreateVTable(CSecToLook *p);
@@ -415,20 +436,19 @@ void SecToLook_CreateVTable(CSecToLook *
 typedef struct
 {
   ISeqInStream vt;
-  const ILookInStream *realStream;
+  ILookInStreamPtr realStream;
 } CSecToRead;
 
 void SecToRead_CreateVTable(CSecToRead *p);
 
 
-typedef struct ICompressProgress ICompressProgress;
-
-struct ICompressProgress
+Z7_C_IFACE_DECL (ICompressProgress)
 {
-  SRes (*Progress)(const ICompressProgress *p, UInt64 inSize, UInt64 outSize);
+  SRes (*Progress)(ICompressProgressPtr p, UInt64 inSize, UInt64 outSize);
     /* Returns: result. (result != SZ_OK) means break.
        Value (UInt64)(Int64)-1 for size means unknown value. */
 };
+
 #define ICompressProgress_Progress(p, inSize, outSize) (p)->Progress(p, inSize, outSize)
 
 
@@ -466,13 +486,13 @@ struct ISzAlloc
 
 
 
-#ifndef MY_container_of
+#ifndef Z7_container_of
 
 /*
-#define MY_container_of(ptr, type, m) container_of(ptr, type, m)
-#define MY_container_of(ptr, type, m) CONTAINING_RECORD(ptr, type, m)
-#define MY_container_of(ptr, type, m) ((type *)((char *)(ptr) - offsetof(type, m)))
-#define MY_container_of(ptr, type, m) (&((type *)0)->m == (ptr), ((type *)(((char *)(ptr)) - MY_offsetof(type, m))))
+#define Z7_container_of(ptr, type, m) container_of(ptr, type, m)
+#define Z7_container_of(ptr, type, m) CONTAINING_RECORD(ptr, type, m)
+#define Z7_container_of(ptr, type, m) ((type *)((char *)(ptr) - offsetof(type, m)))
+#define Z7_container_of(ptr, type, m) (&((type *)0)->m == (ptr), ((type *)(((char *)(ptr)) - MY_offsetof(type, m))))
 */
 
 /*
@@ -481,24 +501,64 @@ struct ISzAlloc
     GCC 4.8.1 : classes with non-public variable members"
 */
 
-#define MY_container_of(ptr, type, m) ((type *)(void *)((char *)(void *)(1 ? (ptr) : &((type *)0)->m) - MY_offsetof(type, m)))
+#define Z7_container_of(ptr, type, m) \
+  ((type *)(void *)((char *)(void *) \
+  (1 ? (ptr) : &((type *)NULL)->m) - MY_offsetof(type, m)))
+
+#define Z7_container_of_CONST(ptr, type, m) \
+  ((const type *)(const void *)((const char *)(const void *) \
+  (1 ? (ptr) : &((type *)NULL)->m) - MY_offsetof(type, m)))
+
+/*
+#define Z7_container_of_NON_CONST_FROM_CONST(ptr, type, m) \
+  ((type *)(void *)(const void *)((const char *)(const void *) \
+  (1 ? (ptr) : &((type *)NULL)->m) - MY_offsetof(type, m)))
+*/
 
 #endif
 
-#define CONTAINER_FROM_VTBL_SIMPLE(ptr, type, m) ((type *)(void *)(ptr))
+#define Z7_CONTAINER_FROM_VTBL_SIMPLE(ptr, type, m) ((type *)(void *)(ptr))
 
-/*
-#define CONTAINER_FROM_VTBL(ptr, type, m) CONTAINER_FROM_VTBL_SIMPLE(ptr, type, m)
-*/
-#define CONTAINER_FROM_VTBL(ptr, type, m) MY_container_of(ptr, type, m)
+// #define Z7_CONTAINER_FROM_VTBL(ptr, type, m) Z7_CONTAINER_FROM_VTBL_SIMPLE(ptr, type, m)
+#define Z7_CONTAINER_FROM_VTBL(ptr, type, m) Z7_container_of(ptr, type, m)
+// #define Z7_CONTAINER_FROM_VTBL(ptr, type, m) Z7_container_of_NON_CONST_FROM_CONST(ptr, type, m)
 
-#define CONTAINER_FROM_VTBL_CLS(ptr, type, m) CONTAINER_FROM_VTBL_SIMPLE(ptr, type, m)
+#define Z7_CONTAINER_FROM_VTBL_CONST(ptr, type, m) Z7_container_of_CONST(ptr, type, m)
+
+#define Z7_CONTAINER_FROM_VTBL_CLS(ptr, type, m) Z7_CONTAINER_FROM_VTBL_SIMPLE(ptr, type, m)
 /*
-#define CONTAINER_FROM_VTBL_CLS(ptr, type, m) CONTAINER_FROM_VTBL(ptr, type, m)
+#define Z7_CONTAINER_FROM_VTBL_CLS(ptr, type, m) Z7_CONTAINER_FROM_VTBL(ptr, type, m)
 */
+#if defined (__clang__) || defined(__GNUC__)
+#define Z7_DIAGNOSTIC_IGNORE_BEGIN_CAST_QUAL \
+  _Pragma("GCC diagnostic push") \
+  _Pragma("GCC diagnostic ignored \"-Wcast-qual\"")
+#define Z7_DIAGNOSTIC_IGNORE_END_CAST_QUAL \
+  _Pragma("GCC diagnostic pop")
+#else
+#define Z7_DIAGNOSTIC_IGNORE_BEGIN_CAST_QUAL
+#define Z7_DIAGNOSTIC_IGNORE_END_CAST_QUAL
+#endif
+
+#define Z7_CONTAINER_FROM_VTBL_TO_DECL_VAR(ptr, type, m, p) \
+  Z7_DIAGNOSTIC_IGNORE_BEGIN_CAST_QUAL \
+  type *p = Z7_CONTAINER_FROM_VTBL(ptr, type, m); \
+  Z7_DIAGNOSTIC_IGNORE_END_CAST_QUAL
+
+#define Z7_CONTAINER_FROM_VTBL_TO_DECL_VAR_pp_vt_p(type) \
+  Z7_CONTAINER_FROM_VTBL_TO_DECL_VAR(pp, type, vt, p)
 
 
-#define MY_memset_0_ARRAY(a) memset((a), 0, sizeof(a))
+// #define ZIP7_DECLARE_HANDLE(name)  typedef void *name;
+#define Z7_DECLARE_HANDLE(name)  struct name##_dummy{int unused;}; typedef struct name##_dummy *name;
+
+
+#define Z7_memset_0_ARRAY(a)  memset((a), 0, sizeof(a))
+
+#ifndef Z7_ARRAY_SIZE
+#define Z7_ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]))
+#endif
+
 
 #ifdef _WIN32
 
@@ -527,3 +587,11 @@ struct ISzAlloc
 EXTERN_C_END
 
 #endif
+
+/*
+#ifndef Z7_ST
+#ifdef _7ZIP_ST
+#define Z7_ST
+#endif
+#endif
+*/
