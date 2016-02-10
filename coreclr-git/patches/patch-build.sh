$NetBSD$

--- build.sh.orig	2016-02-09 22:37:14.000000000 +0000
+++ build.sh
@@ -1,10 +1,10 @@
-#!/usr/bin/env bash
+#!/usr/pkg/bin/bash
 
 PYTHON=${PYTHON:-python}
 
 usage()
 {
-    echo "Usage: $0 [BuildArch] [BuildType] [clean] [verbose] [coverage] [cross] [clangx.y] [ninja] [configureonly] [skipconfigure] [skipnative] [skipmscorlib] [skiptests]"
+    echo "Usage: $0 [BuildArch] [BuildType] [clean] [verbose] [coverage] [cross] [clangx.y] [ninja] [configureonly] [skipconfigure] [skipnative] [skipmscorlib] [skiptests] [cmakeargs]"
     echo "BuildArch can be: x64, x86, arm, arm64"
     echo "BuildType can be: Debug, Checked, Release"
     echo "clean - optional argument to force a clean build."
@@ -19,6 +19,7 @@ usage()
     echo "skipnative - do not build native components."
     echo "skipmscorlib - do not build mscorlib.dll even if mono is installed."
     echo "skiptests - skip the tests in the 'tests' subdirectory."
+    echo "cmakeargs - user-settable additional arguments passed to CMake."
 
     exit 1
 }
@@ -142,8 +143,8 @@ build_coreclr()
 
     if [ $__SkipConfigure == 0 ]; then
         # Regenerate the CMake solution
-        echo "Invoking \"$__ProjectRoot/src/pal/tools/gen-buildsys-clang.sh\" \"$__ProjectRoot\" $__ClangMajorVersion $__ClangMinorVersion $__BuildArch $__BuildType $__CodeCoverage $__IncludeTests $generator"
-        "$__ProjectRoot/src/pal/tools/gen-buildsys-clang.sh" "$__ProjectRoot" $__ClangMajorVersion $__ClangMinorVersion $__BuildArch $__BuildType $__CodeCoverage $__IncludeTests $generator
+        echo "Invoking \"$__ProjectRoot/src/pal/tools/gen-buildsys-clang.sh\" \"$__ProjectRoot\" $__ClangMajorVersion $__ClangMinorVersion $__BuildArch $__BuildType $__CodeCoverage $__IncludeTests $generator $__cmakeargs"
+        "$__ProjectRoot/src/pal/tools/gen-buildsys-clang.sh" "$__ProjectRoot" $__ClangMajorVersion $__ClangMinorVersion $__BuildArch $__BuildType $__CodeCoverage $__IncludeTests $generator "$__cmakeargs"
     fi
 
     if [ $__SkipCoreCLR == 1 ]; then
@@ -381,6 +382,7 @@ __ClangMinorVersion=5
 __MSBuildPath=$__ProjectRoot/Tools/MSBuild.exe
 __NuGetPath="$__PackagesDir/NuGet.exe"
 __DistroName=""
+__cmakeargs=""
 
 for i in "$@"
 do
@@ -486,6 +488,13 @@ do
             __IncludeTests=
             ;;
 
+        cmakeargs)
+            shift
+            __cmakeargs="$1"
+            echo "Mam! cmakeargs"
+            echo "wartosc: $__cmakeargs"
+            ;;
+
         *)
             __UnprocessedBuildArgs="$__UnprocessedBuildArgs $i"
             ;;
