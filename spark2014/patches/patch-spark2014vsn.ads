$NetBSD: patch-spark2014vsn.ads,v 1.0 2024/05/19 22:00:00 dkazankov Exp $

Fix version number

--- spark2014vsn.ads.orig	2023-01-05 11:22:11.000000000 +0200
+++ spark2014vsn.ads	2024-05-19 23:19:54.364201126 +0300
@@ -22,7 +22,7 @@
 
 package SPARK2014VSN is
 
-   SPARK2014_Static_Version_String : constant String := "0.0w";
+   SPARK2014_Static_Version_String : constant String := "13.0";
    --  Static string identifying this version, that can be used as an argument
    --  to e.g. pragma Ident.
    --
