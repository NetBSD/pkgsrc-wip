$NetBSD$

--- src/debug/di/rsappdomain.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/debug/di/rsappdomain.cpp
@@ -1029,7 +1029,7 @@ HRESULT CordbAppDomain::GetFunctionPoint
         return E_INVALIDARG;
     }
 
-    CordbType ** ppTypeInstantiations = reinterpret_cast<CordbType **>(_alloca(allocSize.Value()));
+    CordbType ** ppTypeInstantiations = reinterpret_cast<CordbType **>(Alloca(allocSize.Value()));
 
     for (unsigned int i = 0; i < cTypeArgs; i++)
     {
