$NetBSD$

--- src/debug/di/rstype.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/debug/di/rstype.cpp
@@ -976,7 +976,7 @@ CordbType::SigToType(CordbModule * pModu
                 IfFailRet(E_OUTOFMEMORY);
             }
 
-            CordbType ** ppTypeInstantiations = reinterpret_cast<CordbType **>(_alloca( allocSize.Value()));
+            CordbType ** ppTypeInstantiations = reinterpret_cast<CordbType **>(Alloca( allocSize.Value()));
 
             for (unsigned int i = 0; i < cArgs;i++) 
             {
@@ -1082,7 +1082,7 @@ CordbType::SigToType(CordbModule * pModu
                 IfFailRet(E_OUTOFMEMORY);
             }
 
-            CordbType ** ppTypeInstantiations = (CordbType **) _alloca( allocSize.Value() );
+            CordbType ** ppTypeInstantiations = (CordbType **) Alloca( allocSize.Value() );
 
             for (unsigned int i = 0; i <= cArgs; i++) 
             {
