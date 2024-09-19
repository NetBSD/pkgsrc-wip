$NetBSD: patch-hw_xfree86_os-support_bsd_bsd__init.c,v 1.1 2018/10/26 10:20:12 maya Exp $

Don't error when running unprivileged.

From FreeBSD ports for x11-servers/xorg-server 1.18.4.
sparc64 patch

Bug 196678
x11-servers/xorg-server: Update to 1.19.6 + make config/devd recognize
/dev/input/eventX from multimedia/webcamd

https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=196678

Attachment #191592: update Xorg to 1.19.6 and integrate collective devd enhancements
for bug #196678

https://bugs.freebsd.org/bugzilla/attachment.cgi?id=191592&action=diff

--- hw/xfree86/os-support/bsd/bsd_init.c.orig	2019-05-30 18:27:34.000000000 +0000
+++ hw/xfree86/os-support/bsd/bsd_init.c
@@ -48,6 +48,10 @@ static int devConsoleFd = -1;
 #if defined (SYSCONS_SUPPORT) || defined (PCVT_SUPPORT)
 static int VTnum = -1;
 static int initialVT = -1;
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+static struct termios tty_attr;	/* tty state to restore */
+static int tty_mode;		/* kbd mode to restore */
+#endif /* __FreeBSD__ */
 #endif
 
 #ifdef PCCONS_SUPPORT
@@ -165,10 +169,12 @@ xf86OpenConsole()
 #endif
 
     if (serverGeneration == 1) {
+#if !defined(ALLOW_UNPRIVILEGED)
         /* check if we are run with euid==0 */
         if (geteuid() != 0) {
             FatalError("xf86OpenConsole: Server must be suid root");
         }
+#endif
 
         if (!KeepTty) {
             /*
@@ -230,6 +236,9 @@ xf86OpenConsole()
              * Add cases for other *BSD that behave the same.
              */
 #if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#if defined(__sparc64__)
+	    pci_system_init_dev_mem(fd);
+#endif
             uname(&uts);
             i = atof(uts.release) * 100;
             if (i >= 310)
@@ -253,6 +262,9 @@ xf86OpenConsole()
 #endif
  acquire_vt:
             if (!xf86Info.ShareVTs) {
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+                struct termios nTty;
+#endif /* __FreeBSD__ */
                 /*
                  * now get the VT
                  */
@@ -287,6 +299,27 @@ xf86OpenConsole()
                 if (ioctl(xf86Info.consoleFd, KDSETMODE, KD_GRAPHICS) < 0) {
                     FatalError("xf86OpenConsole: KDSETMODE KD_GRAPHICS failed");
                 }
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+                tcgetattr(xf86Info.consoleFd, &tty_attr);
+                ioctl(xf86Info.consoleFd, KDGKBMODE, &tty_mode);
+
+                /* disable special keys */
+                if (ioctl(xf86Info.consoleFd, KDSKBMODE, K_RAW) < 0) {
+                    FatalError("xf86OpenConsole: KDSKBMODE K_RAW failed (%s)",
+                               strerror(errno));
+                }
+
+                nTty = tty_attr;
+                nTty.c_iflag = IGNPAR | IGNBRK;
+                nTty.c_oflag = 0;
+                nTty.c_cflag = CREAD | CS8;
+                nTty.c_lflag = 0;
+                nTty.c_cc[VTIME] = 0;
+                nTty.c_cc[VMIN] = 1;
+                cfsetispeed(&nTty, 9600);
+                cfsetospeed(&nTty, 9600);
+                tcsetattr(xf86Info.consoleFd, TCSANOW, &nTty);
+#endif /* __FreeBSD__ */
             }
             else {              /* xf86Info.ShareVTs */
                 close(xf86Info.consoleFd);
@@ -529,6 +562,9 @@ xf86OpenPcvt()
             xf86Msg(X_PROBED, "Using pcvt driver (version %d.%d)\n",
                     pcvt_version.rmajor, pcvt_version.rminor);
 #endif
+#if defined(STRICT_XSRC_NETBSD)
+            xf86Msg(X_PROBED, "using VT number %d\n", xf86Info.vtno);
+#endif
         }
         else {
             /* Not pcvt */
@@ -581,8 +617,10 @@ xf86CloseConsole()
     struct vt_mode VT;
 #endif
 
+#if defined (SYSCONS_SUPPORT) || defined (PCVT_SUPPORT) || !defined(SHAREVTS_XSRC_NETBSD)
     if (xf86Info.ShareVTs)
         return;
+#endif
 
     switch (xf86Info.consType) {
 #ifdef PCCONS_SUPPORT
@@ -594,6 +632,10 @@ xf86CloseConsole()
     case SYSCONS:
     case PCVT:
         ioctl(xf86Info.consoleFd, KDSETMODE, KD_TEXT);  /* Back to text mode */
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+        ioctl(xf86Info.consoleFd, KDSKBMODE, tty_mode);
+        tcsetattr(xf86Info.consoleFd, TCSANOW, &tty_attr);
+#endif /* __FreeBSD__ */
         if (ioctl(xf86Info.consoleFd, VT_GETMODE, &VT) != -1) {
             VT.mode = VT_AUTO;
             ioctl(xf86Info.consoleFd, VT_SETMODE, &VT); /* dflt vt handling */
