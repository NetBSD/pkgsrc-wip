$NetBSD$

--- lib/Transforms/Instrumentation/InstrProfiling.cpp.orig	2018-08-20 14:06:28.441231794 +0000
+++ lib/Transforms/Instrumentation/InstrProfiling.cpp
@@ -701,6 +701,7 @@ static bool needsRuntimeRegistrationOfSe
   // Use linker script magic to get data/cnts/name start/end.
   if (Triple(M.getTargetTriple()).isOSLinux() ||
       Triple(M.getTargetTriple()).isOSFreeBSD() ||
+      Triple(M.getTargetTriple()).isOSNetBSD() ||
       Triple(M.getTargetTriple()).isOSFuchsia() ||
       Triple(M.getTargetTriple()).isPS4CPU())
     return false;
