$NetBSD$

--- run-test.sh.orig	2016-03-02 23:13:05.000000000 +0000
+++ run-test.sh
@@ -184,9 +184,9 @@ runtest()
 
   echo
   echo "Running tests in $dirName"
-  echo "./corerun xunit.console.netcore.exe $testDllName -xml testResults.xml -notrait category=failing $OuterLoop -notrait category=$xunitOSCategory" -notrait Benchmark=true
+  echo "timeout -s SIGKILL 15m ./corerun xunit.console.netcore.exe $testDllName -xml testResults.xml -notrait category=failing $OuterLoop -notrait category=$xunitOSCategory" -notrait Benchmark=true
   echo
-  ./corerun xunit.console.netcore.exe $testDllName -xml testResults.xml -notrait category=failing $OuterLoop -notrait category=$xunitOSCategory -notrait Benchmark=true
+  timeout -s SIGKILL 15m ./corerun xunit.console.netcore.exe $testDllName -xml testResults.xml -notrait category=failing $OuterLoop -notrait category=$xunitOSCategory -notrait Benchmark=true
   exitCode=$?
 
   if [ $exitCode -ne 0 ]
