$NetBSD: patch-Garlic_s-gafizi.adb,v 1.0 2024/12/05 15:00:00 dkazankov Exp $

Fix som compilation warnings

--- Garlic/s-gafizi.adb.orig	2007-11-26 15:10:13.000000000 +0200
+++ Garlic/s-gafizi.adb
@@ -33,8 +33,6 @@
 
 with Ada.Streams;           use Ada.Streams;
 with Interfaces.C;
-with System.Garlic.Filters;
-pragma Warnings (Off, System.Garlic.Filters);
 with System.Garlic.Debug; use System.Garlic.Debug;
 with System.Garlic.Streams; use System.Garlic.Streams;
 
