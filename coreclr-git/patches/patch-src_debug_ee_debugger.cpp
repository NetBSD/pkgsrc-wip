$NetBSD$

--- src/debug/ee/debugger.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/debug/ee/debugger.cpp
@@ -12341,7 +12341,7 @@ TypeHandle Debugger::TypeDataWalk::ReadI
     {
         ThrowHR(COR_E_OVERFLOW);
     }
-    TypeHandle * inst = (TypeHandle *) _alloca(dwAllocSize);
+    TypeHandle * inst = (TypeHandle *) Alloca(dwAllocSize);
     ReadTypeHandles(nTypeArgs, inst) ;
     TypeHandle th = g_pEEInterface->LoadInstantiation(pModule, tok, nTypeArgs, inst);
     if (th.IsNull())
@@ -12408,7 +12408,7 @@ TypeHandle Debugger::TypeDataWalk::ReadT
                 _ASSERTE(COR_E_OVERFLOW);
                 cbAllocSize = UINT_MAX;
             }
-            TypeHandle * inst = (TypeHandle *) _alloca(cbAllocSize);
+            TypeHandle * inst = (TypeHandle *) Alloca(cbAllocSize);
             ReadTypeHandles(data->numTypeArgs, inst) ;
             th = g_pEEInterface->LoadFnptrType(inst, data->numTypeArgs);
             break;
