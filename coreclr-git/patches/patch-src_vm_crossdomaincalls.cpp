$NetBSD$

--- src/vm/crossdomaincalls.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/vm/crossdomaincalls.cpp
@@ -1243,7 +1243,7 @@ CrossDomainChannel::BlitAndCall()
         // since the srvObject is in the server domain and the TPMethodFrame m_pFrame is in the client domain.
         // I don't think we need to protect the srvOjbect in this case, since it's reachable from the transparent
         // proxy, which is protected by the TPMethodFrame.
-        SIZE_T* pTmpStackArgs = (SIZE_T*)_alloca(m_numStackSlotsToCopy * sizeof(SIZE_T));
+        SIZE_T* pTmpStackArgs = (SIZE_T*)Alloca(m_numStackSlotsToCopy * sizeof(SIZE_T));
         memcpy(pTmpStackArgs, pStackArgs, m_numStackSlotsToCopy * sizeof(SIZE_T));
         pStackArgs = pTmpStackArgs;
 
@@ -1571,10 +1571,10 @@ void CrossDomainChannel::MarshalAndCall_
 
     // And a variable sized array and frame of marshaled arg GC references.
     OBJECTREF *pServerArgArray = NULL;
-    pServerArgArray = (OBJECTREF *) _alloca(pArgs->dwNumObjectsMarshalled * sizeof(OBJECTREF));
+    pServerArgArray = (OBJECTREF *) Alloca(pArgs->dwNumObjectsMarshalled * sizeof(OBJECTREF));
     ZeroMemory(pServerArgArray, sizeof(OBJECTREF) * pArgs->dwNumObjectsMarshalled);
 
-    TypeHandle* pServerArgTH = (TypeHandle *) _alloca(pArgs->dwNumObjectsMarshalled * sizeof(TypeHandle));
+    TypeHandle* pServerArgTH = (TypeHandle *) Alloca(pArgs->dwNumObjectsMarshalled * sizeof(TypeHandle));
     GCPROTECT_ARRAY_BEGIN(pServerArgArray[0], pArgs->dwNumObjectsMarshalled);
 
     // Initialize server side info, such as method address etc
@@ -1740,9 +1740,9 @@ void CrossDomainChannel::MarshalAndCall_
             if (pMT->IsStructRequiringStackAllocRetBuf())
             {
                 SIZE_T sz = pMT->GetNumInstanceFieldBytes();
-                pvRetBuff = _alloca(sz);
+                pvRetBuff = Alloca(sz);
                 memset(pvRetBuff, 0, sz);
-                pValueClasses = new (_alloca(sizeof(ValueClassInfo))) ValueClassInfo(pvRetBuff, pMT, pValueClasses);
+                pValueClasses = new (Alloca(sizeof(ValueClassInfo))) ValueClassInfo(pvRetBuff, pMT, pValueClasses);
             }
             else
             {
@@ -2094,21 +2094,21 @@ CrossDomainChannel::MarshalAndCall()
 #endif // _TARGET_X86_
 
     // pArgAttribs tell where the marshalled objects should go, where they need unboxing etc
-    pArgAttribs = (DWORD*) _alloca(dwNumArgs * sizeof(DWORD));
+    pArgAttribs = (DWORD*) Alloca(dwNumArgs * sizeof(DWORD));
     ZeroMemory(pArgAttribs, sizeof(DWORD) * dwNumArgs);
     // pThByRefs has the typehandles of the by-ref args
-    pThByRefs = (TypeHandle *)_alloca(dwNumArgs * sizeof(TypeHandle));
+    pThByRefs = (TypeHandle *)Alloca(dwNumArgs * sizeof(TypeHandle));
     ZeroMemory(pThByRefs, sizeof(TypeHandle) *dwNumArgs);
     // pByRefArgAttribs tell where the by-ref args should go, after the call
-    pByRefArgAttribs = (int*) _alloca(dwNumArgs * sizeof(int));
+    pByRefArgAttribs = (int*) Alloca(dwNumArgs * sizeof(int));
     ZeroMemory(pByRefArgAttribs, sizeof(int) * dwNumArgs);
     // bMarshalledArgs is a bunch of flags that tell which args were marshalled
-    bMarshalledArgs = (BOOL*) _alloca(dwNumArgs * sizeof(BOOL));
+    bMarshalledArgs = (BOOL*) Alloca(dwNumArgs * sizeof(BOOL));
     ZeroMemory(bMarshalledArgs, sizeof(BOOL) * dwNumArgs);
 
     // pArgArray contains marshalled objects on the client side
     OBJECTREF *pClientArgArray = NULL;
-    pClientArgArray = (OBJECTREF *) _alloca(dwNumArgs * sizeof(OBJECTREF));
+    pClientArgArray = (OBJECTREF *) Alloca(dwNumArgs * sizeof(OBJECTREF));
     ZeroMemory(pClientArgArray, sizeof(OBJECTREF) * dwNumArgs);
     GCPROTECT_ARRAY_BEGIN(pClientArgArray[0], dwNumArgs);
 
@@ -2122,7 +2122,7 @@ CrossDomainChannel::MarshalAndCall()
     // spans registers and the stack.
     cbStackArgs += sizeof(ArgumentRegisters);
 #endif
-    SIZE_T *pStackArgs = (SIZE_T*)_alloca(cbStackArgs);
+    SIZE_T *pStackArgs = (SIZE_T*)Alloca(cbStackArgs);
     ZeroMemory(pStackArgs, cbStackArgs);
 #ifdef CALLDESCR_ARGREGS
     SIZE_T *pRegArgs = pStackArgs;
