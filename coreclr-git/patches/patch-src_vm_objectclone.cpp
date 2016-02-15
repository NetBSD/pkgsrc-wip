$NetBSD$

--- src/vm/objectclone.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/vm/objectclone.cpp
@@ -1002,7 +1002,7 @@ OBJECTREF ObjectClone::Clone(OBJECTREF r
                 DWORD size = sizeof(IObjRefInstanceInfo) + (currObjFixupInfo ? currObjFixupInfo->GetSize() : 0);
                 if (size > dwCurrStackSpaceSize)
                 {
-                    pTempStackSpace = _alloca(size);
+                    pTempStackSpace = Alloca(size);
                     dwCurrStackSpaceSize = size;
                 }
                 IObjRefInstanceInfo *pIORInfo = new (pTempStackSpace) IObjRefInstanceInfo(currID, 0, 0);
@@ -1040,7 +1040,7 @@ OBJECTREF ObjectClone::Clone(OBJECTREF r
                 DWORD size = sizeof(ValueTypeInfo) + currObjFixupInfo->GetSize();
                 if (size > dwCurrStackSpaceSize)
                 {
-                    pTempStackSpace = _alloca(size);
+                    pTempStackSpace = Alloca(size);
                     dwCurrStackSpaceSize = size;
                 }
                 ValueTypeInfo *valInfo = new (pTempStackSpace) ValueTypeInfo(currID, currObjFixupInfo);
@@ -1496,7 +1496,7 @@ void ObjectClone::AllocateArray()
     TypeHandle __arrayTh = ClassLoader::LoadArrayTypeThrowing(__elemTh, __rank == 1 ? ELEMENT_TYPE_SZARRAY : ELEMENT_TYPE_ARRAY, __rank);
 
     DWORD __numArgs =  __rank*2;
-    INT32* __args = (INT32*) _alloca(sizeof(INT32)*__numArgs);
+    INT32* __args = (INT32*) Alloca(sizeof(INT32)*__numArgs);
 
     if (__arrayTh.AsArray()->GetInternalCorElementType() == ELEMENT_TYPE_ARRAY)
     {
@@ -2743,8 +2743,8 @@ void ObjectClone::ScanArrayMembers()
     DWORD rank                   = pArrayMT->GetRank();
     DWORD dwOffset               = 0;
 
-    DWORD *pIndices = (DWORD*) _alloca(sizeof(DWORD) * rank);
-    VOID *pTemp = _alloca(sizeof(NDimArrayMemberInfo) + rank * sizeof(DWORD));
+    DWORD *pIndices = (DWORD*) Alloca(sizeof(DWORD) * rank);
+    VOID *pTemp = Alloca(sizeof(NDimArrayMemberInfo) + rank * sizeof(DWORD));
     NDimArrayMemberInfo *pArrInfo = new (pTemp) NDimArrayMemberInfo(rank);
     
     bool boxingObjects = (pArrayMT->GetArrayElementType() == ELEMENT_TYPE_VALUETYPE);
@@ -3784,7 +3784,7 @@ void ObjectClone::InvokeVtsCallbacks(OBJ
 
     // Allocate an array to hold the methods to invoke (we do this because the invocation order is the opposite way round from the
     // way we can easily scan for the methods). We can easily optimize this for the single callback case though.
-    MethodDesc **pCallbacks = cMethods == 1 ? &pLastCallback : (MethodDesc**)_alloca(cMethods * sizeof(MethodDesc*));
+    MethodDesc **pCallbacks = cMethods == 1 ? &pLastCallback : (MethodDesc**)Alloca(cMethods * sizeof(MethodDesc*));
 
     if (cMethods > 1)
     {
