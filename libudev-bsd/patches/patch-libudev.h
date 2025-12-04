$NetBSD$

Add missing prototypes.

--- libudev.h.orig	2025-08-06 15:53:14.000000000 +0000
+++ libudev.h
@@ -78,7 +78,11 @@ struct udev_list_entry * udev_device_get
     struct udev_device *udev_device);
 struct udev_list_entry * udev_device_get_tags_list_entry(
     struct udev_device *udev_device);
+struct udev_list_entry *udev_device_get_current_tags_list_entry(
+    struct udev_device *udev_device);
 int udev_device_has_tag(struct udev_device *udev_device, const char *tag);
+int udev_device_has_current_tag(
+    struct udev_device *udev_device, const char *tag);
 struct udev_list_entry * udev_device_get_devlinks_list_entry(
     struct udev_device *udev_device);
 struct udev *udev_device_get_udev(struct udev_device *udev_device);
