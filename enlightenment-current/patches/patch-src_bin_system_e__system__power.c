$NetBSD$

Merged upstream: https://git.enlightenment.org/enlightenment/enlightenment/pulls/139

--- src/bin/system/e_system_power.c.orig	2025-03-17 17:18:54.000000000 +0000
+++ src/bin/system/e_system_power.c
@@ -46,7 +46,7 @@ _cb_power_suspend_then_hibernate(void *d
 static void
 _power_halt_init(void)
 {
-#if defined (__FreeBSD__) || defined (__OpenBSD__)
+#if defined (__FreeBSD__) || defined (__OpenBSD__) || defined (__NetBSD__)
    _cmd_halt = strdup("shutdown -p now");
 #else
    if (ecore_file_app_installed("systemctl"))
@@ -62,7 +62,7 @@ _power_halt_init(void)
 static void
 _power_reboot_init(void)
 {
-#if defined (__FreeBSD__) || defined (__OpenBSD__)
+#if defined (__FreeBSD__) || defined (__OpenBSD__) || defined (__NetBSD__)
    _cmd_reboot = strdup("shutdown -r now");
 #else
    if (ecore_file_app_installed("systemctl"))
@@ -80,6 +80,8 @@ _power_suspend_init(void)
 #if defined (__FreeBSD__) || defined (__OpenBSD__)
    if (ecore_file_app_installed("zzz"))
      _cmd_suspend = strdup("zzz");
+#elif defined (__NetBSD__)
+     _cmd_suspend = strdup("sysctl -w hw.acpi.sleep.state=3");
 #else
    if (ecore_file_app_installed("systemctl"))
      _cmd_suspend = strdup("systemctl suspend");
@@ -94,6 +96,7 @@ _power_suspend_init(void)
 #endif
    // linux systemd: PATH/systemctl suspend
    //           bsd: /usr/sbin/zzz
+   //        NetBSD: /sbin/sysctl
    //             *:
    //    PATH/sleep.sh
    //    /etc/acpi/sleep.sh force
@@ -110,6 +113,8 @@ _power_hibernate_init(void)
 #elif defined (__OpenBSD__)
    if (ecore_file_app_installed("ZZZ"))
      _cmd_suspend = strdup("ZZZ");
+#elif defined (__NetBSD__)
+     _cmd_hibernate = strdup("sysctl -w hw.acpi.sleep.state=4");
 #else
    if (ecore_file_app_installed("systemctl"))
      _cmd_hibernate = strdup("systemctl hibernate");
@@ -125,6 +130,7 @@ _power_hibernate_init(void)
    // linux systemd: PATH/systemctl hibernate
    // FreeBSD: acpiconf -s4
    // OpenBSD: ZZZ
+   // Netbsd: sysctl
    // if exist:
    //    PATH/hibernate.sh
    //    /etc/acpi/hibernate.sh force
