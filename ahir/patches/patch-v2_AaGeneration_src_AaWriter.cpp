$NetBSD$

llvm 17 to 19 migration, patch shared upstream

--- v2/AaGeneration/src/AaWriter.cpp.orig	2025-09-12 13:36:48.000000000 +0000
+++ v2/AaGeneration/src/AaWriter.cpp
@@ -1443,12 +1443,12 @@ namespace {
 			if(called_function != NULL)
 			{ 
 				StringRef fname = called_function->getName();
-				if(fname.equals("__loop_pipelining_on__"))
+				if(fname == "__loop_pipelining_on__")
 				{
 					std::cerr << "Info: ignoring call to special function __loop_pipelining_on__." << std::endl;
 					return;
 				}
-				if(fname.equals("__aa_barrier__"))
+				if(fname == "__aa_barrier__")
 				{
 					std::cerr << "Info: saw special function __aa_barrier__." << std::endl;
 					std::cout << "$barrier " << std::endl;
