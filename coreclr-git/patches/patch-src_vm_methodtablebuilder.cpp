$NetBSD$

--- src/vm/methodtablebuilder.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/vm/methodtablebuilder.cpp
@@ -6867,7 +6867,7 @@ VOID MethodTableBuilder::PlaceInterfaceD
         
         // We have to MethodImpl all interface duplicates as all duplicates are 'declared on type' (see 
         // code:#InjectInterfaceDuplicates_ApproxInterfaces)
-        DispatchMapTypeID * rgDispatchMapTypeIDs = (DispatchMapTypeID *)_alloca(sizeof(DispatchMapTypeID) * cInterfaceDuplicates);
+        DispatchMapTypeID * rgDispatchMapTypeIDs = (DispatchMapTypeID *)Alloca(sizeof(DispatchMapTypeID) * cInterfaceDuplicates);
         ComputeDispatchMapTypeIDs(
             pDeclMT, 
             &pDecl->GetMethodSignature().GetSubstitution(), 
@@ -9428,7 +9428,7 @@ MethodTableBuilder::LoadExactInterfaceMa
     // (d) If no duplicates then we can use the computed interface map we've created
     // (e) If duplicates found then use the slow metadata-based technique code:#LoadExactInterfaceMap_Algorithm2
     DWORD nInterfacesCount = pMT->GetNumInterfaces();
-    MethodTable **pExactMTs = (MethodTable**) _alloca(sizeof(MethodTable *) * nInterfacesCount);
+    MethodTable **pExactMTs = (MethodTable**) Alloca(sizeof(MethodTable *) * nInterfacesCount);
     DWORD nAssigned = 0;
     BOOL duplicates = false;
     if (pParentMT != NULL)
