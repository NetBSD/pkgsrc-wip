$NetBSD$

--- build.sh.orig	2016-02-25 00:30:19.839282245 +0000
+++ build.sh
@@ -103,7 +103,7 @@ build_managed_corefx()
     __binclashlog=$__scriptpath/binclash.log
     __binclashloggerdll=$__scriptpath/Tools/Microsoft.DotNet.Build.Tasks.dll
 
-    ReferenceAssemblyRoot=$__referenceassemblyroot $__scriptpath/Tools/corerun $__scriptpath/Tools/MSBuild.exe "$__buildproj" /nologo /verbosity:minimal "/fileloggerparameters:Verbosity=normal;LogFile=$__buildlog" "/l:BinClashLogger,$__binclashloggerdll;LogFile=$__binclashlog" /t:Build /p:OSGroup=$__BuildOS /p:COMPUTERNAME=$(hostname) /p:USERNAME=$(id -un) /p:TestNugetRuntimeId=$__TestNugetRuntimeId $__UnprocessedBuildArgs
+    $__scriptpath/Tools/corerun $__scriptpath/Tools/MSBuild.exe "$__buildproj" /nologo /verbosity:minimal "/fileloggerparameters:Verbosity=normal;LogFile=$__buildlog" /t:Build /p:OSGroup=$__BuildOS /p:COMPUTERNAME=$(hostname) /p:USERNAME=$(id -un) /p:TestNugetRuntimeId=$__TestNugetRuntimeId $__UnprocessedBuildArgs
     BUILDERRORLEVEL=$?
 
     echo
@@ -247,19 +247,6 @@ __BuildOS=$__HostOS
 __BuildType=Debug
 __CMakeArgs=DEBUG
 
-case $__HostOS in
-    FreeBSD)
-        __monoroot=/usr/local
-        ;;
-    OSX)
-        __monoroot=/Library/Frameworks/Mono.framework/Versions/Current
-        ;;
-    *)
-        __monoroot=/usr
-        ;;
-esac
-
-__referenceassemblyroot=$__monoroot/lib/mono/xbuild-frameworks
 BUILDERRORLEVEL=0
 
 # Set the various build properties here so that CMake and MSBuild can pick them up
