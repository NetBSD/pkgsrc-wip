$NetBSD$

--- src/vm/class.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/vm/class.cpp
@@ -321,15 +321,15 @@ VOID EEClass::FixupFieldDescForEnC(Metho
 
     MethodTableBuilder::bmtMetaDataInfo bmtMetaData;
     bmtMetaData.cFields = 1;
-    bmtMetaData.pFields = (mdToken*)_alloca(sizeof(mdToken));
+    bmtMetaData.pFields = (mdToken*)Alloca(sizeof(mdToken));
     bmtMetaData.pFields[0] = fieldDef;
-    bmtMetaData.pFieldAttrs = (DWORD*)_alloca(sizeof(DWORD));
+    bmtMetaData.pFieldAttrs = (DWORD*)Alloca(sizeof(DWORD));
     IfFailThrow(pImport->GetFieldDefProps(fieldDef, &bmtMetaData.pFieldAttrs[0]));
     
     MethodTableBuilder::bmtMethAndFieldDescs bmtMFDescs;
     // We need to alloc the memory, but don't have to fill it in.  InitializeFieldDescs
     // will copy pFD (1st arg) into here.
-    bmtMFDescs.ppFieldDescList = (FieldDesc**)_alloca(sizeof(FieldDesc*));
+    bmtMFDescs.ppFieldDescList = (FieldDesc**)Alloca(sizeof(FieldDesc*));
 
     MethodTableBuilder::bmtFieldPlacement bmtFP;
 
@@ -362,7 +362,7 @@ VOID EEClass::FixupFieldDescForEnC(Metho
     
     // We shouldn't have to fill this in b/c we're not allowed to EnC value classes, or
     // anything else with layout info associated with it.
-    LayoutRawFieldInfo *pLayoutRawFieldInfos = (LayoutRawFieldInfo*)_alloca((2) * sizeof(LayoutRawFieldInfo));
+    LayoutRawFieldInfo *pLayoutRawFieldInfos = (LayoutRawFieldInfo*)Alloca((2) * sizeof(LayoutRawFieldInfo));
 
     // If not NULL, it means there are some by-value fields, and this contains an entry for each instance or static field,
     // which is NULL if not a by value field, and points to the EEClass of the field if a by value field.  Instance fields
