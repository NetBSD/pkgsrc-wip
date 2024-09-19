$NetBSD: patch-src_wsfb__driver.c,v 1.3 2018/05/13 03:45:07 ryoon Exp $

Add revision 1.15 from xsrc version:
date: 2013-01-31 12:18:01 +0100; author: macallan; state: Exp; lines: +145 -72;
use WSDISPLAYIO_GET_FBINFO if available

Merge upstream commits for server 1.17 compatibility:
586b722fb17b3eb0ab776c170ee21e6a66fc7f22
fa9aabe95a65c4dd12008e16ad66d5c773a7993a
2993b33c466793c984b0c7cfeab06a3e333a29dd

Replace LoaderGetOS with ifdef (fix build with modular-xorg-server-1.20.0)
8069c6970c731c38e105f5dddd5ce83ba88b0773

call ioctl(WSDISPLAYIO_SMODE, ...) in EnterVT/LeaveVT so kernel graphics
drivers get notified when we switch in and out of X

Fix wrong VRAM size calculation on old drivers without GET_FBINFO ioctl.

The linebytes is a byte number of width so it should be
(linebytes * height), not (width * linebytes).

XXX: I'm not sure where WSDISPLAYIO_GET_FBINFO implementation was discussed
     but I wonder if we should use proper ifdef or macro to share this
     third party Xorg driver with OpenBSD...

No need to handle colormap ioctls if cmsize == 0 even in WSFB_CI case.

actually use wsdisplayio_fbinfo::fbi_fboffset

xf86DisableRandR() is gone

The modesetting driver and wsfb access the same hardware but through
different interfaces (/dev/dri/card0 vs /dev/ttyE0). To prevent both
drivers from being active at once, skip wsfb probe if the modesetting
driver has claimed the fb slot.

--- src/wsfb_driver.c.orig	2012-01-01 15:25:08.000000000 +0000
+++ src/wsfb_driver.c
@@ -46,14 +46,19 @@
 #include <sys/types.h>
 #include <sys/mman.h>
 #include <sys/time.h>
+#if defined(STRICT_XSRC_NETBSD)
+#include <errno.h>
+#endif
 #include <dev/wscons/wsconsio.h>
 
 /* All drivers need this. */
 #include "xf86.h"
 #include "xf86_OSproc.h"
+#if defined(STRICT_XSRC_NETBSD)
+#include "xf86_OSlib.h"
+#endif
 
 #include "mipointer.h"
-#include "mibstore.h"
 #include "micmap.h"
 #include "colormapst.h"
 #include "xf86cmap.h"
@@ -61,12 +66,6 @@
 #include "dgaproc.h"
 
 /* For visuals */
-#ifdef HAVE_XF1BPP
-# include "xf1bpp.h"
-#endif
-#ifdef HAVE_XF4BPP
-# include "xf4bpp.h"
-#endif
 #include "fb.h"
 
 #if GET_ABI_MAJOR(ABI_VIDEODRV_VERSION) < 6
@@ -78,6 +77,16 @@
 #include "xf86xv.h"
 #endif
 
+#if defined(HWCURSOR_XSRC_NETBSD)
+#include "wsfb.h"
+
+/* #include "wsconsio.h" */
+
+#include <sys/mman.h>
+#else
+#include "compat-api.h"
+#endif
+
 #ifdef X_PRIVSEP
 extern int priv_open_device(const char *);
 #else
@@ -110,15 +119,15 @@ static const OptionInfoRec * WsfbAvailab
 static void WsfbIdentify(int);
 static Bool WsfbProbe(DriverPtr, int);
 static Bool WsfbPreInit(ScrnInfoPtr, int);
-static Bool WsfbScreenInit(int, ScreenPtr, int, char **);
-static Bool WsfbCloseScreen(int, ScreenPtr);
+static Bool WsfbScreenInit(SCREEN_INIT_ARGS_DECL);
+static Bool WsfbCloseScreen(CLOSE_SCREEN_ARGS_DECL);
 static void *WsfbWindowLinear(ScreenPtr, CARD32, CARD32, int, CARD32 *,
 			      void *);
-static void WsfbPointerMoved(int, int, int);
-static Bool WsfbEnterVT(int, int);
-static void WsfbLeaveVT(int, int);
-static Bool WsfbSwitchMode(int, DisplayModePtr, int);
-static int WsfbValidMode(int, DisplayModePtr, Bool, int);
+static void WsfbPointerMoved(SCRN_ARG_TYPE, int, int);
+static Bool WsfbEnterVT(VT_FUNC_ARGS_DECL);
+static void WsfbLeaveVT(VT_FUNC_ARGS_DECL);
+static Bool WsfbSwitchMode(SWITCH_MODE_ARGS_DECL);
+static int WsfbValidMode(SCRN_ARG_TYPE, DisplayModePtr, Bool, int);
 static void WsfbLoadPalette(ScrnInfoPtr, int, int *, LOCO *, VisualPtr);
 static Bool WsfbSaveScreen(ScreenPtr, int);
 static void WsfbSave(ScrnInfoPtr);
