$NetBSD: patch-gcc_ada_libgnat_g-socthi.ads,v 1.1 2022/03/13 08:34:04 nia Exp $

Fix symbol to make it use the C processed one.

--- gcc/ada/libgnat/g-socthi.ads.orig	2023-07-07 10:08:19.039159092 +0300
+++ gcc/ada/libgnat/g-socthi.ads
@@ -53,8 +53,6 @@
 
    package C renames Interfaces.C;
 
-   use type System.CRTL.ssize_t;
-
    function Socket_Errno return Integer renames GNAT.OS_Lib.Errno;
    --  Returns last socket error number
 
