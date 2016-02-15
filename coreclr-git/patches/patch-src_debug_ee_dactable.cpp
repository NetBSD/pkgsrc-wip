$NetBSD$

--- src/debug/ee/dactable.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/debug/ee/dactable.cpp
@@ -69,13 +69,13 @@ void DacGlobals::InitializeEntries(TADDR
 
 #define VPTR_CLASS(name) \
     { \
-        void *pBuf = _alloca(sizeof(name)); \
+        void *pBuf = Alloca(sizeof(name)); \
         name *dummy = new (pBuf) name(0); \
         name##__vtAddr = PTR_TO_TADDR(*((PVOID*)dummy)) - baseAddress; \
     }
 #define VPTR_MULTI_CLASS(name, keyBase) \
     { \
-        void *pBuf = _alloca(sizeof(name)); \
+        void *pBuf = Alloca(sizeof(name)); \
         name *dummy = new (pBuf) name(0); \
         name##__##keyBase##__mvtAddr = PTR_TO_TADDR(*((PVOID*)dummy)) - baseAddress; \
     }
