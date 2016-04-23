$NetBSD$

--- run-test.sh.orig	2016-04-20 18:37:43.000000000 +0000
+++ run-test.sh
@@ -185,9 +185,9 @@ run_test()
 
   echo
   echo "Running tests in $dirName"
-  echo "./corerun xunit.console.netcore.exe $testProject.dll -xml testResults.xml -notrait category=failing $OuterLoop $IgnoreForCI -notrait category=$xunitOSCategory -notrait Benchmark=true"
+  echo "timeout -s SIGKILL 15m ./corerun xunit.console.netcore.exe $testProject.dll -xml testResults.xml -notrait category=failing $OuterLoop $IgnoreForCI -notrait category=$xunitOSCategory -notrait Benchmark=true"
   echo
-  ./corerun xunit.console.netcore.exe "$testProject.dll" -xml testResults.xml -notrait category=failing $OuterLoop $IgnoreForCI -notrait category=$xunitOSCategory -notrait Benchmark=true
+  timeout -s SIGKILL 15m ./corerun xunit.console.netcore.exe "$testProject.dll" -xml testResults.xml -notrait category=failing $OuterLoop $IgnoreForCI -notrait category=$xunitOSCategory -notrait Benchmark=true
   exitCode=$?
 
   if [ $exitCode -ne 0 ]
