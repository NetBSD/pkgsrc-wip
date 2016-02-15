$NetBSD$

--- src/vm/runtimehandles.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/vm/runtimehandles.cpp
@@ -2874,7 +2874,7 @@ FCIMPL3(MethodDesc*, RuntimeMethodHandle
             size_t size = ntypars * sizeof(TypeHandle);
             if ((size / sizeof(TypeHandle)) != ntypars) // uint over/underflow
                 COMPlusThrow(kArgumentException);
-            inst = (TypeHandle*) _alloca(size);        
+            inst = (TypeHandle*) Alloca(size);
 
             for (DWORD i = 0; i < ntypars; i++) 
             {
