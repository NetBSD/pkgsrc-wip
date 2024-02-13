$NetBSD: patch-src_alire_os__netbsd_alire-platforms-current__netbsd.adb,v 1.0 2023/12/27 22:00:00 dkazankov Exp $

Add NetBSD support

--- /dev/null	2023-12-27 21:54:28.155585723 +0200
+++ src/alire/os_netbsd/alire-platforms-current__netbsd.adb	2023-12-27 21:51:57.420839908 +0200
@@ -0,0 +1,34 @@
+
+package body Alire.Platforms.Current is
+
+   --  NetBSD implementation (identical to FreeBSD)
+
+   ---------------------------
+   -- Detected_Distribution --
+   ---------------------------
+
+   function Detected_Distribution return Platforms.Distributions is
+      (Platforms.Distro_Unknown);
+
+   -----------------------
+   -- Distribution_Root --
+   -----------------------
+
+   function Distribution_Root return Absolute_Path
+   is ("/");
+
+   ----------------------
+   -- Load_Environment --
+   ----------------------
+
+   procedure Load_Environment (Ctx : in out Alire.Environment.Context)
+   is null;
+
+   ----------------------
+   -- Operating_System --
+   ----------------------
+
+   function Operating_System return Alire.Platforms.Operating_Systems
+   is (Alire.Platforms.NetBSD);
+
+end Alire.Platforms.Current;
