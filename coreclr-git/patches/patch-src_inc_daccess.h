$NetBSD$

--- src/inc/daccess.h.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/inc/daccess.h
@@ -1820,7 +1820,7 @@ typedef __VoidPtr PTR_CVOID;
 #define VPTR_ANY_CLASS_METHODS(name)                            \
         virtual ULONG32 VPtrSize(void) { SUPPORTS_DAC; return sizeof(name); } \
         static PVOID VPtrHostVTable() {                         \
-            void * pBuf = _alloca(sizeof(name));                \
+            void * pBuf = Alloca(sizeof(name));                \
             name * dummy = new (pBuf) name((TADDR)0, (TADDR)0); \
             return *((PVOID*)dummy); }
 
