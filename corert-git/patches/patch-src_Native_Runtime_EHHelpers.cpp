$NetBSD$

--- src/Native/Runtime/EHHelpers.cpp.orig	2016-01-23 11:26:49.000000000 +0000
+++ src/Native/Runtime/EHHelpers.cpp
@@ -445,7 +445,7 @@ Int32 __stdcall RhpVectoredExceptionHand
         {
             // Get the module handle for this runtime. Do this by passing an address definitely within the
             // module (the address of this function) to GetModuleHandleEx with the "from address" flag.
-            HANDLE hRuntimeModule = PalGetModuleHandleFromPointer(RhpVectoredExceptionHandler);
+            HANDLE hRuntimeModule = PalGetModuleHandleFromPointer(reinterpret_cast<void*>(RhpVectoredExceptionHandler));
             if (!hRuntimeModule)
             {
                 ASSERT_UNCONDITIONALLY("Failed to locate our own module handle");
