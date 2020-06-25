$NetBSD$

* Add NetBSD support

--- src/bin/system/e_system_power.c.orig	2020-05-31 18:22:37.498920400 +0000
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
@@ -93,6 +96,8 @@ _power_hibernate_init(void)
 #if defined (__FreeBSD__) || defined (__OpenBSD__)
    if (ecore_file_app_installed("acpiconf"))
      _cmd_hibernate = strdup("acpiconf -s4");
+#elif defined (__NetBSD__)
+     _cmd_hibernate = strdup("sysctl -w hw.acpi.sleep.state=4");
 #else
    if (ecore_file_app_installed("systemctl"))
      _cmd_hibernate = strdup("systemctl hibernate");
@@ -107,6 +112,7 @@ _power_hibernate_init(void)
 #endif
    // linux systemd: PATH/systemctl hibernate
    // bsd: acpiconf -s4
+   //        NetBSD: sysctl
    // if exist:
    //    PATH/hibernate.sh
    //    /etc/acpi/hibernate.sh force
