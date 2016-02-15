$NetBSD$

--- src/vm/i386/gmsx86.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/vm/i386/gmsx86.cpp
@@ -398,7 +398,7 @@ void LazyMachState::unwindLazyState(Lazy
 #ifdef _DEBUG
     int count = 0;
     const DWORD cInstructions = 1000;
-    PTR_BYTE *instructionBytes = (PTR_BYTE*)alloca(cInstructions * sizeof(PTR_BYTE));
+    PTR_BYTE *instructionBytes = (PTR_BYTE*)Alloca(cInstructions * sizeof(PTR_BYTE));
     memset(instructionBytes, 0, cInstructions * sizeof(PTR_BYTE));
 #endif
     bool bset16bit=false;
