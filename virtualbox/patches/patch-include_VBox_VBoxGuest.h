$NetBSD$

--- include/VBox/VBoxGuest.h.orig	2016-03-04 19:22:56.000000000 +0000
+++ include/VBox/VBoxGuest.h
@@ -204,6 +204,13 @@ typedef const VBGLBIGREQ *PCVBGLBIGREQ;
 # define VBOXGUEST_IOCTL_CODE_FAST_(Function)       _IO(  'V', (Function))
 # define VBOXGUEST_IOCTL_STRIP_SIZE(Code)           IOCBASECMD(Code)
 
+#elif defined(RT_OS_NETBSD) /** @todo r=bird: Please do it like SUPDRVIOC to keep it as similar as possible. */
+# include <sys/ioccom.h>
+
+# define VBOXGUEST_IOCTL_CODE_(Function, Size)      _IOWR('V', (Function), VBGLBIGREQ)
+# define VBOXGUEST_IOCTL_CODE_FAST_(Function)       _IO(  'V', (Function))
+# define VBOXGUEST_IOCTL_STRIP_SIZE(Code)           IOCBASECMD(Code)
+
 #else /* BSD Like */
   /* Automatic buffering, size limited to 4KB on *BSD and 8KB on Darwin - commands the limit, 4KB. */
 # include <sys/ioccom.h>
@@ -534,7 +541,7 @@ typedef VBOXGUESTOS2IDCCONNECT *PVBOXGUE
 
 #endif /* RT_OS_OS2 */
 
-#if defined(RT_OS_LINUX) || defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD)
+#if defined(RT_OS_LINUX) || defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
 
 /* Private IOCtls between user space and the kernel video driver.  DRM private
  * IOCtls always have the type 'd' and a number between 0x40 and 0x99 (0x9F?) */
@@ -554,7 +561,7 @@ typedef VBOXGUESTOS2IDCCONNECT *PVBOXGUE
 # define DRM_IOCTL_VBOX_ENABLE_HGSMI     VBOX_DRM_IOCTL(ENABLE_HGSMI)
 # define VBOXVIDEO_IOCTL_ENABLE_HGSMI    _IO('d', DRM_IOCTL_VBOX_ENABLE_HGSMI)
 
-#endif /* RT_OS_LINUX || RT_OS_SOLARIS || RT_OS_FREEBSD */
+#endif /* RT_OS_LINUX || RT_OS_SOLARIS || RT_OS_FREEBSD || RT_OS_FREEBSD */
 
 #endif /* !defined(IN_RC) && !defined(IN_RING0_AGNOSTIC) && !defined(IPRT_NO_CRT) */
 
@@ -562,4 +569,3 @@ typedef VBOXGUESTOS2IDCCONNECT *PVBOXGUE
 
 /** @} */
 #endif
-
