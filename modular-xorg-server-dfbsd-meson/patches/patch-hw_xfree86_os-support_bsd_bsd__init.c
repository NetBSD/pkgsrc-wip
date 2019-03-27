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

--- hw/xfree86/os-support/bsd/bsd_init.c.orig	2019-03-20 23:09:22.000000000 +0000
+++ hw/xfree86/os-support/bsd/bsd_init.c
@@ -37,6 +37,9 @@
 
 #include <sys/utsname.h>
 #include <sys/ioctl.h>
+#if defined(USL_VT_SWITCHING)
+#include <sys/sysctl.h>
+#endif
 #include <stdlib.h>
 #include <errno.h>
 
@@ -45,9 +48,14 @@ static Bool KeepTty = FALSE;
 #ifdef PCCONS_SUPPORT
 static int devConsoleFd = -1;
 #endif
-#if defined (SYSCONS_SUPPORT) || defined (PCVT_SUPPORT)
+#if defined (SYSCONS_SUPPORT) || defined (PCVT_SUPPORT) \
+    || (defined(WSCONS_SUPPORT) && defined(USL_VT_SWITCHING))
 static int VTnum = -1;
 static int initialVT = -1;
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+static struct termios tty_attr;	/* tty state to restore */
+static int tty_mode;		/* kbd mode to restore */
+#endif /* __FreeBSD__ */
 #endif
 
 #ifdef PCCONS_SUPPORT
@@ -67,13 +75,21 @@ static int initialVT = -1;
 #ifdef PCVT_SUPPORT
 /* Hellmuth Michaelis' pcvt driver */
 #ifndef __OpenBSD__
+#if defined(__NetBSD__)
+#define PCVT_CONSOLE_DEV "/dev/ttyE0"
+#else
 #define PCVT_CONSOLE_DEV "/dev/ttyv0"
+#endif
 #else
 #define PCVT_CONSOLE_DEV "/dev/ttyC0"
 #endif
 #define PCVT_CONSOLE_MODE O_RDWR|O_NDELAY
 #endif
 
+#if defined(WSCONS_SUPPORT) && defined(USL_VT_SWITCHING)
+static Bool hasVT = FALSE;      /* has VT support ? */
+#endif
+
 #if defined(WSCONS_SUPPORT) && defined(__NetBSD__)
 /* NetBSD's new console driver */
 #define WSCONS_PCVT_COMPAT_CONSOLE_DEV "/dev/ttyE0"
