$NetBSD$

From NetBSD xsrc:

Oct 22 15:00:40 2011 UTC

if the video driver is "vmware" or "vmwlegacy" and no mouse section exists,
use the "vmmouse" input driver instead of "mouse" -- now xorg works properly
in vmware without a config file

--- hw/xfree86/parser/xf86Parser.h.orig	2019-05-30 18:27:34.000000000 +0000
+++ hw/xfree86/parser/xf86Parser.h
@@ -455,6 +455,10 @@ extern void xf86freeConfig(XF86ConfigPtr
 extern int xf86writeConfigFile(const char *, XF86ConfigPtr);
 extern _X_EXPORT XF86ConfDevicePtr xf86findDevice(const char *ident,
                                                   XF86ConfDevicePtr p);
+#if defined(__NetBSD__)
+extern _X_EXPORT XF86ConfDevicePtr xf86findDeviceByDriver(const char *driver,
+                                                          XF86ConfDevicePtr p);
+#endif
 extern _X_EXPORT XF86ConfLayoutPtr xf86findLayout(const char *name,
                                                   XF86ConfLayoutPtr list);
 extern _X_EXPORT XF86ConfMonitorPtr xf86findMonitor(const char *ident,
