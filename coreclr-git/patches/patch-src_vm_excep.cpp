$NetBSD$

--- src/vm/excep.cpp.orig	2016-02-08 23:48:23.000000000 +0000
+++ src/vm/excep.cpp
@@ -6643,7 +6643,7 @@ static STRINGREF MissingMemberException_
         return StringObject::NewString("Unknown signature");
     }
 
-    psig = (const BYTE*)_alloca(csig);
+    psig = (const BYTE*)Alloca(csig);
     CopyMemory((BYTE*)psig,
                (*ppPersistedSig)->GetDirectPointerToNonObjectElements(),
                csig);
