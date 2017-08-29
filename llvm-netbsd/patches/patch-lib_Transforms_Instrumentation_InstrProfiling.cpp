$NetBSD$

--- lib/Transforms/Instrumentation/InstrProfiling.cpp.orig	2017-06-17 16:34:37.000000000 +0000
+++ lib/Transforms/Instrumentation/InstrProfiling.cpp
@@ -394,6 +394,7 @@ static bool needsRuntimeRegistrationOfSe
   // Use linker script magic to get data/cnts/name start/end.
   if (Triple(M.getTargetTriple()).isOSLinux() ||
       Triple(M.getTargetTriple()).isOSFreeBSD() ||
+      Triple(M.getTargetTriple()).isOSNetBSD() ||
       Triple(M.getTargetTriple()).isPS4CPU())
     return false;
 
