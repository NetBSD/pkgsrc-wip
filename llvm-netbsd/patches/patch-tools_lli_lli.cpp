$NetBSD$

--- tools/lli/lli.cpp.orig	2017-08-03 18:13:30.000000000 +0000
+++ tools/lli/lli.cpp
@@ -568,9 +568,6 @@ int main(int argc, char **argv, char * c
     // Trigger compilation separately so code regions that need to be
     // invalidated will be known.
     (void)EE->getPointerToFunction(EntryFn);
-    // Clear instruction cache before code will be executed.
-    if (RTDyldMM)
-      static_cast<SectionMemoryManager*>(RTDyldMM)->invalidateInstructionCache();
 
     // Run main.
     Result = EE->runFunctionAsMain(EntryFn, InputArgv, envp);
