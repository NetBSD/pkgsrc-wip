$NetBSD$

--- src/vm/callhelpers.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/vm/callhelpers.cpp
@@ -473,7 +473,7 @@ ARG_SLOT MethodDescCallSite::CallTargetW
         // Note that SizeOfFrameArgumentArray does overflow checks with sufficient margin to prevent overflows here
         DWORD dwAllocaSize = TransitionBlock::GetNegSpaceSize() + sizeof(TransitionBlock) + nStackBytes;
 
-        LPBYTE pAlloc = (LPBYTE)_alloca(dwAllocaSize);
+        LPBYTE pAlloc = (LPBYTE)Alloca(dwAllocaSize);
 
         pTransitionBlock = pAlloc + TransitionBlock::GetNegSpaceSize();
 
