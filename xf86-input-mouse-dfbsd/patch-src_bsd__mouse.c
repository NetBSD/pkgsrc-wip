$NetBSD$

Patches from FreeBSD ports / DragonFly dports with include guards.
Support for different versions of system libusb headers.

--- src/bsd_mouse.c.orig	2015-04-20 01:07:33.000000000 +0000
+++ src/bsd_mouse.c
@@ -26,6 +26,41 @@
  * authorization from the copyright holder(s) and author(s).
  */
 
+/* PKGSRC note: To support newer versions of DragonFly and FreeBSD,
+ * this file is patched using DragonFly dports
+ * x11-drivers/xf86-input-mouse/files/patch-src-bsd_mouse.c and
+ * x11-drivers/xf86-input-mouse/dragonfly/patch-src_bsd__mouse.c
+ * as of master commit 4f04bfe0ea83 ... Tue Jul 14 22:56:44 2015 -0700
+ * The patch's code is enclosed in include defined(FREEBSD_USB) while the
+ * original code is enclosed in include !defined(FREEBSD_USB).
+ */
+
+/* DRAGONFLY_U4B is the usb system after OS version 300703
+ * DRAGONFLY_USB is the usb system before OS version 300703
+ * FREEBSD_USB must be defined if either DRAGONFLY_U4B or DRAGONFLY_USB are.
+ */
+
+#if defined(FREEBSD_USB)
+
+/*
+ * XXX - Should this be autoconf'd instead?
+ */
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+
+#if !defined(USBMOUSE_SUPPORT)
+#define USBMOUSE_SUPPORT
+#endif
+#if !defined(HAS_LIB_USB_HID)
+#define HAS_LIB_USB_HID
+#endif
+#if !defined(XPS2_SUPPORT)
+#define XPS2_SUPPORT
+#endif
+
+#endif /* defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__) */
+
+#endif /* defined(FREEBSD_USB) */
+
 #include <xorg-server.h>
 
 #include <X11/X.h>
@@ -33,12 +68,33 @@
 #include "xf86Priv.h"
 #include "xf86_OSlib.h"
 #include "xf86Xinput.h"
+#if defined(FREEBSD_USB)
+#include <exevents.h>
+#endif
 #include "mouse.h"
 #include "xisb.h"
 #include "mipointer.h"
+
+#if defined(FREEBSD_USB)
+#if GET_ABI_MAJOR(ABI_XINPUT_VERSION) >= 3
+#define HAVE_PROPERTIES 1
+#endif
+#ifdef HAVE_PROPERTIES
+#include <X11/Xatom.h>
+#include <xserver-properties.h>
+/* 1.6 has properties, but no labels */
+#ifdef AXIS_LABEL_PROP
+#define HAVE_LABELS
+#else
+#undef HAVE_LABELS
+#endif
+#endif
+#endif /* defined(FREEBSD_USB) */
+
 #ifdef WSCONS_SUPPORT
 #include <dev/wscons/wsconsio.h>
 #endif
+
 #ifdef USBMOUSE_SUPPORT
 #ifdef HAS_LIB_USB_HID
 #include <usbhid.h>
@@ -46,10 +102,25 @@
 #include "usb.h"
 #endif
 
+#if defined(FREEBSD_USB)
+
+#if defined(DRAGONFLY_U4B)
+#include <sys/param.h>
+#include <bus/u4b/usb.h>
+#elif defined(DRAGONFLY_USB)
+#include <sys/param.h>
+#include <bus/usb/usb.h>
+#else
 #include <dev/usb/usb.h>
+#endif
+
+#endif /* defined(FREEBSD_USB) */
+
+#if !defined(FREEBSD_USB)
 #ifdef USB_GET_REPORT_ID
 #define USB_NEW_HID
 #endif
+#endif /* !defined(FREEBSD_USB) */
 
 #define HUP_GENERIC_DESKTOP     0x0001
 #define HUP_BUTTON              0x0009
