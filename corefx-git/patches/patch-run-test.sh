$NetBSD$

--- run-test.sh.orig	2016-02-28 15:39:48.000000000 +0000
+++ run-test.sh
@@ -184,7 +184,7 @@ runtest()
 
   echo
   echo "Running tests in $dirName"
-  echo "./corerun xunit.console.netcore.exe $testDllName -xml testResults.xml -notrait category=failing -notrait category=OuterLoop -notrait category=$xunitOSCategory" -notrait Benchmark=true
+  echo "timeout 15m ./corerun xunit.console.netcore.exe $testDllName -xml testResults.xml -notrait category=failing -notrait category=OuterLoop -notrait category=$xunitOSCategory" -notrait Benchmark=true
   echo
   ./corerun xunit.console.netcore.exe $testDllName -xml testResults.xml -notrait category=failing -notrait category=OuterLoop -notrait category=$xunitOSCategory -notrait Benchmark=true
   exitCode=$?
