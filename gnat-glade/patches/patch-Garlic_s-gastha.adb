$NetBSD: patch-Garlic_s-gastha.adb,v 1.0 2024/12/05 15:00:00 dkazankov Exp $

Fix some compilation warnings
https://github.com/reznikmm/garlic/commit/b738f20db65add57f817f952a625df73bef0710e

--- Garlic/s-gastha.adb.orig	2007-11-26 15:10:13.000000000 +0200
+++ Garlic/s-gastha.adb
@@ -39,7 +39,6 @@
    package SSE renames System.Storage_Elements;
 
    use type SSE.Storage_Count;
-   use type IC.int;
 
    function malloc (Size : IC.int) return Address;
    pragma Import (C, malloc, "__gnat_malloc");
