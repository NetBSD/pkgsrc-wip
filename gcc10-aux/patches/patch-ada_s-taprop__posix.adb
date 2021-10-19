--- gcc/ada/libgnarl/s-taprop__posix.adb.orig	2021-09-23 19:55:24.471842046 +0000
+++ gcc/ada/libgnarl/s-taprop__posix.adb	2021-09-23 20:01:31.689253592 +0000
@@ -654,6 +654,16 @@
       else
          Result := pthread_setschedparam
            (T.Common.LL.Thread, SCHED_OTHER, Param'Access);
+         if Result /= 0 then
+            Param.sched_priority := 0;
+            Result := pthread_setschedparam
+              (T.Common.LL.Thread, SCHED_OTHER, Param'Access);
+            if Result /= 0 then
+               Param.sched_priority := -1;
+               Result := pthread_setschedparam
+                 (T.Common.LL.Thread, SCHED_OTHER, Param'Access);
+            end if;
+         end if;
       end if;
 
       pragma Assert (Result = 0);
