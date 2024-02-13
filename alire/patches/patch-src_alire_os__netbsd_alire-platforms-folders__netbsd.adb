$NetBSD: patch-src_alire_os__netbsd_alire-platforms-folders__netbsd.adb,v 1.0 2023/12/27 22:00:00 dkazankov Exp $

Add NetBSD support

--- /dev/null	2023-12-27 21:54:28.155585723 +0200
+++ src/alire/os_netbsd/alire-platforms-folders__netbsd.adb	2023-10-19 18:04:21.000000000 +0300
@@ -0,0 +1,34 @@
+with Ada.Directories;
+
+with Alire.Platforms.Common;
+
+package body Alire.Platforms.Folders is
+
+   --  Linux implementation
+
+   -----------
+   -- Cache --
+   -----------
+
+   function Cache return Absolute_Path is (Common.XDG_Cache_Folder);
+
+   -----------
+   -- Config--
+   -----------
+
+   function Config return Absolute_Path is (Common.XDG_Config_Folder);
+
+   ----------
+   -- Home --
+   ----------
+
+   function Home return Absolute_Path is (Common.Unix_Home_Folder);
+
+   ----------
+   -- Temp --
+   ----------
+
+   function Temp return Absolute_Path
+   is (Ada.Directories.Full_Name (Common.Unix_Temp_Folder));
+
+end Alire.Platforms.Folders;