@@ -134,6 +150,11 @@ static int xf86OpenWScons(void);
  * pcvt or syscons might succesfully probe as pccons.)
  */
 static xf86ConsOpen_t xf86ConsTab[] = {
+#if defined(TRY_DEV_WSKBD) || defined(USL_VT_SWITCHING)
+#ifdef WSCONS_SUPPORT
+    xf86OpenWScons,
+#endif
+#endif /* TRY_DEV_WSKBD || USL_VT_SWITCHING */
 #ifdef PCVT_SUPPORT
     xf86OpenPcvt,
 #endif
@@ -143,9 +164,11 @@ static xf86ConsOpen_t xf86ConsTab[] = {
 #ifdef PCCONS_SUPPORT
     xf86OpenPccons,
 #endif
+#if !defined(TRY_DEV_WSKBD) && !defined(USL_VT_SWITCHING)
 #ifdef WSCONS_SUPPORT
     xf86OpenWScons,
 #endif
+#endif /* !TRY_DEV_WSKBD && !USL_VT_SWITCHING */
     (xf86ConsOpen_t) NULL
 };
 
@@ -155,7 +178,8 @@ xf86OpenConsole()
     int i, fd = -1;
     xf86ConsOpen_t *driver;
 
-#if defined (SYSCONS_SUPPORT) || defined (PCVT_SUPPORT)
+#if defined (SYSCONS_SUPPORT) || defined (PCVT_SUPPORT) \
+    || (defined(WSCONS_SUPPORT) && defined(USL_VT_SWITCHING))
     int result;
 
 #if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
@@ -164,11 +188,23 @@ xf86OpenConsole()
     vtmode_t vtmode;
 #endif
 
+#if defined(WSCONS_SUPPORT) && defined(USL_VT_SWITCHING)
+    int mode;
+#endif
+
+#if defined(USL_VT_SWITCHING)
+    if (xf86Info.consoleFd != -1) {
+        return;
+    }
+#endif
+
     if (serverGeneration == 1) {
+#if !defined(ALLOW_UNPRIVILEGED)
         /* check if we are run with euid==0 */
         if (geteuid() != 0) {
             FatalError("xf86OpenConsole: Server must be suid root");
         }
+#endif
 
         if (!KeepTty) {
             /*
@@ -230,6 +266,9 @@ xf86OpenConsole()
              * Add cases for other *BSD that behave the same.
              */
 #if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#if defined(__sparc64__)
+	    pci_system_init_dev_mem(fd);
+#endif
             uname(&uts);
             i = atof(uts.release) * 100;
             if (i >= 310)
@@ -253,6 +292,9 @@ xf86OpenConsole()
 #endif
  acquire_vt:
             if (!xf86Info.ShareVTs) {
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+                struct termios nTty;
+#endif /* __FreeBSD__ */
                 /*
                  * now get the VT
                  */
@@ -287,6 +329,27 @@ xf86OpenConsole()
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
@@ -295,7 +358,40 @@ xf86OpenConsole()
 #endif                          /* SYSCONS_SUPPORT || PCVT_SUPPORT */
 #ifdef WSCONS_SUPPORT
         case WSCONS:
+
+#if defined(USL_VT_SWITCHING)
+            if (hasVT) {
+                /* now get the VT */
+                SYSCALL(result =
+                        ioctl(xf86Info.consoleFd, VT_ACTIVATE, xf86Info.vtno));
+                if (result != 0) {
+                    xf86Msg(X_WARNING, "xf86OpenConsole: VT_ACTIVATE %d failed\n", xf86Info.vtno);
+                }
+                SYSCALL(result =
+                        ioctl(xf86Info.consoleFd, VT_WAITACTIVE, xf86Info.vtno));
+                if (result != 0) {
+                    xf86Msg(X_WARNING, "xf86OpenConsole: VT_WAITACTIVE failed\n");
+                }
+
+                OsSignal(SIGUSR1, xf86VTRequest);
+
+                vtmode.mode = VT_PROCESS;
+                vtmode.relsig = SIGUSR1;
+                vtmode.acqsig = SIGUSR1;
+                vtmode.frsig = SIGUSR1;
+                if (ioctl(xf86Info.consoleFd, VT_SETMODE, &vtmode) < 0) {
+                    FatalError("xf86OpenConsole: VT_SETMODE VT_PROCESS failed");
+                }
+            }
+            mode = WSDISPLAYIO_MODE_MAPPED;
+            if (ioctl(fd, WSDISPLAYIO_SMODE, &mode) < 0) {
+                FatalError("%s: WSDISPLAYIO_MODE_MAPPED failed (%s)\n%s",
+                           "xf86OpenConsole", strerror(errno),
+                           CHECK_DRIVER_MSG);
+            }
+#else /* !USL_VT_SWITCHING */
             /* Nothing to do */
+#endif /* USL_VT_SWITCHING */
             break;
 #endif
         }
@@ -414,8 +510,18 @@ xf86OpenSyscons()
             }
 
             close(fd);
+#ifndef __OpenBSD__
+#if defined(__NetBSD__)
+            snprintf(vtname, sizeof(vtname), "/dev/ttyE%01x",
+                     xf86Info.vtno - 1);
+#else
             snprintf(vtname, sizeof(vtname), "/dev/ttyv%01x",
                      xf86Info.vtno - 1);
+#endif
+#else
+            snprintf(vtname, sizeof(vtname), "/dev/ttyC%01x",
+                     xf86Info.vtno - 1);
+#endif
             if ((fd = open(vtname, SYSCONS_CONSOLE_MODE, 0)) < 0) {
                 FatalError("xf86OpenSyscons: Cannot open %s (%s)",
                            vtname, strerror(errno));
@@ -457,12 +563,26 @@ xf86OpenPcvt()
     struct pcvtid pcvt_version;
 
 #ifndef __OpenBSD__
+#if defined(__NetBSD__)
+    vtprefix = "/dev/ttyE";
+#else
     vtprefix = "/dev/ttyv";
+#endif
 #else
     vtprefix = "/dev/ttyC";
 #endif
 
+#if defined(USL_VT_SWITCHING)
+    if (VTnum != -1) {
+            snprintf(vtname, sizeof(vtname), "%s%x", vtprefix, VTnum - 1);
+            fd  = open(vtname, PCVT_CONSOLE_MODE, 0);
+    }
+    else {
+            fd = open(PCVT_CONSOLE_DEV, PCVT_CONSOLE_MODE, 0);
+    }
+#else /* !USL_VT_SWITCHING */
     fd = open(PCVT_CONSOLE_DEV, PCVT_CONSOLE_MODE, 0);
+#endif /* USL_VT_SWITCHING */
 #ifdef WSCONS_PCVT_COMPAT_CONSOLE_DEV
     if (fd < 0) {
         fd = open(WSCONS_PCVT_COMPAT_CONSOLE_DEV, PCVT_CONSOLE_MODE, 0);
@@ -529,6 +649,9 @@ xf86OpenPcvt()
             xf86Msg(X_PROBED, "Using pcvt driver (version %d.%d)\n",
                     pcvt_version.rmajor, pcvt_version.rminor);
 #endif
+#if defined(STRICT_XSRC_NETBSD)
+            xf86Msg(X_PROBED, "using VT number %d\n", xf86Info.vtno);
+#endif
         }
         else {
             /* Not pcvt */
@@ -546,11 +669,101 @@ xf86OpenPcvt()
 static int
 xf86OpenWScons()
 {
+#if defined(USL_VT_SWITCHING)
+    char vtname[16], vtprefix[16];
+    char *p;
+    int mib[2];
+    int fd = -1;
+    int i;
+    size_t len;
+    dev_t dev;
+    vtmode_t vtmode;
+#else /* !USL_VT_SWITCHING */
     int fd = -1;
     int mode = WSDISPLAYIO_MODE_MAPPED;
     int i;
     char ttyname[16];
+#endif /* USL_VT_SWITCHING */
 
+#if defined(USL_VT_SWITCHING)
+    if (xf86Info.ShareVTs)
+        FatalError("-sharevt is not supported with wscons\n");
+
+    /* default value if probing the console device fails */
+#if defined(__NetBSD__)
+    snprintf(vtprefix, sizeof(vtprefix), "/dev/ttyE");
+#elif defined(__OpenBSD__)
+    snprintf(vtprefix, sizeof(vtprefix), "/dev/ttyC");
+#else
+    snprintf(vtprefix, sizeof(vtprefix), "/dev/ttyv");
+#endif
+
+    /* probe console device - it my be /dev/ttyD0 on some multi-heads setups */
+    mib[0] = CTL_KERN;
+    mib[1] = KERN_CONSDEV;
+    len = sizeof(dev);
+    if (sysctl(mib, 2, &dev, &len, NULL, 0) != -1) {
+        snprintf(vtname, sizeof(vtname), "/dev/%s", devname(dev, S_IFCHR));
+	if ((fd = open(vtname, O_RDWR)) != -1) {
+    if (ioctl(fd, WSDISPLAYIO_GTYPE, &i) == 0) {
+               /* console is a wsdisplay(4) device */
+                strlcpy(vtprefix, vtname, sizeof(vtprefix));
+                /* strip number, assuming 0 */
+                p = strchr(vtprefix, '0');
+                *p = '\0';
+                close(fd);
+                fd = -1;
+            }
+        }
+    }
+    if (VTnum != -1) {
+        snprintf(vtname, sizeof(vtname), "%s%01x", vtprefix, VTnum - 1);
+        xf86Info.vtno = VTnum;
+    } else {
+        snprintf(vtname, sizeof(vtname), "%s0", vtprefix);
+    }
+    fd = open(vtname, O_RDWR);
+    if (fd == -1)
+        return fd;
+
+    /* Check if USL VTs are supported */
+    if (ioctl(fd, VT_GETACTIVE, &initialVT) < 0) {
+        if (errno == ENOTTY) {
+            /* double-check that this is a wsdisplay screeen */
+            if (ioctl(fd, WSDISPLAYIO_GTYPE, &i) == -1) {
+                close(fd);
+                return -1;
+            }
+            /* NO VTs */
+            initialVT = 1;
+            hasVT = FALSE;
+        } else {
+            close(fd);
+            return -1;
+        }
+    } else {
+        hasVT = TRUE;
+        /* find a free VT */
+        if (xf86Info.vtno == -1) {
+            if (ioctl(fd, VT_OPENQRY, &xf86Info.vtno) < 0) {
+                /* All VTs are in use.  If initialVT was found, use it. */
+                if (initialVT != -1)
+                    xf86Info.vtno = initialVT;
+                else
+                    FatalError("xf86OpenWScons: Cannot find a free VT");
+            }
+            /* re-open the new VT */
+            close(fd);
+            snprintf(vtname, sizeof(vtname), "%s%01x", vtprefix,
+                     xf86Info.vtno - 1);
+            if ((fd = open(vtname, O_RDWR)) < 0)
+                FatalError("xf86OpenWScons: cannot open %s (%s)",
+                           vtname, strerror(errno));
+        }
+    }
+    xf86Info.consType = WSCONS;
+    xf86Msg(X_PROBED, "Using wscons driver on %s\n", vtname);
+#else /* !USL_VT_SWITCHING */
     /* XXX Is this ok? */
     for (i = 0; i < 8; i++) {
 #if defined(__NetBSD__)
@@ -569,6 +782,7 @@ xf86OpenWScons()
         xf86Info.consType = WSCONS;
         xf86Msg(X_PROBED, "Using wscons driver\n");
     }
+#endif /* USL_VT_SWITCHING */
     return fd;
 }
 
@@ -581,8 +795,10 @@ xf86CloseConsole()
     struct vt_mode VT;
 #endif
 
+#if defined (SYSCONS_SUPPORT) || defined (PCVT_SUPPORT) || !defined(STRICT_XSRC_NETBSD)
     if (xf86Info.ShareVTs)
         return;
+#endif
 
     switch (xf86Info.consType) {
 #ifdef PCCONS_SUPPORT
@@ -594,6 +810,10 @@ xf86CloseConsole()
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
@@ -614,6 +834,10 @@ xf86CloseConsole()
         int mode = WSDISPLAYIO_MODE_EMUL;
 
         ioctl(xf86Info.consoleFd, WSDISPLAYIO_SMODE, &mode);
+#if defined(USL_VT_SWITCHING)
+        if (initialVT != -1 && hasVT)
+            ioctl(xf86Info.consoleFd, VT_ACTIVATE, initialVT);
+#endif
         break;
     }
 #endif
@@ -638,7 +862,8 @@ xf86ProcessArgument(int argc, char *argv
         KeepTty = TRUE;
         return 1;
     }
-#if defined (SYSCONS_SUPPORT) || defined (PCVT_SUPPORT)
+#if defined (SYSCONS_SUPPORT) || defined (PCVT_SUPPORT) \
+        || (defined(WSCONS_SUPPORT) && defined(USL_VT_SWITCHING))
     if ((argv[i][0] == 'v') && (argv[i][1] == 't')) {
         if (sscanf(argv[i], "vt%2d", &VTnum) == 0 || VTnum < 1 || VTnum > 12) {
             UseMsg();
@@ -654,7 +879,8 @@ xf86ProcessArgument(int argc, char *argv
 void
 xf86UseMsg()
 {
-#if defined (SYSCONS_SUPPORT) || defined (PCVT_SUPPORT)
+#if defined (SYSCONS_SUPPORT) || defined (PCVT_SUPPORT) \
+        || (defined(WSCONS_SUPPORT) && defined(USL_VT_SWITCHING))
     ErrorF("vtXX                   use the specified VT number (1-12)\n");
 #endif                          /* SYSCONS_SUPPORT || PCVT_SUPPORT */
     ErrorF("-keeptty               ");
