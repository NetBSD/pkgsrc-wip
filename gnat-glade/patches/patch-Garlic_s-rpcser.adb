$NetBSD: patch-Garlic_s-rpcser.adb,v 1.0 2024/12/05 15:00:00 dkazankov Exp $

Fix some compilation warnings
https://github.com/reznikmm/garlic/commit/b738f20db65add57f817f952a625df73bef0710e

--- Garlic/s-rpcser.adb.orig	2007-11-26 15:10:13.000000000 +0200
+++ Garlic/s-rpcser.adb
@@ -61,7 +61,6 @@
 package body System.RPC.Server is
 
    use type System.Garlic.Types.Partition_ID;
-   use type System.Garlic.Streams.Params_Stream_Type;
 
    Private_Debug_Key : constant Debug_Key :=
      Debug_Initialize ("S_RPCSER", "(s-rpcser): ");
