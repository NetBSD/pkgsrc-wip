$NetBSD: patch-Garlic_isthrbio.adb,v 1.0 2024/12/05 15:00:00 dkazankov Exp $

Fix link time version warning

--- Garlic/isthrbio.adb.orig	2007-11-26 15:10:13.000000000 +0200
+++ Garlic/isthrbio.adb
@@ -65,7 +65,7 @@
       Exceptfds : Fd_Set_Access;
       Timeout   : Timeval_Access)
      return int;
-   pragma Import (C, C_Select, "select");
+   pragma Import (C, C_Select, "__netbsd_select");
 
    task A_Task is
       entry Start;
