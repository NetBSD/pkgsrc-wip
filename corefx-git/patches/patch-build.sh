$NetBSD$

--- build.sh.orig	2016-03-02 23:13:05.000000000 +0000
+++ build.sh
@@ -2,7 +2,7 @@
 
 usage()
 {
-    echo "Usage: $0 [managed] [native] [BuildArch] [BuildType] [clean] [verbose] [clangx.y] [platform] [cross]"
+    echo "Usage: $0 [managed] [native] [BuildArch] [BuildType] [clean] [verbose] [clangx.y] [platform] [cross] [cmakeargs]"
     echo "managed - optional argument to build the managed code"
     echo "native - optional argument to build the native code"
     echo "The following arguments affect native builds only:"
@@ -14,6 +14,7 @@ usage()
     echo "platform can be: FreeBSD, Linux, NetBSD, OSX, Windows"
     echo "cross - optional argument to signify cross compilation,"
     echo "      - will use ROOTFS_DIR environment variable if set."
+    echo "cmakeargs - user-settable additional arguments passed to CMake."
     exit 1
 }
 
@@ -122,8 +123,8 @@ build_native_corefx()
     cd "$__IntermediatesDir"
 
     # Regenerate the CMake solution
-    echo "Invoking cmake with arguments: \"$__nativeroot\" $__CMakeArgs"
-    "$__nativeroot/gen-buildsys-clang.sh" "$__nativeroot" $__ClangMajorVersion $__ClangMinorVersion $__BuildArch $__CMakeArgs
+    echo "Invoking cmake with arguments: \"$__nativeroot\" $__CMakeArgs $__cmakeextraargs"
+    "$__nativeroot/gen-buildsys-clang.sh" "$__nativeroot" $__ClangMajorVersion $__ClangMinorVersion $__BuildArch $__CMakeArgs "$__cmakeextraargs"
 
     # Check that the makefiles were created.
 
@@ -247,6 +248,7 @@ esac
 __BuildOS=$__HostOS
 __BuildType=Debug
 __CMakeArgs=DEBUG
+__cmakeextraargs=""
 
 BUILDERRORLEVEL=0
 
@@ -258,20 +260,26 @@ __VerboseBuild=false
 __ClangMajorVersion=3
 __ClangMinorVersion=5
 
-for i in "$@"
-    do
-        lowerI="$(echo $i | awk '{print tolower($0)}')"
-        case $lowerI in
+while :; do
+    if [ $# -le 0 ]; then
+        break
+    fi
+
+    lowerI="$(echo $1 | awk '{print tolower($0)}')"
+    case $lowerI in
         -?|-h|--help)
             usage
             exit 1
             ;;
+
         managed)
             __buildmanaged=true
             ;;
+
         native)
             __buildnative=true
             ;;
+
         x86)
             __BuildArch=x86
             ;;
@@ -291,32 +299,40 @@ for i in "$@"
         debug)
             __BuildType=Debug
             ;;
+
         release)
             __BuildType=Release
             __CMakeArgs=RELEASE
             ;;
+
         clean)
             __CleanBuild=1
             ;;
+
         verbose)
             __VerboseBuild=1
             ;;
+
         clang3.5)
             __ClangMajorVersion=3
             __ClangMinorVersion=5
             ;;
+
         clang3.6)
             __ClangMajorVersion=3
             __ClangMinorVersion=6
             ;;
+
         clang3.7)
             __ClangMajorVersion=3
             __ClangMinorVersion=7
             ;;
+
         freebsd)
             __BuildOS=FreeBSD
             __TestNugetRuntimeId=osx.10.10-x64
             ;;
+
         linux)
             __BuildOS=Linux
             # If the Host OS is also Linux, then use the RID of the host.
@@ -325,24 +341,41 @@ for i in "$@"
                 __TestNugetRuntimeId=ubuntu.14.04-x64
             fi
             ;;
+
         netbsd)
             __BuildOS=NetBSD
             __TestNugetRuntimeId=osx.10.10-x64
             ;;
+
         osx)
             __BuildOS=OSX
             __TestNugetRuntimeId=osx.10.10-x64
             ;;
+
         windows)
             __BuildOS=Windows_NT
             __TestNugetRuntimeId=win7-x64
             ;;
+
         cross)
             __CrossBuild=1
             ;;
+
+        cmakeargs)
+            if [ -n "$2" ]; then
+                __cmakeargs="$2"
+                shift
+            else
+                echo "ERROR: 'cmakeargs' requires a non-empty option argument"
+                exit 1
+            fi
+            ;;
+
         *)
-          __UnprocessedBuildArgs="$__UnprocessedBuildArgs $i"
+          __UnprocessedBuildArgs="$__UnprocessedBuildArgs $1"
     esac
+
+    shift
 done
 
 # If neither managed nor native are passed as arguments, default to building both
