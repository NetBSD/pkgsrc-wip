$NetBSD$

--- src/bin/system/e_system_power.c.orig	2023-12-23 16:08:09.000000000 +0000
+++ src/bin/system/e_system_power.c
@@ -32,7 +32,7 @@ _cb_power_hibernate(void *data EINA_UNUS
 static void
 _power_halt_init(void)
 {
-#if defined (__FreeBSD__) || defined (__OpenBSD__)
+#if defined (__FreeBSD__) || defined (__OpenBSD__) || defined (__NetBSD__)
    _cmd_halt = strdup("shutdown -p now");
 #else
    if (ecore_file_app_installed("systemctl"))
@@ -41,7 +41,7 @@ _power_halt_init(void)
      _cmd_halt = strdup("shutdown -h now");
 #endif
    // linux systemd: PATH/systemctl poweroff
-   //           bsd: /sbin/shutdown -p no
+   //           bsd: /sbin/shutdown -p now
    // *            : /sbin/shutdown -h now
 }
 
@@ -66,6 +66,8 @@ _power_suspend_init(void)
 #if defined (__FreeBSD__) || defined (__OpenBSD__)
    if (ecore_file_app_installed("zzz"))
      _cmd_suspend = strdup("zzz");
+#elif defined (__NetBSD__)
+     _cmd_suspend = strdup("sysctl -w hw.acpi.sleep.state=3");
 #else
    if (ecore_file_app_installed("systemctl"))
      _cmd_suspend = strdup("systemctl suspend");
@@ -80,6 +82,7 @@ _power_suspend_init(void)
 #endif
    // linux systemd: PATH/systemctl suspend
    //           bsd: /usr/sbin/zzz
+   //        NetBSD: sysctl
    //             *:
    //    PATH/sleep.sh
    //    /etc/acpi/sleep.sh force
@@ -96,6 +99,8 @@ _power_hibernate_init(void)
 #elif defined (__OpenBSD__)
    if (ecore_file_app_installed("ZZZ"))
      _cmd_suspend = strdup("ZZZ");
+#elif defined (__NetBSD__)
+     _cmd_hibernate = strdup("sysctl -w hw.acpi.sleep.state=4");
 #else
    if (ecore_file_app_installed("systemctl"))
      _cmd_hibernate = strdup("systemctl hibernate");
@@ -111,6 +116,7 @@ _power_hibernate_init(void)
    // linux systemd: PATH/systemctl hibernate
    // FreeBSD: acpiconf -s4
    // OpenBSD: ZZZ
+   // Netbsd: sysctl
    // if exist:
    //    PATH/hibernate.sh
    //    /etc/acpi/hibernate.sh force
