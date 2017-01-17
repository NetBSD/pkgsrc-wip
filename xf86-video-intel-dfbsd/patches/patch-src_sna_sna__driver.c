$NetBSD: patch-src_sna_sna__driver.c,v 1.1 2016/12/07 21:59:54 wiz Exp $

Upstream patches for xorg-server-1.19.

Wrong place for #if !HAVE_NOTIFY_FD condition.

"sna: Update sanity check for next stage of Xorg ABI" 2016-09-19
https://cgit.freedesktop.org/xorg/driver/xf86-video-intel/commit/?id=b45dbdbd446108745b39b305303b457f5e876989

"sna: Wrap direct access to ScrnInfoPtr->pScreen" 2015-01-13
https://cgit.freedesktop.org/xorg/driver/xf86-video-intel/commit/?id=b7feeca0730bf55c23e5bc5af4cae9b8a73bba0e

--- src/sna/sna_driver.c.orig	2014-12-11 13:52:11.000000000 +0000
+++ src/sna/sna_driver.c
@@ -721,6 +721,7 @@ cleanup:
 	return FALSE;
 }
 
+#if !HAVE_NOTIFY_FD
 static bool has_shadow(struct sna *sna)
 {
 	if (!sna->mode.shadow_damage)
@@ -778,6 +779,31 @@ sna_wakeup_handler(WAKEUPHANDLER_ARGS_DE
 		FD_CLR(sna->kgem.fd, (fd_set*)read_mask);
 	}
 }
+#else
+static void
+sna_block_handler(void *data, void *_timeout)
+{
+	struct sna *sna = data;
+	int *timeout = _timeout;
+	struct timeval tv, *tvp;
+
+	DBG(("%s (timeout=%d)\n", __FUNCTION__, *timeout));
+	if (*timeout == 0)
+		return;
+
+	if (*timeout < 0) {
+		tvp = NULL;
+	} else {
+		tv.tv_sec = *timeout / 1000;
+		tv.tv_usec = (*timeout % 1000) * 1000;
+		tvp = &tv;
+	}
+
+	sna_accel_block_handler(sna, &tvp);
+	if (tvp)
+		*timeout = tvp->tv_sec * 1000 + tvp->tv_usec / 1000;
+}
+#endif
 
 #if HAVE_UDEV
 static void
@@ -948,6 +974,12 @@ static Bool sna_early_close_screen(CLOSE
 
 	/* XXX Note that we will leak kernel resources if !vtSema */
 
+#if HAVE_NOTIFY_FD
+	RemoveBlockAndWakeupHandlers(sna_block_handler,
+				     (ServerWakeupHandlerProcPtr)NoopDDA,
+				     sna);
+#endif
+
 	sna_uevent_fini(sna);
 	sna_mode_close(sna);
 
@@ -1098,7 +1130,8 @@ sna_screen_init(SCREEN_INIT_ARGS_DECL)
 	DBG(("%s\n", __FUNCTION__));
 
 	assert(sna->scrn == scrn);
-	assert(scrn->pScreen == NULL); /* set afterwards */
+	assert(scrn->pScreen == NULL || /* set afterwards */
+	       scrn->pScreen == screen);
 
 	assert(sna->freed_pixmap == NULL);
 
@@ -1166,11 +1199,17 @@ sna_screen_init(SCREEN_INIT_ARGS_DECL)
 	 * later memory should be bound when allocating, e.g rotate_mem */
 	scrn->vtSema = TRUE;
 
+#if !HAVE_NOTIFY_FD
 	sna->BlockHandler = screen->BlockHandler;
 	screen->BlockHandler = sna_block_handler;
 
 	sna->WakeupHandler = screen->WakeupHandler;
 	screen->WakeupHandler = sna_wakeup_handler;
+#else
+	RegisterBlockAndWakeupHandlers(sna_block_handler,
+				       (ServerWakeupHandlerProcPtr)NoopDDA,
+				       sna);
+#endif
 
 	screen->SaveScreen = sna_save_screen;
 	screen->CreateScreenResources = sna_create_screen_resources;
