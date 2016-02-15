$NetBSD$

--- src/debug/di/rsclass.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/debug/di/rsclass.cpp
@@ -405,7 +405,7 @@ HRESULT CordbClass::GetParameterizedType
 
     // Note: casting from (ICorDebugType **) to (CordbType **) is not valid.
     // Offsets may differ.  Copy and validate the type array.
-    CordbType ** ppArgTypes = reinterpret_cast<CordbType **>(_alloca( allocSize.Value()));
+    CordbType ** ppArgTypes = reinterpret_cast<CordbType **>(Alloca( allocSize.Value()));
 
     for (unsigned int i = 0; i < cTypeArgs; i++)
     {
