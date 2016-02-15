$NetBSD$

--- src/vm/invokeutil.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/vm/invokeutil.cpp
@@ -565,7 +565,7 @@ OBJECTREF InvokeUtil::GetBoxedObject(Typ
     // Save off the data.  We are going to create and object
     //  which may cause GC to occur.
     int size = pMethTable->GetNumInstanceFieldBytes();
-    void *p = _alloca(size);
+    void *p = Alloca(size);
     memcpy(p, pData, size);
     OBJECTREF retO = pMethTable->Box(p);
     return retO;
@@ -1170,7 +1170,7 @@ void InvokeUtil::SetValidField(CorElemen
             else if (val == NULL) {
                 // Null is the universal null object.  (Is this a good idea?)
                 int size = pMT->GetNumInstanceFieldBytes();
-                valueData = _alloca(size);
+                valueData = Alloca(size);
                 memset(valueData, 0, size);
             }
             else 
