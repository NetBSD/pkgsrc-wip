$NetBSD$

--- lib/Transforms/Instrumentation/InstrProfiling.cpp.orig	2017-12-08 18:49:41.938921680 +0000
+++ lib/Transforms/Instrumentation/InstrProfiling.cpp
@@ -670,6 +670,7 @@ static bool needsRuntimeRegistrationOfSe
   // Use linker script magic to get data/cnts/name start/end.
   if (Triple(M.getTargetTriple()).isOSLinux() ||
       Triple(M.getTargetTriple()).isOSFreeBSD() ||
+      Triple(M.getTargetTriple()).isOSNetBSD() ||
       Triple(M.getTargetTriple()).isPS4CPU())
     return false;
 
