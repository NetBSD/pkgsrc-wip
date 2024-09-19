$NetBSD$

Bug 196678
x11-servers/xorg-server: Update to 1.19.6 + make config/devd recognize
/dev/input/eventX from multimedia/webcamd

https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=196678

Attachment #191592: update Xorg to 1.19.6 and integrate collective devd enhancements
for bug #196678

https://bugs.freebsd.org/bugzilla/attachment.cgi?id=191592&action=diff

* Skip the detection of root rights requirement, the assumption that presence
* of KMS drivers removes the root requirement is only valid for Linux
*

--- hw/xfree86/xorg-wrapper.c.orig	2018-08-07 16:31:04.000000000 +0000
+++ hw/xfree86/xorg-wrapper.c
@@ -191,7 +191,7 @@ static int on_console(int fd)
 
 int main(int argc, char *argv[])
 {
-#ifdef WITH_LIBDRM
+#if defined(WITH_LIBDRM) && !defined(__FreeBSD__) && !defined(__DragonFly__)
     struct drm_mode_card_res res;
 #endif
     char buf[PATH_MAX];
@@ -230,7 +230,7 @@ int main(int argc, char *argv[])
         }
     }
 
-#ifdef WITH_LIBDRM
+#if defined(WITH_LIBDRM) && !defined(__FreeBSD__) && !defined(__DragonFly__)
     /* Detect if we need root rights, except when overriden by the config */
     if (needs_root_rights == -1) {
         for (i = 0; i < 16; i++) {