@@ -76,10 +147,17 @@ static const char *FindDevice(InputInfoP
 #define DEFAULT_SYSMOUSE_DEV            "/dev/sysmouse"
 #define DEFAULT_PS2_DEV                 "/dev/psm0"
 
+#if defined(FREEBSD_USB)
+#define DEFAULT_USB_DEV                 "/dev/ums0"
+#endif
+
 static const char *mouseDevs[] = {
         DEFAULT_MOUSE_DEV,
         DEFAULT_SYSMOUSE_DEV,
         DEFAULT_PS2_DEV,
+#if defined(FREEBSD_USB)
+        DEFAULT_USB_DEV,
+#endif
         NULL
 };
 #elif (defined(__OpenBSD__) || defined(__NetBSD__)) && defined(WSCONS_SUPPORT)
@@ -97,11 +175,23 @@ static const char *mouseDevs[] = {
 static int
 SupportedInterfaces(void)
 {
+#if !defined(FREEBSD_USB)
+
 #if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__) || defined(__NetBSD__)
     return MSE_SERIAL | MSE_BUS | MSE_PS2 | MSE_AUTO | MSE_MISC;
 #else
     return MSE_SERIAL | MSE_BUS | MSE_PS2 | MSE_XPS2 | MSE_AUTO | MSE_MISC;
 #endif
+
+#else /* defined(FREEBSD_USB) */
+
+#if defined(__NetBSD__)
+    return MSE_SERIAL | MSE_BUS | MSE_PS2 | MSE_AUTO | MSE_MISC;
+#else
+    return MSE_SERIAL | MSE_BUS | MSE_PS2 | MSE_XPS2 | MSE_AUTO | MSE_MISC;
+#endif
+
+#endif /* !defined(FREEBSD_USB) */
 }
 
 /* Names of protocols that are handled internally here. */
@@ -178,9 +268,34 @@ static struct {
         { MOUSE_PROTO_SYSMOUSE,         "SysMouse" }
 };
 
+#if defined(FREEBSD_USB)
+#ifdef XPS2_SUPPORT
+static struct {
+        int dmodel;
+        const char *name;
+} ps2proto[] = {
+        { MOUSE_MODEL_NETSCROLL,        "NetScrollPS/2" },
+        { MOUSE_MODEL_NET,              "NetMousePS/2" },
+        { MOUSE_MODEL_GLIDEPOINT,       "GlidePointPS/2" },
+        { MOUSE_MODEL_THINK,            "ThinkingMousePS/2" },
+        { MOUSE_MODEL_INTELLI,          "IMPS/2" },
+        { MOUSE_MODEL_MOUSEMANPLUS,     "MouseManPlusPS/2" },
+        { MOUSE_MODEL_EXPLORER,         "ExplorerPS/2" },
+        { MOUSE_MODEL_4D,               "IMPS/2" },
+        { MOUSE_MODEL_4DPLUS,           "IMPS/2" },
+};
+#endif
+#endif /* defined(FREEBSD_USB) */
+
 static const char *
 SetupAuto(InputInfoPtr pInfo, int *protoPara)
 {
+#if defined(FREEBSD_USB)
+#ifdef XPS2_SUPPORT
+    const char *dev;
+#endif
+    const char *proto;
+#endif /* defined(FREEBSD_USB) */
     int i;
     mousehw_t hw;
     mousemode_t mode;
@@ -189,6 +304,14 @@ SetupAuto(InputInfoPtr pInfo, int *proto
         return NULL;
 
     /* set the driver operation level, if applicable */
+#if defined (FREEBSD_USB)
+#ifdef XPS2_SUPPORT
+    dev = xf86FindOptionValue(pInfo->options, "Device");
+    if (dev != NULL && !strncmp(dev, DEFAULT_PS2_DEV, 8))
+        i = 2;
+    else
+#endif
+#endif /* defined(FREEBSD_USB) */
     i = 1;
     ioctl(pInfo->fd, MOUSE_SETLEVEL, &i);
 
@@ -207,9 +330,27 @@ SetupAuto(InputInfoPtr pInfo, int *proto
                     protoPara[0] = mode.syncmask[0];
                     protoPara[1] = mode.syncmask[1];
                 }
+#if defined(FREEBSD_USB)
+                proto = devproto[i].name;
+#ifdef XPS2_SUPPORT
+                if (mode.protocol == MOUSE_PROTO_PS2)
+                    for (i = 0; i < sizeof(ps2proto)/sizeof(ps2proto[0]); ++i)
+                        if (hw.model == ps2proto[i].dmodel) {
+                           proto = ps2proto[i].name;
+                           break;
+                }
+#endif
+#endif /* defined(FREEBSD_USB) */
+
+#if !defined(FREEBSD_USB)
                 xf86MsgVerb(X_INFO, 3, "%s: SetupAuto: protocol is %s\n",
                             pInfo->name, devproto[i].name);
                 return devproto[i].name;
+#else /* defined(FREEBSD_USB) */
+                xf86MsgVerb(X_INFO, 3, "%s: SetupAuto: protocol is %s\n",
+                            pInfo->name, proto);
+                return proto;
+#endif /* !defined(FREEBSD_USB) */
             }
         }
     }
@@ -227,6 +368,9 @@ SetSysMouseRes(InputInfoPtr pInfo, const
     mode.rate = rate > 0 ? rate : -1;
     mode.resolution = res > 0 ? res : -1;
     mode.accelfactor = -1;
+
+#if !defined(FREEBSD_USB)
+
 #if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
     if (pMse->autoProbe ||
         (protocol && xf86NameCmp(protocol, "SysMouse") == 0)) {
@@ -241,13 +385,35 @@ SetSysMouseRes(InputInfoPtr pInfo, const
 #else
     mode.level = -1;
 #endif
+
+#else /* defined(FREEBSD_USB) */
+
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+    if (pMse->autoProbe ||
+        (protocol && xf86NameCmp(protocol, "SysMouse") == 0)) {
+        /*
+         * As the FreeBSD sysmouse driver defaults to protocol level 0
+         * everytime it is closed we enforce protocol level 1 again at
+         * this point.
+         */
+        mode.level = 1;
+    } else
+#endif
+    mode.level = -1;
+
+#endif /* !defined(FREEBSD_USB) */
+
     ioctl(pInfo->fd, MOUSE_SETMODE, &mode);
 }
 #endif
 
 #if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
 
+#if !defined(FREEBSD_USB)
 #define MOUSED_PID_FILE "/var/run/moused.pid"
+#endif
+
+#if !defined(FREEBSD_USB)
 
 /*
  * Try to check if moused is running.  DEFAULT_SYSMOUSE_DEV is useless without
@@ -271,20 +437,66 @@ MousedRunning(void)
     return FALSE;
 }
 
+#else /* defined(FREEBSD_USB) */
+
+/*
+ * Try to check if moused is running.  DEFAULT_SYSMOUSE_DEV is useless without
+ * it.  Also, try to check if the device is used by moused.  If it is opened
+ * by moused, we do not want to use it directly.  There doesn't seem to be
+ * a better way of checking.
+ */
+static Bool
+MousedRunning(const char *dev)
+{
+    char cmd[128];
+    FILE *f = NULL;
+    unsigned int i;
+
+    if (dev)
+        sprintf(cmd, "sh -c 'fstat %s | grep -c moused' 2>/dev/null", dev);
+    else
+        sprintf(cmd, "sh -c 'pgrep -nx moused' 2>/dev/null");
+    if ((f = popen(cmd, "r")) != NULL) {
+        if (fscanf(f, "%u", &i) == 1 && i > 0) {
+            pclose(f);
+            return TRUE;
+        }
+        pclose(f);
+    }
+    return FALSE;
+}
+
+#endif /* !defined(FREEBSD_USB) */
+
 static const char *
 FindDevice(InputInfoPtr pInfo, const char *protocol, int flags)
 {
+#if !defined(FREEBSD_USB)
     int fd = -1;
+#else
+    int ret = -1;
+#endif
     const char **pdev, *dev = NULL;
     Bool devMouse = FALSE;
     struct stat devMouseStat;
     struct stat sb;
 
     for (pdev = mouseDevs; *pdev; pdev++) {
+
+#if !defined(FREEBSD_USB)
         SYSCALL (fd = open(*pdev, O_RDWR | O_NONBLOCK));
         if (fd == -1) {
+#else
+        SYSCALL (ret = stat(*pdev, &sb));
+        if (ret == -1) {
+#endif /* !defined(FREEBSD_USB) */
+
 #ifdef DEBUG
+#if !defined(FREEBSD_USB)
             ErrorF("Cannot open %s (%s)\n", *pdev, strerror(errno));
+#else
+            ErrorF("Cannot stat %s (%s)\n", *pdev, strerror(errno));
+#endif /* !defined(FREEBSD_USB) */
 #endif
         } else {
             /*
@@ -293,28 +505,70 @@ FindDevice(InputInfoPtr pInfo, const cha
              * the test for whether /dev/sysmouse is usable can be made.
              */
             if (!strcmp(*pdev, DEFAULT_MOUSE_DEV)) {
+#if !defined(FREEBSD_USB)
                 if (fstat(fd, &devMouseStat) == 0)
                     devMouse = TRUE;
                 close(fd);
+#else
+                memcpy(&devMouseStat, &sb, sizeof(devMouseStat));
+                devMouse = TRUE;
+#endif /* !defined(FREEBSD_USB) */
                 continue;
             } else if (!strcmp(*pdev, DEFAULT_SYSMOUSE_DEV)) {
                 /* Check if /dev/mouse is the same as /dev/sysmouse. */
+#if !defined(FREEBSD_USB)
                 if (devMouse && fstat(fd, &sb) == 0 &&
                     devMouseStat.st_dev == sb.st_dev &&
                     devMouseStat.st_ino == sb.st_ino) {
+#else
+                if (devMouse && devMouseStat.st_dev == sb.st_dev &&
+                    devMouseStat.st_ino == sb.st_ino) {
+#endif /* !defined(FREEBSD_USB) */
                     /* If the same, use /dev/sysmouse. */
                     devMouse = FALSE;
                 }
+
+#if !defined(FREEBSD_USB)
                 close(fd);
                 if (MousedRunning())
+#else
+                if (MousedRunning(NULL))
+#endif /* !defined(FREEBSD_USB) */
+
                     break;
+
+#if !defined(FREEBSD_USB)
                 else {
 #ifdef DEBUG
                     ErrorF("moused isn't running\n");
 #endif
                 }
+#endif /* !defined(FREEBSD_USB) */
+
             } else {
+
+#if !defined(FREEBSD_USB)
+
                 close(fd);
+
+#else /* defined(FREEBSD_USB) */
+
+                /* Check if /dev/mouse is the same as this device. */
+                if (devMouse && devMouseStat.st_dev == sb.st_dev &&
+                    devMouseStat.st_ino == sb.st_ino) {
+                    /* If the same, use this device. */
+                    devMouse = FALSE;
+                }
+                if (MousedRunning(*pdev))
+                    continue;
+                /* ums(4) does not support anything but SysMouse protocol. */
+                if (!strncmp(*pdev, DEFAULT_USB_DEV, 8) && protocol &&
+                    xf86NameCmp(protocol, "auto") != 0 &&
+                    xf86NameCmp(protocol, "sysmouse") != 0)
+                    continue;
+
+#endif /* !defined(FREEBSD_USB) */
+
                 break;
             }
         }
@@ -486,8 +740,17 @@ wsconsPreInit(InputInfoPtr pInfo, const
 
 #if defined(USBMOUSE_SUPPORT)
 
+#if defined(FREEBSD_USB)
+#define MAXRIDS		64
+#define MAXACOLS	8
+#define MAXLCOLS	16
+#endif
+
 typedef struct _UsbMseRec {
     int packetSize;
+
+#if !defined(FREEBSD_USB)
+
     int iid;
     hid_item_t loc_x;           /* x locator item */
     hid_item_t loc_y;           /* y locator item */
@@ -495,22 +758,92 @@ typedef struct _UsbMseRec {
     hid_item_t loc_w;           /* z (wheel) locator item */
     hid_item_t loc_btn[MSE_MAXBUTTONS]; /* buttons locator items */
    unsigned char *buffer;
+
+#else /* defined(FREEBSD_USB) */
+
+    int iid, nrids, nacols, opened;
+    struct {
+	int32_t rid;
+	int size;
+    } rids[MAXRIDS];
+    struct UsbMseAcol {
+	InputInfoPtr pInfo;
+	int nlcols, nbuttons, hasZ, hasW;
+	int xmin, xmax, ymin, ymax, pmin, pmax, px, py;
+	int cxmin, cxmax, cymin, cymax, cpmin, cpmax;
+	struct UsbMseLcol {
+	    hid_item_t loc_x;		/* x locator item */
+	    hid_item_t loc_y;		/* y locator item */
+	    hid_item_t loc_z;		/* z (wheel) locator item */
+	    hid_item_t loc_w;		/* w (hwheel) locator item */
+	    hid_item_t loc_p;		/* Tip Pressure */
+	    hid_item_t loc_valid;		/* Touch Valid */
+	    hid_item_t loc_in_range;	/* In Range */
+	    hid_item_t loc_btn[MSE_MAXBUTTONS]; /* buttons locator items */
+	} lcols[MAXLCOLS];
+	hid_item_t loc_cc;		/* contact count */
+    } acols[MAXACOLS];
+    unsigned char *buffer;
+
+#endif /* !defined(FREEBSD_USB) */
+
 } UsbMseRec, *UsbMsePtr;
 
+#if defined(FREEBSD_USB)
+static int *
+usbGetReportSizePtr(UsbMsePtr pUsbMse, int32_t rid)
+{
+    int i;
+
+    for (i = 0; i < pUsbMse->nrids; i++) {
+	if (pUsbMse->rids[i].rid == rid)
+	    return (&pUsbMse->rids[i].size);
+    }
+    for (i = 0; i < MAXRIDS; i++) {
+	if (pUsbMse->rids[i].size == 0) {
+	    pUsbMse->rids[i].rid = rid;
+	    pUsbMse->nrids = max(pUsbMse->nrids, i + 1);
+	    return (&pUsbMse->rids[i].size);
+	}
+    }
+    return (NULL);
+}
+#endif /* defined(FREEBSD_USB) */
+
 static int
 usbMouseProc(DeviceIntPtr pPointer, int what)
 {
     InputInfoPtr pInfo;
     MouseDevPtr pMse;
     UsbMsePtr pUsbMse;
+#if defined(FREEBSD_USB)
+    struct UsbMseAcol *acol;
+#endif
     unsigned char map[MSE_MAXBUTTONS + 1];
+
+#if !defined(FREEBSD_USB)
     int nbuttons;
+#else /* defined (FREEBSD_USB) */
+    int nacol, nbuttons;
+#ifdef HAVE_LABELS
+    Atom btn_labels[MSE_MAXBUTTONS] = {0};
+    Atom axes_labels[3] = { 0, 0, 0 };
+#endif
+#endif /* !defined(FREEBSD_USB) */
 
     pInfo = pPointer->public.devicePrivate;
     pMse = pInfo->private;
     pMse->device = pPointer;
     pUsbMse = pMse->mousePriv;
 
+#if defined(FREEBSD_USB)
+    for (nacol = 0; nacol < (pUsbMse->nacols - 1); nacol++) {
+	if (pUsbMse->acols[nacol].pInfo == pInfo)
+	    break;
+    }
+    acol = &pUsbMse->acols[nacol];
+#endif
+
     switch (what) {
     case DEVICE_INIT:
         pPointer->public.on = FALSE;
@@ -518,23 +851,114 @@ usbMouseProc(DeviceIntPtr pPointer, int
         for (nbuttons = 0; nbuttons < MSE_MAXBUTTONS; ++nbuttons)
             map[nbuttons + 1] = nbuttons + 1;
 
+#if !defined(FREEBSD_USB)
         InitPointerDeviceStruct((DevicePtr)pPointer,
                                 map,
                                 min(pMse->buttons, MSE_MAXBUTTONS),
                                 miPointerGetMotionEvents,
                                 pMse->Ctrl,
                                 miPointerGetMotionBufferSize());
+#else /* defined(FREEBSD_USB) */
+
+#ifdef HAVE_LABELS
+	btn_labels[0] = XIGetKnownProperty(BTN_LABEL_PROP_BTN_LEFT);
+	btn_labels[1] = XIGetKnownProperty(BTN_LABEL_PROP_BTN_MIDDLE);
+	btn_labels[2] = XIGetKnownProperty(BTN_LABEL_PROP_BTN_RIGHT);
+	axes_labels[0] = XIGetKnownProperty((acol->xmin != acol->xmax)
+	    ? AXIS_LABEL_PROP_ABS_X : AXIS_LABEL_PROP_REL_X);
+	axes_labels[1] = XIGetKnownProperty((acol->xmin != acol->xmax)
+	    ? AXIS_LABEL_PROP_ABS_Y : AXIS_LABEL_PROP_REL_Y);
+	axes_labels[2] = XIGetKnownProperty(AXIS_LABEL_PROP_ABS_PRESSURE);
+#endif
+
+	InitButtonClassDeviceStruct(pPointer, min(pMse->buttons, MSE_MAXBUTTONS),
+#ifdef HAVE_LABELS
+	    btn_labels,
+#endif
+	    map);
+	InitValuatorClassDeviceStruct(pPointer, (acol->pmin != acol->pmax) ? 3 : 2,
+#ifdef HAVE_LABELS
+	    axes_labels,
+#endif
+#if GET_ABI_MAJOR(ABI_XINPUT_VERSION) == 0
+	    miPointerGetMotionEvents,
+#elif GET_ABI_MAJOR(ABI_XINPUT_VERSION) < 3
+	    GetMotionHistory,
+#endif
+	    GetMotionHistorySize(),
+	    (acol->xmin != acol->xmax || acol->ymin != acol->ymax) ?
+	     Absolute : Relative);
+	InitPtrFeedbackClassDeviceStruct(pPointer, pMse->Ctrl);
+
+#endif /* !defined(FREEBSD_USB) */
 
         /* X valuator */
+#if !defined(FREEBSD_USB)
+
         xf86InitValuatorAxisStruct(pPointer, 0, 0, -1, 1, 0, 1);
         xf86InitValuatorDefaults(pPointer, 0);
+
+#else /* defined(FREEBSD_USB) */
+
+	xf86InitValuatorAxisStruct(pPointer, 0,
+#ifdef HAVE_LABELS
+	    axes_labels[0],
+#endif
+	    (acol->xmin != acol->xmax) ? acol->xmin : -1,
+	    (acol->xmin != acol->xmax) ? acol->xmax : -1,
+	    1, 0, 1
+#if GET_ABI_MAJOR(ABI_XINPUT_VERSION) >= 12
+	    , (acol->xmin != acol->xmax) ? Absolute : Relative
+#endif
+	    );
+        xf86InitValuatorDefaults(pPointer, 0);
+
+#endif /* !defined(FREEBSD_USB) */
+
         /* Y valuator */
+
+#if !defined(FREEBSD_USB)
+
         xf86InitValuatorAxisStruct(pPointer, 1, 0, -1, 1, 0, 1);
         xf86InitValuatorDefaults(pPointer, 1);
+
+#else /* defined(FREEBSD_USB) */
+
+	xf86InitValuatorAxisStruct(pPointer, 1,
+#ifdef HAVE_LABELS
+	    axes_labels[1],
+#endif
+	    (acol->ymin != acol->ymax) ? acol->ymin : -1,
+	    (acol->ymin != acol->ymax) ? acol->ymax : -1,
+	    1, 0, 1
+#if GET_ABI_MAJOR(ABI_XINPUT_VERSION) >= 12
+	    , (acol->ymin != acol->ymax) ? Absolute : Relative
+#endif
+	    );
+        xf86InitValuatorDefaults(pPointer, 1);
+	/* Pressure valuator */
+	if (acol->pmin != acol->pmax) {
+	    xf86InitValuatorAxisStruct(pPointer, 2,
+#ifdef HAVE_LABELS
+		axes_labels[2],
+#endif
+		acol->pmin, acol->pmax, 1, 0, 1
+#if GET_ABI_MAJOR(ABI_XINPUT_VERSION) >= 12
+		, Absolute
+#endif
+		);
+	    xf86InitValuatorDefaults(pPointer, 2);
+	}
+
+#endif /* !defined(FREEBSD_USB) */
+
         xf86MotionHistoryAllocate(pInfo);
         break;
 
     case DEVICE_ON:
+
+#if !defined(FREEBSD_USB)
+
         pInfo->fd = xf86OpenSerial(pInfo->options);
         if (pInfo->fd == -1)
             xf86Msg(X_WARNING, "%s: cannot open input device\n", pInfo->name);
@@ -551,6 +975,30 @@ usbMouseProc(DeviceIntPtr pPointer, int
                     AddEnabledDevice(pInfo->fd);
             }
         }
+
+#else /* defined(FREEBSD_USB) */
+
+	if (pUsbMse->opened++ == 0) {
+		pInfo->fd = xf86OpenSerial(pInfo->options);
+		if (pInfo->fd == -1)
+		    xf86Msg(X_WARNING, "%s: cannot open input device\n", pInfo->name);
+		else {
+		    pMse->buffer = XisbNew(pInfo->fd, pUsbMse->packetSize);
+		    if (!pMse->buffer) {
+			free(pMse);
+			xf86CloseSerial(pInfo->fd);
+			pInfo->fd = -1;
+		    } else {
+			xf86FlushInput(pInfo->fd);
+			if (!xf86InstallSIGIOHandler (pInfo->fd, usbSigioReadInput, 
+						      pInfo))
+			    AddEnabledDevice(pInfo->fd);
+		    }
+		}
+        }
+
+#endif /* !defined(FREEBSD_USB) */
+
         pMse->lastButtons = 0;
         pMse->lastMappedButtons = 0;
         pMse->emulateState = 0;
@@ -571,6 +1019,9 @@ usbMouseProc(DeviceIntPtr pPointer, int
             xf86CloseSerial(pInfo->fd);
             pInfo->fd = -1;
         }
+#if defined(FREEBSD_USB)
+        pUsbMse->opened--;
+#endif
         pPointer->public.on = FALSE;
         usleep(300000);
         break;
@@ -586,27 +1037,86 @@ usbReadInput(InputInfoPtr pInfo)
 {
     MouseDevPtr pMse;
     UsbMsePtr pUsbMse;
+
+#if !defined(FREEBSD_USB)
     int buttons = pMse->lastButtons;
     int dx = 0, dy = 0, dz = 0, dw = 0;
     int n, c;
+#else
+    int buttons, cc;
+    int dx, dy, dz, dw, dp, upd, v, nx, ny, np, in_range;
+    int n, c, rid, *sizep, nacol, nlcol;
+#endif /* !defined(FREEBSD_USB) */
+
     unsigned char *pBuf;
 
+#if defined(FREEBSD_USB)
+    struct UsbMseAcol *acol;
+    struct UsbMseLcol *lcol;
+#endif
     pMse = pInfo->private;
     pUsbMse = pMse->mousePriv;
 
     XisbBlockDuration(pMse->buffer, -1);
+#if defined(FREEBSD_USB)
+next:
+#endif
     pBuf = pUsbMse->buffer;
     n = 0;
+
+#if !defined(FREEBSD_USB)
+
     while ((c = XisbRead(pMse->buffer)) >= 0 && n < pUsbMse->packetSize) {
         pBuf[n++] = (unsigned char)c;
+
+    }
+#else /* defined(FREEBSD_USB) */
+
+    if (pUsbMse->iid) {
+	rid = XisbRead(pMse->buffer);
+	if (rid < 0)
+	    return;
+	pBuf[n++] = (unsigned char)rid;
+    } else
+	rid = 0;
+    sizep = usbGetReportSizePtr(pUsbMse, rid);
+    if (sizep == NULL || *sizep == 0) {
+	xf86Msg(X_WARNING, "%s: unknown report ID %d\n", pInfo->name, rid);
+	goto next;
     }
+    while (n < *sizep && (c = XisbRead(pMse->buffer)) >= 0) {
+        pBuf[n++] = (unsigned char)c;
+    }
+
+#endif /* !defined(FREEBSD_USB) */
+
     if (n == 0)
         return;
+
+#if !defined(FREEBSD_USB)
+
     if (n != pUsbMse->packetSize) {
         LogMessageVerbSigSafe(X_WARNING, -1,
                               "%s: incomplete packet, size %d\n",
                               pInfo->name, n);
     }
+
+#else /* defined(FREEBSD_USB) */
+
+    if (n == 0)
+        return;
+//    xf86MsgVerb(X_INFO, 3, "pkt: %d %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x\n",
+//	n, pBuf[0], pBuf[1], pBuf[2], pBuf[3], pBuf[4], pBuf[5], pBuf[6], pBuf[7], pBuf[8], pBuf[9]);
+    if (n != *sizep) {
+        LogMessageVerbSigSafe(X_WARNING, -1,
+                              "%s: incomplete packet, size %d\n",
+                              pInfo->name, n);
+    }
+
+#endif /* !defined(FREEBSD_USB) */
+
+#if !defined(FREEBSD_USB)
+
     /* discard packets with an id that don't match the mouse */
     /* XXX this is probably not the right thing */
     if (pUsbMse->iid != 0) {
@@ -625,6 +1135,122 @@ usbReadInput(InputInfoPtr pInfo)
     }
     pMse->PostEvent(pInfo, buttons, dx, dy, dz, dw);
     return;
+
+#else /* defined(FREEBSD_USB) */
+
+    for (nacol = 0; nacol < pUsbMse->nacols; nacol++) {
+	acol = &pUsbMse->acols[nacol];
+	if (acol->pInfo == NULL)
+	    continue;
+	nx = ny = np = upd = 0;
+	buttons = cc = 0;
+	dx = dy = dz = dw = dp = 0;
+	for (nlcol = 0; nlcol < pUsbMse->acols[nacol].nlcols; nlcol++) {
+	    lcol = &acol->lcols[nlcol];
+
+	    if (lcol->loc_valid.usage != 0 && rid == lcol->loc_valid.report_ID &&
+		    hid_get_data(pBuf, &lcol->loc_valid) == 0)
+		continue;
+	    if (lcol->loc_in_range.usage != 0 && rid == lcol->loc_in_range.report_ID)
+		in_range = hid_get_data(pBuf, &lcol->loc_in_range);
+	    else
+		in_range = 1;
+	    if (in_range && lcol->loc_x.usage != 0 && rid == lcol->loc_x.report_ID && nx == 0) {
+		v = hid_get_data(pBuf, &lcol->loc_x);
+		if (acol->xmin != acol->xmax) {
+		    v = xf86ScaleAxis(v, acol->xmax, acol->xmin,
+			lcol->loc_x.logical_maximum, lcol->loc_x.logical_minimum);
+		    if (acol->cxmin != acol->cxmax)
+		        v = xf86ScaleAxis(v, acol->xmax, acol->xmin,
+			    acol->cxmax, acol->cxmin);
+		}
+		dx += v;
+		nx++;
+	    }
+	    if (in_range && lcol->loc_y.usage != 0 && rid == lcol->loc_y.report_ID && ny == 0) {
+		v = hid_get_data(pBuf, &lcol->loc_y);
+		if (acol->xmin != acol->xmax) {
+		    v = xf86ScaleAxis(v, acol->ymax, acol->ymin,
+			lcol->loc_y.logical_maximum, lcol->loc_y.logical_minimum);
+		    if (acol->cymin != acol->cymax)
+		        v = xf86ScaleAxis(v, acol->ymax, acol->ymin,
+			    acol->cymax, acol->cymin);
+		}
+		dy += v;
+		ny++;
+	    }
+	    if (lcol->loc_z.usage != 0 && rid == lcol->loc_z.report_ID) {
+		dz -= hid_get_data(pBuf, &lcol->loc_z);
+		upd = 1;
+	    }
+	    if (lcol->loc_w.usage != 0 && rid == lcol->loc_w.report_ID) {
+		dw += hid_get_data(pBuf, &lcol->loc_w);
+		upd = 1;
+	    }
+	    if (lcol->loc_p.usage != 0 && rid == lcol->loc_p.report_ID && np == 0) {
+		v = hid_get_data(pBuf, &lcol->loc_p);
+		    v = xf86ScaleAxis(v, acol->pmax, acol->pmin,
+			lcol->loc_p.logical_maximum, lcol->loc_p.logical_minimum);
+		    if (acol->cpmin != acol->cpmax)
+		        v = xf86ScaleAxis(v, acol->pmax, acol->pmin,
+			    acol->cpmax, acol->cpmin);
+		dp += v;
+		np++;
+	    }
+
+	    for (n = 0; n < acol->nbuttons; n++) {
+		if (lcol->loc_btn[n].usage != 0 && rid == lcol->loc_btn[n].report_ID) {
+		    if (hid_get_data(pBuf, &lcol->loc_btn[n]))
+			buttons |= (1 << UMS_BUT(n));
+		    upd = 1;
+		}
+	    }
+	}
+	if (acol->loc_cc.usage != 0 && rid == acol->loc_cc.report_ID)
+	    cc = hid_get_data(pBuf, &acol->loc_cc);
+	else
+	    cc = (nx || ny) ? 1 : 0;
+	if (cc > 1)
+	    buttons = (1 << UMS_BUT(1));
+	if (nx != 0 && acol->xmin != acol->xmax)
+	    dx /= nx;
+	if (ny != 0 && acol->ymin != acol->ymax)
+	    dy /= ny;
+	if (np != 0 && acol->pmin != acol->pmax)
+	    dp /= np;
+//	if (upd || nx || ny || np)
+//	    xf86MsgVerb(X_INFO, 3, "%d cc %d dx %d dy %d dz %d dw %d press %d buttons %02x\n",
+//		nacol, cc, dx, dy, dz, dw, dp, buttons);
+	if (nx != 0 || ny != 0) {
+	    if (acol->pmin != acol->pmax) {
+		xf86PostMotionEvent(acol->pInfo->dev,
+			    /* is_absolute: */    TRUE,
+			    /* first_valuator: */ 0,
+			    /* num_valuators: */  3,
+			    dx, dy, dp);
+	    } else if (acol->xmin != acol->xmax || acol->ymin != acol->ymax) {
+		xf86PostMotionEvent(acol->pInfo->dev,
+			    /* is_absolute: */    TRUE,
+			    /* first_valuator: */ 0,
+			    /* num_valuators: */  2,
+			    dx, dy);
+	    }
+	}
+	if (upd || (nx != 0) || (ny != 0)) {
+	    ((MouseDevPtr)acol->pInfo->private)->PostEvent(acol->pInfo, buttons,
+		((acol->xmin != acol->xmax) ? dx - acol->px : dx),
+		((acol->ymin != acol->ymax) ? dy - acol->py : dy),
+		dz, dw);
+	}
+	if (nx > 0)
+	    acol->px = dx;
+	if (ny > 0)
+	    acol->py = dy;
+    }
+    goto next;
+
+#endif /* !defined(FREEBSD_USB) */
+
 }
 
 static void
@@ -633,15 +1259,27 @@ usbSigioReadInput (int fd, void *closure
     usbReadInput ((InputInfoPtr) closure);
 }
 
+#if !defined(FREEBSD_USB)
 /* This function is called when the protocol is "usb". */
 static Bool
 usbPreInit(InputInfoPtr pInfo, const char *protocol, int flags)
+#else
+static Bool
+usbInitFirst(InputInfoPtr pInfo)
+#endif /* !defined(FREEBSD_USB) */
 {
     MouseDevPtr pMse = pInfo->private;
     UsbMsePtr pUsbMse;
     report_desc_t reportDesc;
+#if !defined(FREEBSD_USB)
     int i;
-
+#else
+    hid_data_t d;
+    hid_item_t h;
+    struct UsbMseAcol *acol;
+    struct UsbMseLcol *lcol;
+    int mdepth, rsize, *rsizep, acolused, lcolused, used;
+#endif /* !defined(FREEBSD_USB) */
     pUsbMse = malloc(sizeof(UsbMseRec));
     if (pUsbMse == NULL) {
         xf86Msg(X_ERROR, "%s: cannot allocate UsbMouseRec\n", pInfo->name);
@@ -649,12 +1287,16 @@ usbPreInit(InputInfoPtr pInfo, const cha
         return FALSE;
     }
 
+#if !defined(FREEBSD_USB)
     pMse->protocol = protocol;
     xf86Msg(X_CONFIG, "%s: Protocol: %s\n", pInfo->name, protocol);
 
     /* Collect the options, and process the common options. */
     COLLECT_INPUT_OPTIONS(pInfo, NULL);
     xf86ProcessCommonOptions(pInfo, pInfo->options);
+#else
+    bzero(pUsbMse, sizeof(UsbMseRec));
+#endif /* !defined(FREEBSD_USB) */
 
     /* Check if the device can be opened. */
     pInfo->fd = xf86OpenSerial(pInfo->options);
@@ -670,6 +1312,9 @@ usbPreInit(InputInfoPtr pInfo, const cha
     }
     /* Get USB informations */
     reportDesc = hid_get_report_desc(pInfo->fd);
+
+#if !defined(FREEBSD_USB)
+
     /* Get packet size & iid */
 #ifdef USB_NEW_HID
     if (ioctl(pInfo->fd, USB_GET_REPORT_ID, &pUsbMse->iid) == -1) {
@@ -683,6 +1328,139 @@ usbPreInit(InputInfoPtr pInfo, const cha
     pUsbMse->packetSize = hid_report_size(reportDesc, hid_input,
                                               &pUsbMse->iid);
 #endif
+
+#else /* defined(FREEBSD_USB) */
+
+    mdepth = 0;
+    pUsbMse->nacols = 0;
+    acol = &pUsbMse->acols[pUsbMse->nacols];
+    lcol = &acol->lcols[acol->nlcols];
+    acolused = 0;
+    lcolused = 0;
+    d = hid_start_parse(reportDesc, (1 << hid_input) |
+	(1 << hid_collection) | (1 << hid_endcollection), -1);
+    while (hid_get_item(d, &h)) {
+	switch (h.kind) {
+	case hid_collection:
+	    if (mdepth != 0)
+		mdepth++;
+	    else if (h.collection == 1 &&
+		    (h.usage == 0x00010001 || h.usage == 0x00010002 ||
+		     (h.usage >= 0x000d0001 && h.usage <= 0x000d000d))) {
+		mdepth++;
+		if (acolused) {
+		    if (lcolused) {
+			acol->nlcols++;
+			lcolused = 0;
+		    }
+		    pUsbMse->nacols++;
+		    acolused = 0;
+		    acol = &pUsbMse->acols[pUsbMse->nacols];
+		    lcol = &acol->lcols[acol->nlcols];
+		}
+	    }
+	    if (lcolused && (h.collection == 0 ||
+		    h.collection == 2 || h.collection == 3)) {
+		acol->nlcols++;
+		lcolused = 0;
+		lcol = &acol->lcols[acol->nlcols];
+	    }
+	    break;
+	case hid_endcollection:
+	    if (mdepth != 0)
+		mdepth--;
+	    break;
+	case hid_input:
+	    if (h.report_ID != 0)
+		pUsbMse->iid = 1;
+	    rsize = pUsbMse->iid +
+		(h.pos + (h.report_size * h.report_count) + 7) / 8;
+	    if ((rsizep = usbGetReportSizePtr(pUsbMse, h.report_ID)) != NULL)
+		*rsizep = max(*rsizep, rsize);
+	    pUsbMse->packetSize = max(pUsbMse->packetSize, rsize);
+	    if (mdepth == 0)
+		break;
+	    used = 1;
+	    if (h.usage == 0x00010030) { /* X */
+		lcol->loc_x = h;
+		if ((h.flags & 0x04) == 0) {
+		    if (acol->xmin == acol->xmax) {
+			acol->xmin = h.logical_minimum;
+			acol->xmax = h.logical_maximum;
+		    } else {
+			acol->xmin = min(acol->xmin, h.logical_minimum);
+			acol->xmax = max(acol->xmax, h.logical_maximum);
+		    }
+		}
+	    } else if (h.usage == 0x00010031) { /* Y */
+		lcol->loc_y = h;
+		if ((h.flags & 0x04) == 0) {
+		    if (acol->ymin == acol->ymax) {
+			acol->ymin = h.logical_minimum;
+			acol->ymax = h.logical_maximum;
+		    } else {
+			acol->ymin = min(acol->ymin, h.logical_minimum);
+			acol->ymax = max(acol->ymax, h.logical_maximum);
+		    }
+		}
+	    } else if (h.usage == 0x00010038) { /* Z */
+		lcol->loc_z = h;
+		acol->hasZ = 1;
+	    } else if (h.usage == 0x000c0238) { /* W */
+		lcol->loc_w = h;
+		acol->hasW = 1;
+	    } else if (h.usage == 0x000d0030) { /* Press */
+		lcol->loc_p = h;
+		if ((h.flags & 0x04) == 0) {
+		    if (acol->pmin == acol->pmax) {
+			acol->pmin = h.logical_minimum;
+			acol->pmax = h.logical_maximum;
+		    } else {
+			acol->pmin = min(acol->pmin, h.logical_minimum);
+			acol->pmax = max(acol->pmax, h.logical_maximum);
+		    }
+		}
+	    } else if (h.usage == 0x000d0032) /* In Range */
+		lcol->loc_in_range = h;
+	    else if (h.usage == 0x000d0047) /* Valid */
+		lcol->loc_valid = h;
+	    else if (h.usage > 0x00090000 &&
+		h.usage <= 0x00090000 + MSE_MAXBUTTONS) { /* Buttons */
+		    lcol->loc_btn[(h.usage & 0xffff) - 1] = h;
+		    acol->nbuttons = max(acol->nbuttons, h.usage & 0xffff);
+	    } else if (h.usage == 0x000d0042) { /* Tip Switch */
+		lcol->loc_btn[0] = h;
+		acol->nbuttons = max(acol->nbuttons, 1);
+	    } else if (h.usage == 0x000d0044) { /* Barrel Switch */
+		lcol->loc_btn[1] = h;
+		acol->nbuttons = max(acol->nbuttons, 2);
+	    } else if (h.usage == 0x000d0045) { /* Eraser */
+		lcol->loc_btn[3] = h;
+		acol->nbuttons = max(acol->nbuttons, 4);
+	    } else if (h.usage == 0x000d0046) { /* Tablet Pick */
+		lcol->loc_btn[2] = h;
+		acol->nbuttons = max(acol->nbuttons, 3);
+	    } else if (h.usage == 0x000d0054) /* Contact Count */
+		acol->loc_cc = h;
+	    else
+		used = 0;
+	    lcolused += used;
+	    acolused += used;
+	    break;
+	default:
+	    break;
+	}
+    }
+    if (lcolused)
+	acol->nlcols++;
+    if (acolused)
+	pUsbMse->nacols++;
+    hid_end_parse(d);
+    xf86Msg(X_DEFAULT, "%s: Found %d usable logical collections\n",
+	pInfo->name, pUsbMse->nacols);
+
+#endif /* !defined(FREEBSD_USB) */
+
     /* Allocate buffer */
     if (pUsbMse->packetSize <= 8) {
         pUsbMse->buffer = pMse->protoBuf;
@@ -692,10 +1470,15 @@ usbPreInit(InputInfoPtr pInfo, const cha
     if (pUsbMse->buffer == NULL) {
         xf86Msg(X_ERROR, "%s: cannot allocate buffer\n", pInfo->name);
         free(pUsbMse);
+#if !defined(FREEBSD_USB)
         free(pMse);
+#endif
         xf86CloseSerial(pInfo->fd);
         return FALSE;
     }
+
+#if !defined(FREEBSD_USB)
+
 #ifdef USB_NEW_HID
     if (hid_locate(reportDesc, HID_USAGE2(HUP_GENERIC_DESKTOP, HUG_X),
                    hid_input, &pUsbMse->loc_x, pUsbMse->iid) < 0) {
@@ -733,12 +1516,15 @@ usbPreInit(InputInfoPtr pInfo, const cha
     }
     pMse->buttons = i-1;
 
+#endif /* !defined(FREEBSD_USB) */
+
     xf86CloseSerial(pInfo->fd);
     pInfo->fd = -1;
 
     /* Private structure */
     pMse->mousePriv = pUsbMse;
 
+#if !defined(FREEBSD_USB)
     /* Process common mouse options (like Emulate3Buttons, etc). */
     pMse->CommonOptions(pInfo);
 
@@ -749,8 +1535,137 @@ usbPreInit(InputInfoPtr pInfo, const cha
 #if GET_ABI_MAJOR(ABI_XINPUT_VERSION) < 12
     pInfo->flags |= XI86_CONFIGURED;
 #endif
+
+#endif /* !defined(FREEBSD_USB) */
+
     return TRUE;
 }
+
+#if defined(FREEBSD_USB)
+
+/* This function is called when the protocol is "usb". */
+static Bool
+usbPreInit(InputInfoPtr pInfo, const char *protocol, int flags)
+{
+    InputInfoPtr pMatch;
+    MouseDevPtr pMse = pInfo->private;
+    UsbMsePtr pUsbMse;
+    struct UsbMseAcol *acol;
+    char *str;
+    int i, colopt;
+
+    pMse->protocol = protocol;
+    xf86Msg(X_CONFIG, "%s: Protocol: %s\n", pInfo->name, protocol);
+
+    /* Collect the options, and process the common options. */
+    COLLECT_INPUT_OPTIONS(pInfo, NULL);
+    xf86ProcessCommonOptions(pInfo, pInfo->options);
+
+    /* Check if this HID device is already opened. */
+    for (pMatch = xf86FirstLocalDevice(); pMatch != NULL; pMatch = pMatch->next) {
+	if ((pInfo != pMatch) && strstr(pMatch->drv->driverName, "mouse")) {
+	    char *dev1, *dev2;
+
+	    dev1 = xf86SetStrOption(pInfo->options, "Device", NULL);
+	    dev2 = xf86SetStrOption(pMatch->options, "Device", NULL);
+	    if (strcmp(dev1, dev2) == 0) {
+		free(dev1);
+		free(dev2);
+		break;
+	    }
+	    free(dev1);
+	    free(dev2);
+	}
+    }
+    if (pMatch == NULL) {
+	xf86Msg(X_DEFAULT, "%s: Opening new HID device\n", pInfo->name);
+	if (!usbInitFirst(pInfo)) {
+	    free(pMse);
+	    return FALSE;
+	}
+    } else {
+	pMse->mousePriv = ((MouseDevPtr)pMatch->private)->mousePriv;
+	xf86Msg(X_DEFAULT, "%s: Attaching to already opened HID device\n",
+	    pInfo->name);
+    }
+    pUsbMse = pMse->mousePriv;
+
+    /* Attach to collection, respecting "Collection" option. */
+    colopt = xf86SetIntOption(pInfo->options, "Collection", 0);
+    for (i = 0; i < pUsbMse->nacols; i++) {
+	if (pUsbMse->acols[i].pInfo == NULL &&
+		(colopt == 0 || i == colopt - 1)) {
+	    pUsbMse->acols[i].pInfo = pInfo;
+	    break;
+	}
+    }
+    xf86Msg(colopt == 0 ? X_DEFAULT : X_CONFIG,
+	"%s: Collection: %d\n", pInfo->name,
+	i == pUsbMse->nacols ? colopt : i + 1);
+    if (i == pUsbMse->nacols) {
+	xf86Msg(X_ERROR,
+	    "%s: Application collection not found or already handled\n",
+	    pInfo->name);
+	free(pMse);
+	return FALSE;
+    }
+
+    acol = &pUsbMse->acols[i];
+    pMse->buttons = acol->nbuttons;
+    if (pMse->buttons == 2)
+	pMse->buttons = 3;
+    if (acol->xmin != acol->xmax || acol->ymin != acol->ymax)
+	pMse->disableXY = TRUE;
+    pMse->hasZ = acol->hasZ;
+    pMse->hasW = acol->hasW;
+
+    /* Process common mouse options (like Emulate3Buttons, etc). */
+    pMse->CommonOptions(pInfo);
+
+    /* Process "Calibration" option. */
+    str = xf86CheckStrOption(pInfo->options, "Calibration", NULL);
+    if (str != NULL && (acol->xmin != acol->xmax || acol->ymin != acol->ymax)) {
+	int j, xmin, xmax, ymin, ymax, pmin, pmax;
+
+	j = sscanf(str, "%d %d %d %d %d %d", &xmin, &xmax, &ymin, &ymax, &pmin, &pmax);
+	if (j == 4) {
+	    xf86Msg(X_CONFIG, "%s: Calibration: %d %d %d %d\n",
+		pInfo->name, xmin, xmax, ymin, ymax);
+	    acol->cxmin = xmin;
+	    acol->cxmax = xmax;
+	    acol->cymin = ymin;
+	    acol->cymax = ymax;
+	} else if (j == 6) {
+	    xf86Msg(X_CONFIG, "%s: Calibration: %d %d %d %d %d %d\n",
+		pInfo->name, xmin, xmax, ymin, ymax, pmin, pmax);
+	    acol->cxmin = xmin;
+	    acol->cxmax = xmax;
+	    acol->cymin = ymin;
+	    acol->cymax = ymax;
+	    acol->cpmin = pmin;
+	    acol->cpmax = pmax;
+	} else
+	    xf86Msg(X_WARNING, "%s: Calibration: Invalid arguments\n",
+		pInfo->name);
+	free(str);
+    } else if (acol->xmin != acol->xmax || acol->ymin != acol->ymax) {
+	xf86Msg(X_DEFAULT, "%s: Calibration: %d %d %d %d %d %d\n",
+	    pInfo->name, acol->xmin, acol->xmax, acol->ymin, acol->ymax,
+	    acol->pmin, acol->pmax);
+    }
+
+    /* Setup the local procs. */
+    pInfo->device_control = usbMouseProc;
+    pInfo->read_input = usbReadInput;
+
+#if GET_ABI_MAJOR(ABI_XINPUT_VERSION) < 12
+    pInfo->flags |= XI86_CONFIGURED;
+#endif
+    return TRUE;
+}
+
+#endif /* defined(FREEBSD_USB) */
+
 #endif /* USBMOUSE */
 
 static Bool
@@ -784,7 +1699,15 @@ OSMouseInit(int flags)
     p->CheckProtocol = CheckProtocol;
 #if (defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)) && defined(MOUSE_PROTO_SYSMOUSE)
     p->SetupAuto = SetupAuto;
+
+#if !defined(FREEBSD_USB)
+    p->SetPS2Res = SetSysMouseRes;
+#else
+#ifndef XPS2_SUPPORT
     p->SetPS2Res = SetSysMouseRes;
+#endif
+#endif
+
     p->SetBMRes = SetSysMouseRes;
     p->SetMiscRes = SetSysMouseRes;
 #endif
