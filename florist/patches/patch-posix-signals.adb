$NetBSD: patch-posix-signals.adb,v 1.1.1.1 2003/12/11 22:02:06 johnrshannon Exp $

--- posix-signals.adb.orig	2003-12-01 10:20:48.000000000 -0700
+++ posix-signals.adb
@@ -941,7 +941,7 @@ package body POSIX.Signals is
 
    function Get_Data (Info : Signal_Info) return Signal_Data is
    begin
-      return To_Signal_Data (Info.si_value);
+      return To_Signal_Data (Info.si_sigval);
    end Get_Data;
 
    ----------------
@@ -952,7 +952,7 @@ package body POSIX.Signals is
      (Info : in out Signal_Info;
       Data : in Signal_Data) is
    begin
-      Info.si_value := To_sigval (Data);
+      Info.si_sigval := To_sigval (Data);
    end Set_Data;
 
    -----------------------
