$NetBSD$

--- src/utilcode/sxshelpers.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/utilcode/sxshelpers.cpp
@@ -1483,7 +1483,7 @@ HRESULT GetApplicationPathFromWin32Manif
         if (GetLastError() == ERROR_INSUFFICIENT_BUFFER) 
         {
            
-            pInfo = (ACTIVATION_CONTEXT_DETAILED_INFORMATION*) alloca(nCount);
+            pInfo = (ACTIVATION_CONTEXT_DETAILED_INFORMATION*) Alloca(nCount);
             
             if (WszQueryActCtxW(0, hActCtx, NULL, ActivationContextDetailedInformation, 
                                 pInfo, nCount, &nCount) &&
