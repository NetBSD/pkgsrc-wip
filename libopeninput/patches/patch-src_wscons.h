$NetBSD$

* Handle auto-repeat per device instead of globally
* Handle attached-detached devices with udev monitor

--- src/wscons.h.orig	2026-01-30 14:33:45.725593515 +0000
+++ src/wscons.h
@@ -18,12 +18,19 @@ struct wscons_device {
 	struct libinput_device base;
 	enum libinput_device_capability capability;
 	struct TransMapRec *scanCodeMap;
+	int old_value;
 	struct {
 		struct libinput_device_config_accel config;
 		struct motion_filter *filter;
 	} pointer;
 };
 
+struct udev_input {
+	struct libinput base;
+	struct udev *udev;
+	struct udev_monitor *udev_monitor;
+	struct libinput_source *udev_monitor_source;
+};
 
 static inline struct wscons_device *
 wscons_device(struct libinput_device *device)
