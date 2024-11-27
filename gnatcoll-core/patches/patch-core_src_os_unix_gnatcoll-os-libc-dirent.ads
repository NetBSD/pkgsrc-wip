$NetBSD: patch-core_src_os_unix_gnatcoll-os-libc-dirent.ads,v 1.0 2024/11/27 10:00:00 dkazankov Exp $

Fix linker version warning on NetBSD

--- core/src/os/unix/gnatcoll-os-libc-dirent.ads.orig	2024-09-24 12:28:32.000000000 +0300
+++ core/src/os/unix/gnatcoll-os-libc-dirent.ads
@@ -41,7 +41,7 @@
    function Opendir (Path : C_String) return Dir_Handle
    with Import        => True,
         Convention    => C,
-        External_Name => "opendir";
+        External_Name => "__gnatcoll_opendir";
 
    function Closedir (Dir : Dir_Handle) return Libc_Status
    with Import        => True,
