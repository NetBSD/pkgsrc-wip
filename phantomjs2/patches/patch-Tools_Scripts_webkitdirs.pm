$NetBSD: patch-Tools_Scripts_webkitdirs.pm,v 1.1 2015/02/23 16:11:07 leot1990 Exp $

* Add NetBSD support

--- src/qt/qtwebkit/Tools/Scripts/webkitdirs.pm.orig	2015-01-24 02:19:52.000000000 +0000
+++ src/qt/qtwebkit/Tools/Scripts/webkitdirs.pm
@@ -355,7 +355,7 @@ sub determineNumberOfCPUs
     } elsif (isWindows() || isCygwin()) {
         # Assumes cygwin
         $numberOfCPUs = `ls /proc/registry/HKEY_LOCAL_MACHINE/HARDWARE/DESCRIPTION/System/CentralProcessor | wc -w`;
-    } elsif (isDarwin() || isFreeBSD()) {
+    } elsif (isDarwin() || isFreeBSD() || isNetBSD()) {
         chomp($numberOfCPUs = `sysctl -n hw.ncpu`);
     }
 }
@@ -1253,6 +1253,11 @@ sub isFreeBSD()
     return ($^O eq "freebsd") || 0;
 }
 
+sub isNetBSD()
+{
+    return ($^O eq "netbsd") || 0;
+}
+
 sub isARM()
 {
     return $Config{archname} =~ /^arm[v\-]/;