@@ -132,8 +141,15 @@ static Bool WsfbDGASetMode(ScrnInfoPtr, 
 static void WsfbDGASetViewport(ScrnInfoPtr, int, int, int);
 static Bool WsfbDGAInit(ScrnInfoPtr, ScreenPtr);
 #endif
-static Bool WsfbDriverFunc(ScrnInfoPtr pScrn, xorgDriverFuncOp op,
-				pointer ptr);
+
+#if defined(BGRA_XSRC_NETBSD)
+static void WsfbShadowUpdateSwap32(ScreenPtr, shadowBufPtr);
+#endif
+#if defined(WILDCAT_XSRC_NETBSD)
+static void WsfbShadowUpdateSplit(ScreenPtr, shadowBufPtr);
+#endif
+
+static Bool WsfbDriverFunc(ScrnInfoPtr, xorgDriverFuncOp, pointer);
 
 /* Helper functions */
 static int wsfb_open(const char *);
@@ -175,12 +191,21 @@ static SymTabRec WsfbChipsets[] = {
 /* Supported options */
 typedef enum {
 	OPTION_SHADOW_FB,
+#if defined(HWCURSOR_XSRC_NETBSD)
+	OPTION_ROTATE,
+	OPTION_HW_CURSOR,
+	OPTION_SW_CURSOR
+#else
 	OPTION_ROTATE
+#endif
 } WsfbOpts;
 
 static const OptionInfoRec WsfbOptions[] = {
 	{ OPTION_SHADOW_FB, "ShadowFB", OPTV_BOOLEAN, {0}, FALSE},
 	{ OPTION_ROTATE, "Rotate", OPTV_STRING, {0}, FALSE},
+#if defined(HWCURSOR_XSRC_NETBSD)
+	{ OPTION_HW_CURSOR, "HWCursor", OPTV_BOOLEAN, {1}, FALSE},
+#endif
 	{ -1, NULL, OPTV_NONE, {0}, FALSE}
 };
 
@@ -205,18 +230,11 @@ static pointer
 WsfbSetup(pointer module, pointer opts, int *errmaj, int *errmin)
 {
 	static Bool setupDone = FALSE;
-	const char *osname;
 
-	/* Check that we're being loaded on a OpenBSD or NetBSD system. */
-	LoaderGetOS(&osname, NULL, NULL, NULL);
-	if (!osname || (strcmp(osname, "openbsd") != 0 &&
-	                strcmp(osname, "netbsd") != 0)) {
-		if (errmaj)
-			*errmaj = LDR_BADOS;
-		if (errmin)
-			*errmin = 0;
+#if !defined(__NetBSD__) && !defined(__OpenBSD__)
 		return NULL;
-	}
+#endif
+
 	if (!setupDone) {
 		setupDone = TRUE;
 		xf86AddDriver(&WSFB, module, HaveDriverFuncs);
@@ -228,10 +246,11 @@ WsfbSetup(pointer module, pointer opts, 
 	}
 }
 
+#if !defined(HWCURSOR_XSRC_NETBSD)
 /* Private data */
 typedef struct {
 	int			fd; /* File descriptor of open device. */
-	struct wsdisplay_fbinfo info; /* Frame buffer characteristics. */
+	struct wsdisplayio_fbinfo fbi; /* Frame buffer characteristics. */
 	int			linebytes; /* Number of bytes per row. */
 	unsigned char*		fbstart;
 	unsigned char*		fbmem;
@@ -239,9 +258,12 @@ typedef struct {
 	int			rotate;
 	Bool			shadowFB;
 	void *			shadow;
+#if defined(BGRA_XSRC_NETBSD)
+	Bool			useSwap32;
+#endif
 	CloseScreenProcPtr	CloseScreen;
 	CreateScreenResourcesProcPtr CreateScreenResources;
-	void			(*PointerMoved)(int, int, int);
+	void			(*PointerMoved)(SCRN_ARG_TYPE, int, int);
 	EntityInfoPtr		pEnt;
 	struct wsdisplay_cmap	saved_cmap;
 
@@ -254,6 +276,7 @@ typedef struct {
 } WsfbRec, *WsfbPtr;
 
 #define WSFBPTR(p) ((WsfbPtr)((p)->driverPrivate))
+#endif /* !HWCURSOR_XSRC_NETBSD */
 
 static Bool
 WsfbGetRec(ScrnInfoPtr pScrn)
@@ -330,7 +353,11 @@ wsfb_mmap(size_t len, off_t off, int fd)
 	mapaddr = (pointer) mmap(addr, mapsize,
 				 PROT_READ | PROT_WRITE, MAP_SHARED,
 				 fd, off);
+#if defined(HWCURSOR_XSRC_NETBSD)
+	if (mapaddr == MAP_FAILED) {
+#else
 	if (mapaddr == (pointer) -1) {
+#endif
 		mapaddr = NULL;
 	}
 #if DEBUG
@@ -358,6 +385,15 @@ WsfbProbe(DriverPtr drv, int flags)
 					      &devSections)) <= 0)
 		return FALSE;
 
+#if defined(MODESETTING_FB_XSRC_NETBSD)
+	/* Do not attach if the modesetting driver is active */
+	if (fbSlotClaimed == TRUE) {
+		DriverPtr fbSlotDrv = xf86GetEntityInfo(0)->driver;
+		if (strcmp(fbSlotDrv->driverName, "modesetting") == 0)
+			return FALSE;
+	}
+#endif
+
 	for (i = 0; i < numDevSections; i++) {
 		ScrnInfoPtr pScrn = NULL;
 
@@ -395,12 +431,15 @@ static Bool
 WsfbPreInit(ScrnInfoPtr pScrn, int flags)
 {
 	WsfbPtr fPtr;
-	int default_depth, wstype;
+	int default_depth, bitsperpixel, wstype;
 	const char *dev;
 	char *mod = NULL, *s;
 	const char *reqSym = NULL;
 	Gamma zeros = {0.0, 0.0, 0.0};
 	DisplayModePtr mode;
+#if defined(HWCURSOR_XSRC_NETBSD)
+	MessageType from;
+#endif
 
 	if (flags & PROBE_DETECT) return FALSE;
 
@@ -426,48 +465,111 @@ WsfbPreInit(ScrnInfoPtr pScrn, int flags
 		return FALSE;
 	}
 
-	if (ioctl(fPtr->fd, WSDISPLAYIO_GINFO, &fPtr->info) == -1) {
-		xf86DrvMsg(pScrn->scrnIndex, X_ERROR,
-			   "ioctl WSDISPLAY_GINFO: %s\n",
-			   strerror(errno));
-		return FALSE;
-	}
-	if (ioctl(fPtr->fd, WSDISPLAYIO_GTYPE, &wstype) == -1) {
-		xf86DrvMsg(pScrn->scrnIndex, X_ERROR,
-			   "ioctl WSDISPLAY_GTYPE: %s\n",
-			   strerror(errno));
-		return FALSE;
-	}
-	if (ioctl(fPtr->fd, WSDISPLAYIO_LINEBYTES, &fPtr->linebytes) == -1) {
-		xf86DrvMsg(pScrn->scrnIndex, X_ERROR,
-			   "ioctl WSDISPLAYIO_LINEBYTES: %s\n",
-			   strerror(errno));
-		return FALSE;
+	if (ioctl(fPtr->fd, WSDISPLAYIO_GET_FBINFO, &fPtr->fbi) != 0) {
+		struct wsdisplay_fbinfo info;
+		struct wsdisplayio_fbinfo *fbi = &fPtr->fbi;
+		int lb;
+
+		xf86Msg(X_WARNING, "ioctl(WSDISPLAYIO_GET_FBINFO) failed, " \
+			"falling back to old method\n");
+		if (ioctl(fPtr->fd, WSDISPLAYIO_GINFO, &info) == -1) {
+			xf86DrvMsg(pScrn->scrnIndex, X_ERROR,
+				   "ioctl WSDISPLAY_GINFO: %s\n",
+				   strerror(errno));
+			return FALSE;
+		}
+		if (ioctl(fPtr->fd, WSDISPLAYIO_GTYPE, &wstype) == -1) {
+			xf86DrvMsg(pScrn->scrnIndex, X_ERROR,
+				   "ioctl WSDISPLAY_GTYPE: %s\n",
+				   strerror(errno));
+			return FALSE;
+		}
+		if (ioctl(fPtr->fd, WSDISPLAYIO_LINEBYTES, &lb) == -1) {
+			xf86DrvMsg(pScrn->scrnIndex, X_ERROR,
+				   "ioctl WSDISPLAYIO_LINEBYTES: %s\n",
+				   strerror(errno));
+			return FALSE;
+		}
+		/* ok, fake up a new style fbinfo */
+		fbi->fbi_width = info.width;
+		fbi->fbi_height = info.height;
+		fbi->fbi_stride = lb;
+		fbi->fbi_bitsperpixel = info.depth;
+		if (info.depth > 16) {
+			fbi->fbi_pixeltype = WSFB_RGB;
+			if (wstype == WSDISPLAY_TYPE_SUN24 ||
+			    wstype == WSDISPLAY_TYPE_SUNCG12 ||
+			    wstype == WSDISPLAY_TYPE_SUNCG14 ||
+			    wstype == WSDISPLAY_TYPE_SUNTCX ||
+			    wstype == WSDISPLAY_TYPE_SUNFFB ||
+			    wstype == WSDISPLAY_TYPE_XVR1000 ||
+			    wstype == WSDISPLAY_TYPE_VC4) {
+				fbi->fbi_subtype.fbi_rgbmasks.red_offset = 0;
+				fbi->fbi_subtype.fbi_rgbmasks.red_size = 8;
+				fbi->fbi_subtype.fbi_rgbmasks.green_offset = 8;
+				fbi->fbi_subtype.fbi_rgbmasks.green_size = 8;
+				fbi->fbi_subtype.fbi_rgbmasks.blue_offset = 16;
+				fbi->fbi_subtype.fbi_rgbmasks.blue_size = 8;
+			} else {
+				fbi->fbi_subtype.fbi_rgbmasks.red_offset = 16;
+				fbi->fbi_subtype.fbi_rgbmasks.red_size = 8;
+				fbi->fbi_subtype.fbi_rgbmasks.green_offset = 8;
+				fbi->fbi_subtype.fbi_rgbmasks.green_size = 8;
+				fbi->fbi_subtype.fbi_rgbmasks.blue_offset = 0;
+				fbi->fbi_subtype.fbi_rgbmasks.blue_size = 8;
+			}
+			fbi->fbi_subtype.fbi_rgbmasks.alpha_offset = 0;
+			fbi->fbi_subtype.fbi_rgbmasks.alpha_size = 0;
+		} else if (info.depth <= 8) {
+			fbi->fbi_pixeltype = WSFB_CI;
+			fbi->fbi_subtype.fbi_cmapinfo.cmap_entries = info.cmsize;
+		}
+		fbi->fbi_flags = 0;
+#if defined(STRICT_XSRC_NETBSD)
+		fbi->fbi_fbsize = lb * info.height;
+#else
+		fbi->fbi_fbsize = info.width * lb;
+#endif
+#if defined(STRICT_XSRC_NETBSD)
+		fbi->fbi_fboffset = 0;
+#endif
+
 	}
+#if defined(STRICT_XSRC_NETBSD)
+	xf86Msg(X_INFO, "fboffset %x\n", fPtr->fbi.fbi_fboffset);
+#endif
 	/*
 	 * Allocate room for saving the colormap.
 	 */
-	if (fPtr->info.cmsize != 0) {
+#if defined(STRICT_XSRC_NETBSD)
+	if (fPtr->fbi.fbi_pixeltype == WSFB_CI &&
+	    fPtr->fbi.fbi_subtype.fbi_cmapinfo.cmap_entries > 0) {
+#else
+	if (fPtr->fbi.fbi_pixeltype == WSFB_CI) {
+#endif
 		fPtr->saved_cmap.red =
-		    (unsigned char *)malloc(fPtr->info.cmsize);
+		    (unsigned char *)malloc(fPtr->fbi.fbi_subtype.fbi_cmapinfo.cmap_entries);
 		if (fPtr->saved_cmap.red == NULL) {
 			xf86DrvMsg(pScrn->scrnIndex, X_ERROR,
-			    "Cannot malloc %d bytes\n", fPtr->info.cmsize);
+			    "Cannot malloc %d bytes\n",
+			    fPtr->fbi.fbi_subtype.fbi_cmapinfo.cmap_entries);
 			return FALSE;
 		}
 		fPtr->saved_cmap.green =
-		    (unsigned char *)malloc(fPtr->info.cmsize);
+		    (unsigned char *)malloc(fPtr->fbi.fbi_subtype.fbi_cmapinfo.cmap_entries);
 		if (fPtr->saved_cmap.green == NULL) {
 			xf86DrvMsg(pScrn->scrnIndex, X_ERROR,
-			    "Cannot malloc %d bytes\n", fPtr->info.cmsize);
+			    "Cannot malloc %d bytes\n",
+			    fPtr->fbi.fbi_subtype.fbi_cmapinfo.cmap_entries);
 			free(fPtr->saved_cmap.red);
 			return FALSE;
 		}
 		fPtr->saved_cmap.blue =
-		    (unsigned char *)malloc(fPtr->info.cmsize);
+		    (unsigned char *)malloc(fPtr->fbi.fbi_subtype.fbi_cmapinfo.cmap_entries);
 		if (fPtr->saved_cmap.blue == NULL) {
 			xf86DrvMsg(pScrn->scrnIndex, X_ERROR,
-			    "Cannot malloc %d bytes\n", fPtr->info.cmsize);
+			    "Cannot malloc %d bytes\n",
+			    fPtr->fbi.fbi_subtype.fbi_cmapinfo.cmap_entries);
 			free(fPtr->saved_cmap.red);
 			free(fPtr->saved_cmap.green);
 			return FALSE;
@@ -475,18 +577,37 @@ WsfbPreInit(ScrnInfoPtr pScrn, int flags
 	}
 
 	/* Handle depth */
-	default_depth = fPtr->info.depth <= 24 ? fPtr->info.depth : 24;
+	default_depth = fPtr->fbi.fbi_bitsperpixel <= 24 ? fPtr->fbi.fbi_bitsperpixel : 24;
+	bitsperpixel = fPtr->fbi.fbi_bitsperpixel;
+#if defined(LUNA68K_XSRC_NETBSD)
+#if defined(__NetBSD__) && defined(WSDISPLAY_TYPE_LUNA)
+	if (wstype == WSDISPLAY_TYPE_LUNA) {
+		/*
+		 * XXX
+		 * LUNA's color framebuffers support 4bpp or 8bpp
+		 * but they have multiple 1bpp VRAM planes like ancient VGA.
+		 * For now, Xorg server supports only the first one plane
+		 * as 1bpp monochrome server.
+		 *
+		 * Note OpenBSD/luna88k workarounds this by switching depth
+		 * and palette settings by WSDISPLAYIO_SETGFXMODE ioctl.
+		 */
+		default_depth = 1;
+		bitsperpixel = 1;
+	}
+#endif
+#endif /* LUNA68K_XSRC_NETBSD */
 	if (!xf86SetDepthBpp(pScrn, default_depth, default_depth,
-		fPtr->info.depth,
-		fPtr->info.depth >= 24 ? Support24bppFb|Support32bppFb : 0))
+		bitsperpixel,
+		bitsperpixel >= 24 ? Support24bppFb|Support32bppFb : 0))
 		return FALSE;
 
 	/* Check consistency. */
-	if (pScrn->bitsPerPixel != fPtr->info.depth) {
+	if (pScrn->bitsPerPixel != bitsperpixel) {
 		xf86DrvMsg(pScrn->scrnIndex, X_ERROR,
 		    "specified depth (%d) or bpp (%d) doesn't match "
 		    "framebuffer depth (%d)\n", pScrn->depth,
-		    pScrn->bitsPerPixel, fPtr->info.depth);
+		    pScrn->bitsPerPixel, bitsperpixel);
 		return FALSE;
 	}
 	xf86PrintDepthBpp(pScrn);
@@ -495,51 +616,6 @@ WsfbPreInit(ScrnInfoPtr pScrn, int flags
 	if (pScrn->depth == 24 && pix24bpp == 0)
 		pix24bpp = xf86GetBppFromDepth(pScrn, 24);
 
-	/* Color weight */
-	if (pScrn->depth > 8) {
-		rgb zeros = { 0, 0, 0 }, masks;
-
-		if (wstype == WSDISPLAY_TYPE_SUN24 ||
-		    wstype == WSDISPLAY_TYPE_SUNCG12 ||
-		    wstype == WSDISPLAY_TYPE_SUNCG14 ||
-		    wstype == WSDISPLAY_TYPE_SUNTCX ||
-		    wstype == WSDISPLAY_TYPE_SUNFFB) {
-			masks.red = 0x0000ff;
-			masks.green = 0x00ff00;
-			masks.blue = 0xff0000;
-		} else {
-			masks.red = 0;
-			masks.green = 0;
-			masks.blue = 0;
-		}
-
-		if (!xf86SetWeight(pScrn, zeros, masks))
-			return FALSE;
-	}
-
-	/* Visual init */
-	if (!xf86SetDefaultVisual(pScrn, -1))
-		return FALSE;
-
-	/* We don't currently support DirectColor at > 8bpp . */
-	if (pScrn->depth > 8 && pScrn->defaultVisual != TrueColor) {
-		xf86DrvMsg(pScrn->scrnIndex, X_ERROR, "Given default visual"
-			   " (%s) is not supported at depth %d\n",
-			   xf86GetVisualName(pScrn->defaultVisual),
-			   pScrn->depth);
-		return FALSE;
-	}
-
-	xf86SetGamma(pScrn,zeros);
-
-	pScrn->progClock = TRUE;
-	pScrn->rgbBits   = 8;
-	pScrn->chipset   = "wsfb";
-	pScrn->videoRam  = fPtr->linebytes * fPtr->info.height;
-
-	xf86DrvMsg(pScrn->scrnIndex, X_INFO, "Vidmem: %dk\n",
-		   pScrn->videoRam/1024);
-
 	/* Handle options. */
 	xf86CollectOptions(pScrn, NULL);
 	fPtr->Options = (OptionInfoRec *)malloc(sizeof(WsfbOptions));
@@ -550,16 +626,27 @@ WsfbPreInit(ScrnInfoPtr pScrn, int flags
 			   fPtr->Options);
 
 	/* Use shadow framebuffer by default, on depth >= 8 */
-	if (pScrn->depth >= 8)
+	xf86Msg(X_INFO, "fbi_flags: %x\n", fPtr->fbi.fbi_flags);
+	if ((pScrn->depth >= 8) &&
+	   ((fPtr->fbi.fbi_flags & WSFB_VRAM_IS_RAM) == 0)) {
 		fPtr->shadowFB = xf86ReturnOptValBool(fPtr->Options,
 						      OPTION_SHADOW_FB, TRUE);
-	else
+	} else
 		if (xf86ReturnOptValBool(fPtr->Options,
 					 OPTION_SHADOW_FB, FALSE)) {
 			xf86DrvMsg(pScrn->scrnIndex, X_WARNING,
 				   "Shadow FB option ignored on depth < 8");
 		}
 
+#if defined(WILDCAT_XSRC_NETBSD)
+	if (fPtr->fbi.fbi_flags & WSFB_VRAM_IS_SPLIT) {
+		if (!fPtr->shadowFB) {
+			xf86DrvMsg(pScrn->scrnIndex, X_WARNING,
+				   "Shadow FB forced on for split framebuffer");
+			fPtr->shadowFB = TRUE;
+		}
+	}
+#endif
 	/* Rotation */
 	fPtr->rotate = WSFB_ROTATE_NONE;
 	if ((s = xf86GetOptValString(fPtr->Options, OPTION_ROTATE))) {
@@ -593,6 +680,101 @@ WsfbPreInit(ScrnInfoPtr pScrn, int flags
 		}
 	}
 
+#if defined(BGRA_XSRC_NETBSD)
+	fPtr->useSwap32 = FALSE;
+#endif
+	/* Color weight */
+	if (fPtr->fbi.fbi_pixeltype == WSFB_RGB) {
+		rgb zeros = { 0, 0, 0 }, masks;
+
+		if (fPtr->fbi.fbi_subtype.fbi_rgbmasks.red_size > 0) {
+			uint32_t msk;
+
+#if defined(BGRA_XSRC_NETBSD)
+			/*
+			 * see if we need to byte-swap pixels
+			 * XXX this requires a shadow FB and is incompatible
+			 * (for now ) with rotation
+			 */
+			if ((fPtr->fbi.fbi_bitsperpixel == 32) &&
+			    (fPtr->fbi.fbi_subtype.fbi_rgbmasks.blue_offset == 24) &&
+			    (fPtr->rotate == WSFB_ROTATE_NONE) &&
+			    (fPtr->shadowFB == TRUE)) {
+			    	/*
+			    	 * looks like BGRA - set the swap flag and flip
+			    	 * the offsets
+			    	 */
+			    	xf86Msg(X_INFO, "endian-flipped RGB framebuffer "
+			    			"detected, using WsfbShadowUpdateSwap32()\n");
+			    	fPtr->fbi.fbi_subtype.fbi_rgbmasks.blue_offset = 0;
+			    	fPtr->fbi.fbi_subtype.fbi_rgbmasks.green_offset = 8;
+			    	fPtr->fbi.fbi_subtype.fbi_rgbmasks.red_offset = 16;
+			    	fPtr->fbi.fbi_subtype.fbi_rgbmasks.alpha_offset = 24;
+				fPtr->useSwap32 = TRUE;
+			}
+#endif
+
+			msk = 0xffffffff;
+			msk = msk << fPtr->fbi.fbi_subtype.fbi_rgbmasks.red_size;
+			msk = ~msk;
+			masks.red = msk << fPtr->fbi.fbi_subtype.fbi_rgbmasks.red_offset; 
+
+			msk = 0xffffffff;
+			msk = msk << fPtr->fbi.fbi_subtype.fbi_rgbmasks.green_size;
+			msk = ~msk;
+			masks.green = msk << fPtr->fbi.fbi_subtype.fbi_rgbmasks.green_offset; 
+
+			msk = 0xffffffff;
+			msk = msk << fPtr->fbi.fbi_subtype.fbi_rgbmasks.blue_size;
+			msk = ~msk;
+			masks.blue = msk << fPtr->fbi.fbi_subtype.fbi_rgbmasks.blue_offset; 
+#if defined(STRICT_XSRC_NETBSD)
+			xf86Msg(X_INFO, "masks generated: %08lx %08lx %08lx\n",
+			    (unsigned long)masks.red,
+			    (unsigned long)masks.green,
+			    (unsigned long)masks.blue);
+#else
+			xf86Msg(X_INFO, "masks generated: %08x %08x %08x\n",
+			    masks.red, masks.green, masks.blue);
+#endif
+		} else {
+			masks.red = 0;
+			masks.green = 0;
+			masks.blue = 0;
+		}
+
+		if (!xf86SetWeight(pScrn, zeros, masks))
+			return FALSE;
+	}
+
+	/* Visual init */
+	if (!xf86SetDefaultVisual(pScrn, -1))
+		return FALSE;
+
+	/* We don't currently support DirectColor at > 8bpp . */
+	if (pScrn->depth > 8 && pScrn->defaultVisual != TrueColor) {
+		xf86DrvMsg(pScrn->scrnIndex, X_ERROR, "Given default visual"
+			   " (%s) is not supported at depth %d\n",
+			   xf86GetVisualName(pScrn->defaultVisual),
+			   pScrn->depth);
+		return FALSE;
+	}
+
+	xf86SetGamma(pScrn,zeros);
+
+	pScrn->progClock = TRUE;
+#if defined(LUNA68K_XSRC_NETBSD)
+	pScrn->rgbBits   = (pScrn->depth >= 8) ? 8 : pScrn->depth;
+#else
+	pScrn->rgbBits   = 8;
+#endif
+	pScrn->chipset   = "wsfb";
+	pScrn->videoRam  = fPtr->fbi.fbi_fbsize;
+
+	xf86DrvMsg(pScrn->scrnIndex, X_INFO, "Vidmem: %dk\n",
+		   pScrn->videoRam/1024);
+
+
 	/* Fake video mode struct. */
 	mode = (DisplayModePtr)malloc(sizeof(DisplayModeRec));
 	mode->prev = mode;
@@ -601,12 +783,12 @@ WsfbPreInit(ScrnInfoPtr pScrn, int flags
 	mode->status = MODE_OK;
 	mode->type = M_T_BUILTIN;
 	mode->Clock = 0;
-	mode->HDisplay = fPtr->info.width;
+	mode->HDisplay = fPtr->fbi.fbi_width;
 	mode->HSyncStart = 0;
 	mode->HSyncEnd = 0;
 	mode->HTotal = 0;
 	mode->HSkew = 0;
-	mode->VDisplay = fPtr->info.height;
+	mode->VDisplay = fPtr->fbi.fbi_height;
 	mode->VSyncStart = 0;
 	mode->VSyncEnd = 0;
 	mode->VTotal = 0;
@@ -617,27 +799,30 @@ WsfbPreInit(ScrnInfoPtr pScrn, int flags
 		   "Ignoring mode specification from screen section\n");
 	}
 	pScrn->currentMode = pScrn->modes = mode;
-	pScrn->virtualX = fPtr->info.width;
-	pScrn->virtualY = fPtr->info.height;
+	pScrn->virtualX = fPtr->fbi.fbi_width;
+	pScrn->virtualY = fPtr->fbi.fbi_height;
 	pScrn->displayWidth = pScrn->virtualX;
 
 	/* Set the display resolution. */
 	xf86SetDpi(pScrn, 0, 0);
 
+#if defined(HWCURSOR_XSRC_NETBSD)
+	from = X_DEFAULT;
+	fPtr->HWCursor = TRUE;
+	if (xf86GetOptValBool(fPtr->Options, OPTION_HW_CURSOR, &fPtr->HWCursor))
+		from = X_CONFIG;
+	if (xf86ReturnOptValBool(fPtr->Options, OPTION_SW_CURSOR, FALSE)) {
+		from = X_CONFIG;
+		fPtr->HWCursor = FALSE;
+	}
+	xf86DrvMsg(pScrn->scrnIndex, from, "Using %s cursor\n",
+		fPtr->HWCursor ? "HW" : "SW");
+#endif
+
 	/* Load bpp-specific modules. */
 	switch(pScrn->bitsPerPixel) {
-#ifdef HAVE_XF1BPP
 	case 1:
-		mod = "xf1bpp";
-		reqSym = "xf1bppScreenInit";
-		break;
-#endif
-#ifdef HAVE_XF4BPP
 	case 4:
-		mod = "xf4bpp";
-		reqSym = "xf4bppScreenInit";
-		break;
-#endif
 	default:
 		mod = "fb";
 		break;
@@ -657,17 +842,40 @@ WsfbPreInit(ScrnInfoPtr pScrn, int flags
 		WsfbFreeRec(pScrn);
 		return FALSE;
 	}
+
+#if defined(RAMDAC_XSRC_NETBSD)
+	if (xf86LoadSubModule(pScrn, "ramdac") == NULL) {
+		WsfbFreeRec(pScrn);
+		return FALSE;
+        }
+#endif
+
 	TRACE_EXIT("PreInit");
 	return TRUE;
 }
 
+static void
+wsfbUpdateRotatePacked(ScreenPtr pScreen, shadowBufPtr pBuf)
+{
+	shadowUpdateRotatePacked(pScreen, pBuf);
+}
+
+static void
+wsfbUpdatePacked(ScreenPtr pScreen, shadowBufPtr pBuf)
+{
+	shadowUpdatePacked(pScreen, pBuf);
+}
+
 static Bool
 WsfbCreateScreenResources(ScreenPtr pScreen)
 {
-	ScrnInfoPtr pScrn = xf86Screens[pScreen->myNum];
+	ScrnInfoPtr pScrn = xf86ScreenToScrn(pScreen);
 	WsfbPtr fPtr = WSFBPTR(pScrn);
 	PixmapPtr pPixmap;
 	Bool ret;
+#if defined(WILDCAT_XSRC_NETBSD)
+	void (*shadowproc)(ScreenPtr, shadowBufPtr);
+#endif
 
 	pScreen->CreateScreenResources = fPtr->CreateScreenResources;
 	ret = pScreen->CreateScreenResources(pScreen);
@@ -678,11 +886,27 @@ WsfbCreateScreenResources(ScreenPtr pScr
 
 	pPixmap = pScreen->GetScreenPixmap(pScreen);
 
+#if defined(WILDCAT_XSRC_NETBSD)
+	if (fPtr->fbi.fbi_flags & WSFB_VRAM_IS_SPLIT) {
+		shadowproc = WsfbShadowUpdateSplit;
+	} else if (fPtr->useSwap32) {
+		shadowproc = WsfbShadowUpdateSwap32;
+	} else if (fPtr->rotate) {
+		shadowproc = shadowUpdateRotatePacked;
+	} else
+		shadowproc = shadowUpdatePacked;
+	
+	if (!shadowAdd(pScreen, pPixmap, shadowproc,
+		WsfbWindowLinear, fPtr->rotate, NULL)) {
+		return FALSE;
+	}
+#else
 	if (!shadowAdd(pScreen, pPixmap, fPtr->rotate ?
-		shadowUpdateRotatePackedWeak() : shadowUpdatePackedWeak(),
+		wsfbUpdateRotatePacked : wsfbUpdatePacked,
 		WsfbWindowLinear, fPtr->rotate, NULL)) {
 		return FALSE;
 	}
+#endif
 	return TRUE;
 }
 
@@ -702,13 +926,16 @@ WsfbShadowInit(ScreenPtr pScreen)
 }
 
 static Bool
-WsfbScreenInit(int scrnIndex, ScreenPtr pScreen, int argc, char **argv)
+WsfbScreenInit(SCREEN_INIT_ARGS_DECL)
 {
 	ScrnInfoPtr pScrn = xf86Screens[pScreen->myNum];
 	WsfbPtr fPtr = WSFBPTR(pScrn);
 	VisualPtr visual;
 	int ret, flags, ncolors;
 	int wsmode = WSDISPLAYIO_MODE_DUMBFB;
+#if defined(LUNA68K_XSRC_NETBSD)
+	int wstype;
+#endif
 	size_t len;
 
 	TRACE_ENTER("WsfbScreenInit");
@@ -721,36 +948,39 @@ WsfbScreenInit(int scrnIndex, ScreenPtr 
 	       pScrn->mask.red,pScrn->mask.green,pScrn->mask.blue,
 	       pScrn->offset.red,pScrn->offset.green,pScrn->offset.blue);
 #endif
-	switch (fPtr->info.depth) {
+	switch (fPtr->fbi.fbi_bitsperpixel) {
 	case 1:
 	case 4:
 	case 8:
-		len = fPtr->linebytes*fPtr->info.height;
+		len = fPtr->fbi.fbi_stride * fPtr->fbi.fbi_height;
 		break;
 	case 16:
-		if (fPtr->linebytes == fPtr->info.width) {
-			len = fPtr->info.width*fPtr->info.height*sizeof(short);
+		if (fPtr->fbi.fbi_stride == fPtr->fbi.fbi_width) {
+			xf86Msg(X_ERROR, "Bogus stride == width in 16bit colour\n");
+			len = fPtr->fbi.fbi_width * fPtr->fbi.fbi_height * sizeof(short);
 		} else {
-			len = fPtr->linebytes*fPtr->info.height;
+			len = fPtr->fbi.fbi_stride * fPtr->fbi.fbi_height;
 		}
 		break;
 	case 24:
-		if (fPtr->linebytes == fPtr->info.width) {
-			len = fPtr->info.width*fPtr->info.height*3;
+		if (fPtr->fbi.fbi_stride == fPtr->fbi.fbi_width) {
+			xf86Msg(X_ERROR, "Bogus stride == width in 24bit colour\n");
+			len = fPtr->fbi.fbi_width * fPtr->fbi.fbi_height * 3;
 		} else {
-			len = fPtr->linebytes*fPtr->info.height;
+			len = fPtr->fbi.fbi_stride * fPtr->fbi.fbi_height;
 		}
 		break;
 	case 32:
-		if (fPtr->linebytes == fPtr->info.width) {
-			len = fPtr->info.width*fPtr->info.height*sizeof(int);
+		if (fPtr->fbi.fbi_stride == fPtr->fbi.fbi_width) {
+			xf86Msg(X_ERROR, "Bogus stride == width in 32bit colour\n");
+			len = fPtr->fbi.fbi_width * fPtr->fbi.fbi_height * sizeof(int);
 		} else {
-			len = fPtr->linebytes*fPtr->info.height;
+			len = fPtr->fbi.fbi_stride * fPtr->fbi.fbi_height;
 		}
 		break;
 	default:
 		xf86DrvMsg(pScrn->scrnIndex, X_ERROR,
-			   "unsupported depth %d\n", fPtr->info.depth);
+			   "unsupported depth %d\n", fPtr->fbi.fbi_bitsperpixel);
 		return FALSE;
 	}
 	/* Switch to graphics mode - required before mmap. */
@@ -760,6 +990,18 @@ WsfbScreenInit(int scrnIndex, ScreenPtr 
 			   strerror(errno));
 		return FALSE;
 	}
+#if defined(LUNA68K_XSRC_NETBSD)
+	/* Get wsdisplay type to handle quirks */
+	if (ioctl(fPtr->fd, WSDISPLAYIO_GTYPE, &wstype) == -1) {
+		xf86DrvMsg(pScrn->scrnIndex, X_ERROR,
+			   "ioctl WSDISPLAY_GTYPE: %s\n",
+			   strerror(errno));
+		return FALSE;
+	}
+#endif
+#if defined(WILDCAT_XSRC_NETBSD)
+	len = max(len, fPtr->fbi.fbi_fbsize);
+#endif
 	fPtr->fbmem = wsfb_mmap(len, 0, fPtr->fd);
 
 	if (fPtr->fbmem == NULL) {
@@ -798,11 +1040,32 @@ WsfbScreenInit(int scrnIndex, ScreenPtr 
 		pScrn->PointerMoved = WsfbPointerMoved;
 	}
 
+#if defined(STRICT_XSRC_NETBSD)
+	fPtr->fbstart = fPtr->fbmem + fPtr->fbi.fbi_fboffset;
+#else
 	fPtr->fbstart = fPtr->fbmem;
+#endif
+#if defined(LUNA68K_XSRC_NETBSD)
+#ifdef	WSDISPLAY_TYPE_LUNA
+	if (wstype == WSDISPLAY_TYPE_LUNA) {
+		/*
+		 * XXX
+		 * LUNA's FB seems to have 64 dot (8 byte) offset.
+		 * This might be able to be changed in kernel lunafb driver,
+		 * but current setting was pulled from 4.4BSD-Lite2/luna68k.
+		 */
+		fPtr->fbstart += 8;
+	}
+#endif
+#endif /* LUNA68K_XSRC_NETBSD */
 
 	if (fPtr->shadowFB) {
+#if defined(WILDCAT_XSRC_NETBSD)
+		fPtr->shadow = calloc(1, fPtr->fbi.fbi_stride * pScrn->virtualY);
+#else
 		fPtr->shadow = calloc(1, pScrn->virtualX * pScrn->virtualY *
 		    pScrn->bitsPerPixel/8);
+#endif
 
 		if (!fPtr->shadow) {
 			xf86DrvMsg(pScrn->scrnIndex, X_ERROR,
@@ -813,21 +1076,15 @@ WsfbScreenInit(int scrnIndex, ScreenPtr 
 
 	switch (pScrn->bitsPerPixel) {
 	case 1:
-#ifdef HAVE_XF1BPP
-		ret = xf1bppScreenInit(pScreen, fPtr->fbstart,
-				       pScrn->virtualX, pScrn->virtualY,
-				       pScrn->xDpi, pScrn->yDpi,
-				       fPtr->linebytes * 8);
+#if defined(LUNA68K_XSRC_NETBSD)
+		ret = fbScreenInit(pScreen,
+		    fPtr->fbstart,
+		    pScrn->virtualX, pScrn->virtualY,
+		    pScrn->xDpi, pScrn->yDpi,
+		    fPtr->fbi.fbi_stride * 8, pScrn->bitsPerPixel);
 		break;
-#endif
+#endif /* LUNA68K_XSRC_NETBSD */
 	case 4:
-#ifdef HAVE_XF4BPP
-		ret = xf4bppScreenInit(pScreen, fPtr->fbstart,
-				       pScrn->virtualX, pScrn->virtualY,
-				       pScrn->xDpi, pScrn->yDpi,
-				       fPtr->linebytes * 2);
-		break;
-#endif
 	case 8:
 	case 16:
 	case 24:
@@ -836,7 +1093,13 @@ WsfbScreenInit(int scrnIndex, ScreenPtr 
 		    fPtr->shadowFB ? fPtr->shadow : fPtr->fbstart,
 		    pScrn->virtualX, pScrn->virtualY,
 		    pScrn->xDpi, pScrn->yDpi,
+#if defined(WILDCAT_XSRC_NETBSD)
+		    /* apparently fb wants stride in pixels, not bytes */
+		    fPtr->fbi.fbi_stride / (pScrn->bitsPerPixel >> 3),
+		    pScrn->bitsPerPixel);
+#else
 		    pScrn->displayWidth, pScrn->bitsPerPixel);
+#endif
 		break;
 	default:
 		xf86DrvMsg(pScrn->scrnIndex, X_ERROR,
@@ -868,7 +1131,7 @@ WsfbScreenInit(int scrnIndex, ScreenPtr 
 				   "RENDER extension initialisation failed.");
 	}
 	if (fPtr->shadowFB && !WsfbShadowInit(pScreen)) {
-		xf86DrvMsg(scrnIndex, X_ERROR,
+		xf86DrvMsg(pScrn->scrnIndex, X_ERROR,
 		    "shadow framebuffer initialization failed\n");
 		return FALSE;
 	}
@@ -877,25 +1140,32 @@ WsfbScreenInit(int scrnIndex, ScreenPtr 
 	if (!fPtr->rotate)
 		WsfbDGAInit(pScrn, pScreen);
 	else
-		xf86DrvMsg(scrnIndex, X_INFO, "Rotated display, "
+		xf86DrvMsg(pScrn->scrnIndex, X_INFO, "Rotated display, "
 		    "disabling DGA\n");
 #endif
 	if (fPtr->rotate) {
-		xf86DrvMsg(scrnIndex, X_INFO, "Enabling Driver Rotation, "
+		xf86DrvMsg(pScrn->scrnIndex, X_INFO, "Enabling Driver Rotation, "
 		    "disabling RandR\n");
+#if 0
 		xf86DisableRandR();
+#endif
 		if (pScrn->bitsPerPixel == 24)
-			xf86DrvMsg(scrnIndex, X_WARNING,
+			xf86DrvMsg(pScrn->scrnIndex, X_WARNING,
 			    "Rotation might be broken in 24 bpp\n");
 	}
 
 	xf86SetBlackWhitePixels(pScreen);
-	miInitializeBackingStore(pScreen);
 	xf86SetBackingStore(pScreen);
 
 	/* Software cursor. */
 	miDCInitialize(pScreen, xf86GetPointerScreenFuncs());
 
+#if defined(HWCURSOR_XSRC_NETBSD)
+	/* check for hardware cursor support */
+	if (fPtr->HWCursor)
+		WsfbSetupCursor(pScreen);
+#endif
+
 	/*
 	 * Colormap
 	 *
@@ -907,14 +1177,51 @@ WsfbScreenInit(int scrnIndex, ScreenPtr 
 	if (!miCreateDefColormap(pScreen))
 		return FALSE;
 	flags = CMAP_RELOAD_ON_MODE_SWITCH;
-	ncolors = fPtr->info.cmsize;
+
+	ncolors = 0;
+	if (fPtr->fbi.fbi_pixeltype == WSFB_CI) {
+		ncolors = fPtr->fbi.fbi_subtype.fbi_cmapinfo.cmap_entries;
+	}
+
 	/* On StaticGray visuals, fake a 256 entries colormap. */
 	if (ncolors == 0)
 		ncolors = 256;
+
 	if(!xf86HandleColormaps(pScreen, ncolors, 8, WsfbLoadPalette,
 				NULL, flags))
 		return FALSE;
 
+#if defined(LUNA68K_XSRC_NETBSD)
+#if defined(__NetBSD__) && defined(WSDISPLAY_TYPE_LUNA)
+	if (wstype == WSDISPLAY_TYPE_LUNA) {
+		ncolors = fPtr->fbi.fbi_subtype.fbi_cmapinfo.cmap_entries;
+		if (ncolors > 0) {
+			/*
+			 * Override palette to use 4bpp/8bpp framebuffers as
+			 * monochrome server by using only the first plane.
+			 * See also comment in WsfbPreInit().
+			 */
+			struct wsdisplay_cmap cmap;
+			uint8_t r[256], g[256], b[256];
+			int p;
+
+			for (p = 0; p < ncolors; p++)
+				r[p] = g[p] = b[p] = (p & 1) ? 0xff : 0;
+			cmap.index = 0;
+			cmap.count = ncolors;
+			cmap.red   = r;
+			cmap.green = g;
+			cmap.blue  = b;
+			if (ioctl(fPtr->fd, WSDISPLAYIO_PUTCMAP, &cmap) == -1) {
+				xf86DrvMsg(pScrn->scrnIndex, X_ERROR,
+				   "ioctl WSDISPLAYIO_PUTCMAP: %s\n",
+				   strerror(errno));
+			}
+		}
+	}
+#endif
+#endif /* LUNA68K_XSRC_NETBSD */
+
 	pScreen->SaveScreen = WsfbSaveScreen;
 
 #ifdef XvExtension
@@ -937,9 +1244,9 @@ WsfbScreenInit(int scrnIndex, ScreenPtr 
 }
 
 static Bool
-WsfbCloseScreen(int scrnIndex, ScreenPtr pScreen)
+WsfbCloseScreen(CLOSE_SCREEN_ARGS_DECL)
 {
-	ScrnInfoPtr pScrn = xf86Screens[scrnIndex];
+	ScrnInfoPtr pScrn = xf86ScreenToScrn(pScreen);
 	PixmapPtr pPixmap;
 	WsfbPtr fPtr = WSFBPTR(pScrn);
 
@@ -971,30 +1278,34 @@ WsfbCloseScreen(int scrnIndex, ScreenPtr
 	/* Unwrap CloseScreen. */
 	pScreen->CloseScreen = fPtr->CloseScreen;
 	TRACE_EXIT("WsfbCloseScreen");
-	return (*pScreen->CloseScreen)(scrnIndex, pScreen);
+	return (*pScreen->CloseScreen)(CLOSE_SCREEN_ARGS);
 }
 
 static void *
 WsfbWindowLinear(ScreenPtr pScreen, CARD32 row, CARD32 offset, int mode,
 		CARD32 *size, void *closure)
 {
-	ScrnInfoPtr pScrn = xf86Screens[pScreen->myNum];
+	ScrnInfoPtr pScrn = xf86ScreenToScrn(pScreen);
 	WsfbPtr fPtr = WSFBPTR(pScrn);
 
-	if (fPtr->linebytes)
-		*size = fPtr->linebytes;
+	/*
+	 * XXX
+	 * This should never happen. Is it really necessary?
+	 */
+	if (fPtr->fbi.fbi_stride)
+		*size = fPtr->fbi.fbi_stride;
 	else {
 		if (ioctl(fPtr->fd, WSDISPLAYIO_LINEBYTES, size) == -1)
 			return NULL;
-		fPtr->linebytes = *size;
+		fPtr->fbi.fbi_stride = *size;
 	}
-	return ((CARD8 *)fPtr->fbmem + row *fPtr->linebytes + offset);
+	return ((CARD8 *)fPtr->fbmem + row * fPtr->fbi.fbi_stride + offset);
 }
 
 static void
-WsfbPointerMoved(int index, int x, int y)
+WsfbPointerMoved(SCRN_ARG_TYPE arg, int x, int y)
 {
-    ScrnInfoPtr pScrn = xf86Screens[index];
+    SCRN_INFO_PTR(arg);
     WsfbPtr fPtr = WSFBPTR(pScrn);
     int newX, newY;
 
@@ -1026,35 +1337,84 @@ WsfbPointerMoved(int index, int x, int y
     }
 
     /* Pass adjusted pointer coordinates to wrapped PointerMoved function. */
-    (*fPtr->PointerMoved)(index, newX, newY);
+    (*fPtr->PointerMoved)(arg, newX, newY);
 }
 
 static Bool
-WsfbEnterVT(int scrnIndex, int flags)
+WsfbEnterVT(VT_FUNC_ARGS_DECL)
 {
-	ScrnInfoPtr pScrn = xf86Screens[scrnIndex];
+	SCRN_INFO_PTR(arg);
+#if defined(STRICT_XSRC_NETBSD)
+	WsfbPtr fPtr = WSFBPTR(pScrn);
+	int mode;
+#endif
 
 	TRACE_ENTER("EnterVT");
 	pScrn->vtSema = TRUE;
+
+#if defined(STRICT_XSRC_NETBSD)
+	/* Restore the graphics mode. */
+	mode = WSDISPLAYIO_MODE_DUMBFB;
+	if (ioctl(fPtr->fd, WSDISPLAYIO_SMODE, &mode) == -1) {
+		xf86DrvMsg(pScrn->scrnIndex, X_ERROR,
+			   "error setting graphics mode %s\n", strerror(errno));
+	}
+#endif
+
 	TRACE_EXIT("EnterVT");
 	return TRUE;
 }
 
 static void
-WsfbLeaveVT(int scrnIndex, int flags)
+WsfbLeaveVT(VT_FUNC_ARGS_DECL)
 {
-#if DEBUG
-	ScrnInfoPtr pScrn = xf86Screens[scrnIndex];
+#if defined(STRICT_XSRC_NETBSD)
+	SCRN_INFO_PTR(arg);
+#endif
+#if defined(STRICT_XSRC_NETBSD)
+	WsfbPtr fPtr = WSFBPTR(pScrn);
+	int mode;
 #endif
 
 	TRACE_ENTER("LeaveVT");
+
+#if defined(STRICT_XSRC_NETBSD)
+	/*
+	 * stuff to do:
+	 * - turn off hw cursor
+	 * - restore colour map if WSFB_CI
+	 * - ioctl(WSDISPLAYIO_MODE_EMUL) to notify the kernel driver that
+	 *   we're backing off
+	 */
+
+	if (fPtr->fbi.fbi_pixeltype == WSFB_CI &&
+	    fPtr->fbi.fbi_subtype.fbi_cmapinfo.cmap_entries > 0) {
+		/* reset colormap for text mode */
+		if (ioctl(fPtr->fd, WSDISPLAYIO_PUTCMAP,
+			  &(fPtr->saved_cmap)) == -1) {
+			xf86DrvMsg(pScrn->scrnIndex, X_ERROR,
+				   "error restoring colormap %s\n",
+				   strerror(errno));
+		}
+	}
+
+	/* Restore the text mode. */
+	mode = WSDISPLAYIO_MODE_EMUL;
+	if (ioctl(fPtr->fd, WSDISPLAYIO_SMODE, &mode) == -1) {
+		xf86DrvMsg(pScrn->scrnIndex, X_ERROR,
+			   "error setting text mode %s\n", strerror(errno));
+	}
+
+	pScrn->vtSema = FALSE;
+	TRACE_EXIT("LeaveVT");
+#endif
 }
 
 static Bool
-WsfbSwitchMode(int scrnIndex, DisplayModePtr mode, int flags)
+WsfbSwitchMode(SWITCH_MODE_ARGS_DECL)
 {
 #if DEBUG
-	ScrnInfoPtr pScrn = xf86Screens[scrnIndex];
+	SCRN_INFO_PTR(arg);
 #endif
 
 	TRACE_ENTER("SwitchMode");
@@ -1063,10 +1423,10 @@ WsfbSwitchMode(int scrnIndex, DisplayMod
 }
 
 static int
-WsfbValidMode(int scrnIndex, DisplayModePtr mode, Bool verbose, int flags)
+WsfbValidMode(SCRN_ARG_TYPE arg, DisplayModePtr mode, Bool verbose, int flags)
 {
 #if DEBUG
-	ScrnInfoPtr pScrn = xf86Screens[scrnIndex];
+	SCRN_INFO_PTR(arg);
 #endif
 
 	TRACE_ENTER("ValidMode");
@@ -1084,6 +1444,12 @@ WsfbLoadPalette(ScrnInfoPtr pScrn, int n
 
 	TRACE_ENTER("LoadPalette");
 
+#if defined(STRICT_XSRC_NETBSD)
+	/* nothing to do if there is no color palette support */
+	if (fPtr->fbi.fbi_subtype.fbi_cmapinfo.cmap_entries == 0)
+		return;
+#endif
+
 	cmap.count   = 1;
 	cmap.red   = red;
 	cmap.green = green;
@@ -1132,7 +1498,7 @@ WsfbLoadPalette(ScrnInfoPtr pScrn, int n
 static Bool
 WsfbSaveScreen(ScreenPtr pScreen, int mode)
 {
-	ScrnInfoPtr pScrn = xf86Screens[pScreen->myNum];
+	ScrnInfoPtr pScrn = xf86ScreenToScrn(pScreen);
 	WsfbPtr fPtr = WSFBPTR(pScrn);
 	int state;
 
@@ -1159,11 +1525,18 @@ WsfbSave(ScrnInfoPtr pScrn)
 
 	TRACE_ENTER("WsfbSave");
 
-	if (fPtr->info.cmsize == 0)
+	/* nothing to save if we don't run in colour-indexed mode */
+	if (fPtr->fbi.fbi_pixeltype != WSFB_CI)
+		return;
+
+#if defined(STRICT_XSRC_NETBSD)
+	/* nothing to do if no color palette support */
+	if (fPtr->fbi.fbi_subtype.fbi_cmapinfo.cmap_entries == 0)
 		return;
+#endif
 
 	fPtr->saved_cmap.index = 0;
-	fPtr->saved_cmap.count = fPtr->info.cmsize;
+	fPtr->saved_cmap.count = fPtr->fbi.fbi_subtype.fbi_cmapinfo.cmap_entries;
 	if (ioctl(fPtr->fd, WSDISPLAYIO_GETCMAP,
 		  &(fPtr->saved_cmap)) == -1) {
 		xf86DrvMsg(pScrn->scrnIndex, X_ERROR,
@@ -1181,7 +1554,12 @@ WsfbRestore(ScrnInfoPtr pScrn)
 
 	TRACE_ENTER("WsfbRestore");
 
-	if (fPtr->info.cmsize != 0) {
+#if defined(STRICT_XSRC_NETBSD)
+	if (fPtr->fbi.fbi_pixeltype == WSFB_CI &&
+	    fPtr->fbi.fbi_subtype.fbi_cmapinfo.cmap_entries > 0) {
+#else
+	if (fPtr->fbi.fbi_pixeltype == WSFB_CI) {
+#endif
 		/* reset colormap for text mode */
 		if (ioctl(fPtr->fd, WSDISPLAYIO_PUTCMAP,
 			  &(fPtr->saved_cmap)) == -1) {
@@ -1240,9 +1618,9 @@ WsfbDGASetMode(ScrnInfoPtr pScrn, DGAMod
 		frameY0 = pScrn->frameY0;
 	}
 
-	if (!(*pScrn->SwitchMode)(scrnIdx, pMode, 0))
+	if (!(*pScrn->SwitchMode)(SWITCH_MODE_ARGS(pScrn, pMode)))
 		return FALSE;
-	(*pScrn->AdjustFrame)(scrnIdx, frameX0, frameY0, 0);
+	(*pScrn->AdjustFrame)(ADJUST_FRAME_ARGS(pScrn, frameX0, frameY0));
 
 	return TRUE;
 }
@@ -1250,7 +1628,7 @@ WsfbDGASetMode(ScrnInfoPtr pScrn, DGAMod
 static void
 WsfbDGASetViewport(ScrnInfoPtr pScrn, int x, int y, int flags)
 {
-	(*pScrn->AdjustFrame)(pScrn->pScreen->myNum, x, y, flags);
+	(*pScrn->AdjustFrame)(ADJUST_FRAME_ARGS(pScrn, x, y));
 }
 
 static int
@@ -1305,12 +1683,12 @@ WsfbDGAAddModes(ScrnInfoPtr pScrn)
 		pDGAMode->viewportWidth = pMode->HDisplay;
 		pDGAMode->viewportHeight = pMode->VDisplay;
 
-		if (fPtr->linebytes)
-			pDGAMode->bytesPerScanline = fPtr->linebytes;
+		if (fPtr->fbi.fbi_stride)
+			pDGAMode->bytesPerScanline = fPtr->fbi.fbi_stride;
 		else {
 			ioctl(fPtr->fd, WSDISPLAYIO_LINEBYTES,
-			      &fPtr->linebytes);
-			pDGAMode->bytesPerScanline = fPtr->linebytes;
+			      &fPtr->fbi.fbi_stride);
+			pDGAMode->bytesPerScanline = fPtr->fbi.fbi_stride;
 		}
 
 		pDGAMode->imageWidth = pMode->HDisplay;
@@ -1360,3 +1738,171 @@ WsfbDriverFunc(ScrnInfoPtr pScrn, xorgDr
 	}
 }
 
+#if defined(BGRA_XSRC_NETBSD)
+static inline void
+memcpy32sw(void *dest, void *src, int len)
+{
+	uint32_t *d = dest, *s = src;
+
+#if DEBUG
+	if ((((long)dest & 3) + ((long)src & 3) + (len & 3)) != 0) {
+		xf86Msg(X_ERROR, "unaligned %s\n", __func__);
+		return;
+	}
+#endif
+	while (len > 0) {
+		*d = bswap32(*s);
+		d++;
+		s++;
+		len -= 4;
+	}
+}
+
+/* adapted from miext/shadow/shpacked.c::shadowUpdatePacked() */
+void
+WsfbShadowUpdateSwap32(ScreenPtr pScreen, shadowBufPtr pBuf)
+{
+    RegionPtr	damage = DamageRegion (pBuf->pDamage);
+    PixmapPtr	pShadow = pBuf->pPixmap;
+    int		nbox = RegionNumRects (damage);
+    BoxPtr	pbox = RegionRects (damage);
+    FbBits	*shaBase, *shaLine, *sha;
+    FbStride	shaStride;
+    int		scrBase, scrLine, scr;
+    int		shaBpp;
+    int		shaXoff, shaYoff; /* XXX assumed to be zero */
+    int		x, y, w, h, width;
+    int         i;
+    FbBits	*winBase = NULL, *win;
+    CARD32      winSize;
+
+    fbGetDrawable (&pShadow->drawable, shaBase, shaStride, shaBpp, shaXoff, shaYoff);
+    while (nbox--)
+    {
+	x = pbox->x1 * shaBpp;
+	y = pbox->y1;
+	w = (pbox->x2 - pbox->x1) * shaBpp;
+	h = pbox->y2 - pbox->y1;
+
+	scrLine = (x >> FB_SHIFT);
+	shaLine = shaBase + y * shaStride + (x >> FB_SHIFT);
+				   
+	x &= FB_MASK;
+	w = (w + x + FB_MASK) >> FB_SHIFT;
+	
+	while (h--)
+	{
+	    winSize = 0;
+	    scrBase = 0;
+	    width = w;
+	    scr = scrLine;
+	    sha = shaLine;
+	    while (width) {
+		/* how much remains in this window */
+		i = scrBase + winSize - scr;
+		if (i <= 0 || scr < scrBase)
+		{
+		    winBase = (FbBits *) (*pBuf->window) (pScreen,
+							  y,
+							  scr * sizeof (FbBits),
+							  SHADOW_WINDOW_WRITE,
+							  &winSize,
+							  pBuf->closure);
+		    if(!winBase)
+			return;
+		    scrBase = scr;
+		    winSize /= sizeof (FbBits);
+		    i = winSize;
+		}
+		win = winBase + (scr - scrBase);
+		if (i > width)
+		    i = width;
+		width -= i;
+		scr += i;
+		memcpy32sw(win, sha, i * sizeof(FbBits));
+		sha += i;
+	    }
+	    shaLine += shaStride;
+	    y++;
+	}
+	pbox++;
+    }
+}
+#endif /* BGRA_XSRC_NETBSD */
+
+#if defined(WILDCAT_XSRC_NETBSD)
+void
+WsfbShadowUpdateSplit(ScreenPtr pScreen, shadowBufPtr pBuf)
+{
+    ScrnInfoPtr pScrn = xf86Screens[pScreen->myNum];
+    WsfbPtr 	fPtr = WSFBPTR(pScrn);
+    RegionPtr	damage = DamageRegion (pBuf->pDamage);
+    PixmapPtr	pShadow = pBuf->pPixmap;
+    int		nbox = RegionNumRects (damage);
+    BoxPtr	pbox = RegionRects (damage);
+    FbBits	*shaBase, *shaLine, *sha;
+    FbStride	shaStride;
+    int		scrBase, scrLine, scr;
+    int		shaBpp;
+    int		shaXoff, shaYoff; /* XXX assumed to be zero */
+    int		x, y, w, h, width;
+    int         i;
+    FbBits	*winBase = NULL, *win, *win2;
+    unsigned long split = fPtr->fbi.fbi_fbsize / 2; 
+    CARD32      winSize;
+
+    fbGetDrawable (&pShadow->drawable, shaBase, shaStride, shaBpp, shaXoff, shaYoff);
+    while (nbox--)
+    {
+	x = pbox->x1 * shaBpp;
+	y = pbox->y1;
+	w = (pbox->x2 - pbox->x1) * shaBpp;
+	h = pbox->y2 - pbox->y1;
+
+	scrLine = (x >> FB_SHIFT);
+	shaLine = shaBase + y * shaStride + (x >> FB_SHIFT);
+				   
+	x &= FB_MASK;
+	w = (w + x + FB_MASK) >> FB_SHIFT;
+	
+	while (h--)
+	{
+	    winSize = 0;
+	    scrBase = 0;
+	    width = w;
+	    scr = scrLine;
+	    sha = shaLine;
+	    while (width) {
+		/* how much remains in this window */
+		i = scrBase + winSize - scr;
+		if (i <= 0 || scr < scrBase)
+		{
+		    winBase = (FbBits *) (*pBuf->window) (pScreen,
+							  y,
+							  scr * sizeof (FbBits),
+							  SHADOW_WINDOW_WRITE,
+							  &winSize,
+							  pBuf->closure);
+		    if(!winBase)
+			return;
+		    scrBase = scr;
+		    winSize /= sizeof (FbBits);
+		    i = winSize;
+		}
+		win = winBase + (scr - scrBase);
+		win2 = (FbBits *)(split + (unsigned long)win);
+		if (i > width)
+		    i = width;
+		width -= i;
+		scr += i;
+		memcpy(win, sha, i * sizeof(FbBits));
+		memcpy(win2, sha, i * sizeof(FbBits));
+		sha += i;
+	    }
+	    shaLine += shaStride;
+	    y++;
+	}
+	pbox++;
+    }
+}
+#endif
