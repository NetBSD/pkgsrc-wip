$NetBSD$

devd support to detect devices from FreeBSD ports / DragonFly dports

--- config/config-backends.h.orig	2015-05-21 14:23:54.000000000 +0000
+++ config/config-backends.h
@@ -44,3 +44,8 @@ void config_hal_fini(void);
 int config_wscons_init(void);
 void config_wscons_fini(void);
 #endif
+
+#ifdef CONFIG_DEVD
+int config_devd_init(void);
+void config_devd_fini(void);
+#endif
