$NetBSD$

--- src/VBox/Additions/common/crOpenGL/fakedri_drv.c.orig	2016-03-04 19:23:12.000000000 +0000
+++ src/VBox/Additions/common/crOpenGL/fakedri_drv.c
@@ -30,7 +30,7 @@
 #include <elf.h>
 #include <unistd.h>
 
-#if defined(RT_OS_FREEBSD)
+#if defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
 #include <sys/param.h>
 #include <fcntl.h>
 #include <gelf.h>
@@ -62,6 +62,9 @@ typedef enum {
 # ifdef RT_OS_FREEBSD
 #  define DRI_DEFAULT_DRIVER_DIR "/usr/local/lib/dri"
 #  define DRI_XORG_DRV_DIR "/usr/local/lib/xorg/modules/drivers/"
+# elif defined(RT_OS_NETBSD)
+#  define DRI_DEFAULT_DRIVER_DIR "/usr/X11R7/lib/modules/dri"
+#  define DRI_XORG_DRV_DIR "/usr/X11R7/lib/modules/drivers/"
 # else
 #  define DRI_DEFAULT_DRIVER_DIR "/usr/lib64/dri:/usr/lib/dri:/usr/lib/x86_64-linux-gnu/dri:/usr/lib/xorg/modules/dri"
 #  define DRI_XORG_DRV_DIR "/usr/lib/xorg/modules/drivers/"
@@ -70,6 +73,9 @@ typedef enum {
 # ifdef RT_OS_FREEBSD
 #  define DRI_DEFAULT_DRIVER_DIR "/usr/local/lib/dri"
 #  define DRI_XORG_DRV_DIR "/usr/local/lib/xorg/modules/drivers/"
+# elif defined(RT_OS_NETBSD)
+#  define DRI_DEFAULT_DRIVER_DIR "/usr/X11R7/lib/modules/dri"
+#  define DRI_XORG_DRV_DIR "/usr/X11R7/lib/modules/drivers/"
 # else
 #  define DRI_DEFAULT_DRIVER_DIR "/usr/lib/dri:/usr/lib/i386-linux-gnu/dri:/usr/lib/xorg/modules/dri"
 #  define DRI_XORG_DRV_DIR "/usr/lib/xorg/modules/drivers/"
@@ -228,7 +234,7 @@ vboxApplyPatch(const char* psFuncName, v
 
 #define FAKEDRI_JMP64_PATCH_SIZE 13
 
-#if defined(RT_OS_FREEBSD)
+#if defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
 /* Provide basic dladdr1 flags */
 enum {
 	RTLD_DL_SYMENT	= 1
