$NetBSD$

--- src/vm/fieldmarshaler.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/vm/fieldmarshaler.cpp
@@ -1329,7 +1329,7 @@ VOID EEClassLayoutInfo::CollectLayoutFie
     {
         ThrowHR(COR_E_TYPELOAD);
     }
-    LayoutRawFieldInfo **pSortArray = (LayoutRawFieldInfo **)_alloca(cbSortArraySize.Value());
+    LayoutRawFieldInfo **pSortArray = (LayoutRawFieldInfo **)Alloca(cbSortArraySize.Value());
     LayoutRawFieldInfo **pSortArrayEnd = pSortArray;
     
     ULONG maxRid = pInternalImport->GetCountWithTokenKind(mdtFieldDef);
@@ -3297,7 +3297,7 @@ VOID FieldMarshaler_FixedStringAnsi::Upd
     if (allocSize < m_numchar)
         ThrowOutOfMemory();
     
-    LPSTR tempbuf = (LPSTR)(_alloca((size_t)allocSize));
+    LPSTR tempbuf = (LPSTR)(Alloca((size_t)allocSize));
     if (!tempbuf)
         ThrowOutOfMemory();
 
@@ -3310,7 +3310,7 @@ VOID FieldMarshaler_FixedStringAnsi::Upd
     if (allocSize < m_numchar)
         ThrowOutOfMemory();
     
-    LPWSTR    wsztemp = (LPWSTR)_alloca( (size_t)allocSize );
+    LPWSTR    wsztemp = (LPWSTR)Alloca( (size_t)allocSize );
     int ncwritten = MultiByteToWideChar(CP_ACP,
                                         MB_PRECOMPOSED,
                                         tempbuf,
