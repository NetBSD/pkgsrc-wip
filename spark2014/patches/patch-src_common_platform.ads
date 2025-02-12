$NetBSD: patch-src_common_platform.ads,v 1.0 2024/05/19 22:00:00 dkazankov Exp $

Add NetBSD support

--- src/common/platform.ads.orig	2023-01-05 11:22:11.000000000 +0200
+++ src/common/platform.ads
@@ -30,7 +30,7 @@
 
    type Host_Operating_System_Flavor is
       (X86_Windows, X86_64_Windows, X86_Linux, X86_64_Linux, X86_64_Darwin,
-       X86_64_FreeBSD, CodePeer_OS, AArch64_Darwin);
+       X86_64_FreeBSD, CodePeer_OS, AArch64_Darwin, X86_64_NetBSD);
 
    function Get_OS_Flavor return Host_Operating_System_Flavor;
 
