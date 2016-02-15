$NetBSD$

--- src/vm/gchelpers.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/vm/gchelpers.cpp
@@ -700,7 +700,7 @@ OBJECTREF   DupArrayForCloning(BASEARRAY
     unsigned rank = arrayType.GetRank();
 
     DWORD numArgs =  rank*2;
-    INT32* args = (INT32*) _alloca(sizeof(INT32)*numArgs);
+    INT32* args = (INT32*) Alloca(sizeof(INT32)*numArgs);
 
     if (arrayType.GetInternalCorElementType() == ELEMENT_TYPE_ARRAY)
     {
