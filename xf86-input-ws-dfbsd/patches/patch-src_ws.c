$NetBSD: patch-src_ws.c,v 1.1 2015/10/10 20:02:52 tnn Exp $

OpenBSD xenocara option:

Dec 31 23:31:41 2017 UTC
If read() returns EIO, then the wsmouse device has gone away and our fd
to it is useless, so detach the xserver driver and close it.
Modeled on similar code in xf86-input-{keyboard,mouse}

NetBSD xsrc option

Apr 14 19:19:43 2017 UTC
be somewhat smarter with mux devices:
- don't trust the device type, if we're on a mux that may not be the whole
  story
- always call ioctl(WSMOUSEIO_GCALIBCOORDS)
- check .samplelen to see if we're in raw mode
With this touchscreens on mux devices should Just Work(tm) even if they're
not the first device on the mux.

Apr 6 20:55:03 2017 UTC
we can get calibration data from the kernel now

Sep 26 14:47:53 2011 UTC
Restore #ifndef __NetBSD__ portitions (disabling OpenBSD specific TPANEL stuff?)
which were accidentally removed in rev 1.4:
this fixes WSMOUSEIO_SCALIBCOORDS ioctl errors
and coredumps after the driver is loaded on hpcarm W-ZERO3.

--- src/ws.c.orig	2015-08-29 08:48:29.000000000 +0000
+++ src/ws.c
@@ -213,6 +213,49 @@ wsPreInit(InputDriverPtr drv, InputInfoP
 		goto fail;
 	if (ioctl(pInfo->fd, WSMOUSEIO_GTYPE, &priv->type) != 0)
 		goto fail;
+
+#if defined(CALIBRATION_KERNEL_XSRC_NETBSD)
+
+	/* assume screen coordinate space until proven wrong */
+	priv->min_x = 0;
+	priv->max_x = screenInfo.screens[priv->screen_no]->width - 1;
+	priv->min_y = 0;
+	priv->max_y = screenInfo.screens[priv->screen_no]->height - 1;
+	priv->raw = 0;
+
+	/* don't rely on the device type - we may be listening to a mux */		
+	if (ioctl(pInfo->fd, WSMOUSEIO_GCALIBCOORDS,
+		&priv->coords) != 0) {
+		/* can't get absolute coordinate space - assume mouse */
+		pInfo->type_name = XI_MOUSE;
+	} else if (priv->coords.samplelen == WSMOUSE_CALIBCOORDS_RESET) {
+		/*
+		 * we're getting raw coordinates - update accordingly and hope
+		 * that there is no other absolute positioning device on the
+		 * same mux
+		 */
+		priv->min_x = priv->coords.minx;
+		priv->max_x = priv->coords.maxx;
+		priv->min_y = priv->coords.miny;
+		priv->max_y = priv->coords.maxy;
+		priv->raw = 1;
+		pInfo->type_name = XI_TOUCHSCREEN;
+	} else {
+		/*
+		 * touchscreen not in raw mode, should send us screen
+		 * coordinates 
+		 */
+		pInfo->type_name = XI_TOUCHSCREEN;
+	}
+
+	if (priv->raw) {
+		xf86Msg(X_CONFIG,
+		    "%s device will work in raw mode\n",
+		    pInfo->name);
+	}
+
+#else /* !CALIBRATION_KERNEL_XSRC_NETBSD */
+
 	if (priv->type == WSMOUSE_TYPE_TPANEL) {
 		pInfo->type_name = XI_TOUCHSCREEN;
 		priv->raw = xf86SetBoolOption(pInfo->options, "Raw", 1);
@@ -245,6 +288,9 @@ wsPreInit(InputDriverPtr drv, InputInfoP
 		priv->min_y = 0;
 		priv->max_y = screenInfo.screens[priv->screen_no]->height - 1;
 	}
+
+#endif /* CALIBRATION_KERNEL_XSRC_NETBSD */
+
 	/* Allow options to override this */
 	priv->min_x = xf86SetIntOption(pInfo->options, "MinX", priv->min_x);
 	xf86IDrvMsg(pInfo, X_INFO, "minimum x position: %d\n", priv->min_x);
@@ -399,7 +445,9 @@ wsDeviceOn(DeviceIntPtr pWS)
 {
 	InputInfoPtr pInfo = (InputInfoPtr)pWS->public.devicePrivate;
 	WSDevicePtr priv = (WSDevicePtr)pInfo->private;
+#if !defined(UNDEF_TPANEL_XSRC_NETBSD)
 	struct wsmouse_calibcoords coords;
+#endif
 
 	DBG(1, ErrorF("WS DEVICE ON\n"));
 	if ((pInfo->fd < 0) && (wsOpen(pInfo) != Success)) {
@@ -408,6 +456,7 @@ wsDeviceOn(DeviceIntPtr pWS)
 		return !Success;
 	}
 
+#if !defined(UNDEF_TPANEL_XSRC_NETBSD)
 	if (priv->type == WSMOUSE_TYPE_TPANEL) {
 		/* get calibration values */
 		if (ioctl(pInfo->fd, WSMOUSEIO_GCALIBCOORDS, &coords) != 0) {
@@ -427,6 +476,15 @@ wsDeviceOn(DeviceIntPtr pWS)
 			}
 		}
 	}
+#endif
+
+#if defined(READ_EIO_XENOCARA_OPENBSD)
+	if (priv->remove_timer == NULL) {
+		/* allocate here where it's safe */
+		priv->remove_timer = TimerSet(priv->remove_timer,
+					      0, 0, NULL, NULL);
+	}
+#endif
 	xf86AddEnabledDevice(pInfo);
 	wsmbEmuOn(pInfo);
 	pWS->public.on = TRUE;
@@ -438,10 +496,13 @@ wsDeviceOff(DeviceIntPtr pWS)
 {
 	InputInfoPtr pInfo = (InputInfoPtr)pWS->public.devicePrivate;
 	WSDevicePtr priv = (WSDevicePtr)pInfo->private;
+#if !defined(UNDEF_TPANEL_XSRC_NETBSD)
 	struct wsmouse_calibcoords coords;
+#endif
 
 	DBG(1, ErrorF("WS DEVICE OFF\n"));
 	wsmbEmuFinalize(pInfo);
+#if !defined(UNDEF_TPANEL_XSRC_NETBSD)
 	if (priv->type == WSMOUSE_TYPE_TPANEL) {
 		/* Restore calibration data */
 		memcpy(&coords, &priv->coords, sizeof coords);
@@ -450,6 +511,7 @@ wsDeviceOff(DeviceIntPtr pWS)
 			    strerror(errno));
 		}
 	}
+#endif
 	if (pInfo->fd >= 0) {
 		xf86RemoveEnabledDevice(pInfo);
 		wsClose(pInfo);
@@ -457,6 +519,22 @@ wsDeviceOff(DeviceIntPtr pWS)
 	pWS->public.on = FALSE;
 }
 
+#if defined(READ_EIO_XENOCARA_OPENBSD)
+/*
+ * Called as an OsTimer() callback to remove the device while xf86Wakeup()
+ * isn't playing with the list.
+ */
+static CARD32
+wsRemoveMouse(OsTimerPtr timer, CARD32 now, pointer arg)
+{
+	InputInfoPtr pInfo = (InputInfoPtr) arg;
+
+	xf86DisableDevice(pInfo->dev, TRUE);
+
+	return 0;	/* don't set to run again */
+}
+#endif
+
 static size_t
 wsReadEvents(InputInfoPtr pInfo)
 {
@@ -466,7 +544,18 @@ wsReadEvents(InputInfoPtr pInfo)
 	priv->events_count = priv->events_pos = 0;
 	len = read(pInfo->fd, priv->events, sizeof(priv->events));
 	if (len < 0) {
+#if defined(READ_EIO_XENOCARA_OPENBSD)
+		if (errno == EIO) {
+			xf86IDrvMsg(pInfo, X_ERROR,
+			    "device no longer present - removing: %s\n",
+			    strerror(errno));
+			xf86RemoveEnabledDevice(pInfo);
+			priv->remove_timer = TimerSet(priv->remove_timer, 0, 1,
+						      wsRemoveMouse, pInfo);
+		} else if (errno != EAGAIN)
+#else
 		if (errno != EAGAIN)
+#endif
 			xf86IDrvMsg(pInfo, X_ERROR, "read error %s\n",
 			    strerror(errno));
 	} else if (len % sizeof(struct wscons_event)) {
@@ -550,9 +639,11 @@ wsReadHwState(InputInfoPtr pInfo, wsHwSt
 		case WSCONS_EVENT_MOUSE_ABSOLUTE_W:
 			/* ignore those */
 			continue;
+#ifdef WSCONS_EVENT_SYNC
 		case WSCONS_EVENT_SYNC:
 			DBG(4, ErrorF("Sync\n"));
 			return TRUE;
+#endif
 		default:
 			xf86IDrvMsg(pInfo, X_WARNING,
 			    "bad wsmouse event type=%d\n", event->type);
@@ -680,6 +771,14 @@ wsOpen(InputInfoPtr pInfo)
 static void
 wsClose(InputInfoPtr pInfo)
 {
+#if defined(READ_EIO_XENOCARA_OPENBSD)
+	WSDevicePtr priv = (WSDevicePtr)pInfo->private;
+
+	if (priv->remove_timer != NULL) {
+		TimerFree(priv->remove_timer);
+		priv->remove_timer = NULL;
+	}
+#endif
 	xf86CloseSerial(pInfo->fd);
 	pInfo->fd = -1;
 }
@@ -793,17 +892,23 @@ wsSetCalibProperty(DeviceIntPtr device, 
 		priv->coords.maxx = priv->max_x;
 		priv->coords.miny = priv->min_y;
 		priv->coords.maxy = priv->max_y;
+#ifdef __OpenBSD__
 		priv->coords.swapxy = priv->swap_axes;
+#endif
 
 		/* Update the kernel calibration table */
 		coords.minx = priv->min_x;
 		coords.maxx = priv->max_x;
 		coords.miny = priv->min_y;
 		coords.maxy = priv->max_y;
+#ifdef __OpenBSD__
 		coords.swapxy = priv->swap_axes;
+#endif
 		coords.samplelen = priv->raw;
+#ifdef __OpenBSD__
 		coords.resx = priv->coords.resx;
 		coords.resy = priv->coords.resy;
+#endif
 		if (ioctl(pInfo->fd, WSMOUSEIO_SCALIBCOORDS, &coords) != 0) {
 			xf86IDrvMsg(pInfo, X_ERROR, "SCALIBCOORDS failed %s\n",
 			    strerror(errno));
