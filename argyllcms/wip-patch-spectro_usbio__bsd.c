$NetBSD$

Attempt to make actually function with NetBSD ugen(4).

--- spectro/usbio_bsd.c.orig	2018-07-09 02:57:13.000000000 +0000
+++ spectro/usbio_bsd.c
@@ -67,13 +67,15 @@ icompaths *p 
 #if defined(__FreeBSD__)
 	    "/dev/usb/[0-9]*.*.0",		/* FreeBSD >= 8 */
 	    "/dev/ugen[0-9]*",			/* FreeBSD < 8, but no .E */
+#elif defined(__NetBSD__)
+	    "/dev/ugen[0-9]*.00",		/* NetBSD */
 #else
-	    "/dev/ugen/[0-9]*.00",		/* NetBSD, OpenBSD */
+	    "/dev/ugen/[0-9]*.00",		/* OpenBSD */
 #endif
 	    NULL
 	};
 	int vid, pid;
-	int nconfig = 0, nep = 0;
+	unsigned int configix, nconfig, nep;
 	char *dpath;
 	devType itype;
 	struct usb_idevice *usbd = NULL;
@@ -85,6 +87,9 @@ icompaths *p 
 		glob_t g;
 		int fd;
 		struct usb_device_info di;
+		usb_device_descriptor_t udd;
+		struct usb_interface_desc uid;
+		struct usb_config_desc ucd;
 		int rv, found = 0;
 
 		if (paths[j] == NULL)
@@ -112,6 +117,10 @@ icompaths *p 
 
 			vid = di.udi_vendorNo;
 			pid = di.udi_productNo;
+#if 1
+			vid = 0x0971;
+			pid = 0x2005;
+#endif
 
 			a1logd(p->log, 6, "usb_get_paths: checking vid 0x%04x, pid 0x%04x\n",vid,pid);
 
@@ -121,12 +130,8 @@ icompaths *p 
 				continue;
 			}
 
-			// ~~99 need to check number of end points ~~~
-			// ~~99 and number of configs
-			nconfig = 1;
- 
-//USB_GET_DEVICEINFO	struct usb_device_info
-//USB_GET_DEVICE_DESC	struct usb_device_descriptor
+			if (ioctl(fd, USB_GET_DEVICE_DESC, &udd) < 0)
+				continue;
 
 			/* Allocate an idevice so that we can fill in the end point information */
 			if ((usbd = (struct usb_idevice *) calloc(sizeof(struct usb_idevice), 1)) == NULL) {
@@ -136,14 +141,62 @@ icompaths *p 
 				return ICOM_SYS;
 			}
 
-			usbd->nconfig = nconfig;
-			
+			usbd->nconfig = nconfig = udd.bNumConfigurations;
+
+			/* Read the configuration descriptors looking for the first configuration, first interface, */
+			/* and extract the number of end points for each configuration */
+			for (configix = 0; configix < nconfig; configix++) {
+				ucd.ucd_config_index = configix;
+				if (ioctl(fd, USB_GET_CONFIG_DESC, &ucd) < 0) {
+					free(usbd);
+					close(fd);
+					break;
+				}
+				usbd->nifce = ucd.ucd_desc.bNumInterface;
+				usbd->config = ucd.ucd_desc.bConfigurationValue;
+
+				if (ucd.ucd_desc.bConfigurationValue != 1)
+					continue;
+
+				uid.uid_config_index = USB_CURRENT_CONFIG_INDEX;
+				uid.uid_interface_index = 0;
+				uid.uid_alt_index = USB_CURRENT_ALT_INDEX;
+
+				if (ioctl(fd, USB_GET_INTERFACE_DESC, &uid) < 0) {
+					break;
+				}
+
+				nep = uid.uid_desc.bNumEndpoints;
+
+				unsigned int epix;
+				struct usb_endpoint_desc ued;
+				for (epix = 0; epix < nep; epix++) {
+					ued.ued_config_index = USB_CURRENT_CONFIG_INDEX;
+					ued.ued_interface_index = 0;
+					ued.ued_alt_index = USB_CURRENT_ALT_INDEX;
+					ued.ued_endpoint_index = epix;
+					if (ioctl(fd, USB_GET_ENDPOINT_DESC, ued) < 0) {
+						break;
+					}
+
+					const unsigned int ad = ued.ued_desc.bEndpointAddress;
+					usbd->EPINFO(ad).valid = 1;
+					usbd->EPINFO(ad).addr = ad;
+					usbd->EPINFO(ad).packetsize = UGETW(ued.ued_desc.wMaxPacketSize);
+					usbd->EPINFO(ad).type = ued.ued_desc.bmAttributes & IUSB_ENDPOINT_TYPE_MASK;
+					usbd->EPINFO(ad).interface = uid.uid_desc.bInterfaceNumber;
+					usbd->EPINFO(ad).fd = -1;
+
+					a1logd(p->log, 6, "set ep ad 0x%x packetsize %d type %d\n",ad,usbd->EPINFO(ad).packetsize,usbd->EPINFO(ad).type);
+				}
+			}
+
 			/* Found a known instrument ? */
 			if ((itype = inst_usb_match(vid, pid, nep)) != instUnknown) {
 				char pname[400], *cp;
-		
+
 				a1logd(p->log, 2, "usb_get_paths: found instrument vid 0x%04x, pid 0x%04x\n",vid,pid);
-		
+
 				/* Create the base device path */
 				dpath = g.gl_pathv[i];
 #if defined(__FreeBSD__)
@@ -175,7 +228,7 @@ icompaths *p 
 					globfree(&g);
 					return ICOM_SYS;
 				}
-		
+
 				/* Add the path and ep info to the list */
 				if ((rv = p->add_usb(p, pname, vid, pid, nep, usbd, itype)) != ICOM_OK)
 					return rv;
@@ -309,11 +362,9 @@ char **pnames		/* List of process names 
 	if (p->is_open)
 		p->close_port(p);
 
-#ifdef NEVER    // ~~99
 	/* Make sure the port is open */
 	if (!p->is_open) {
 		int rv, i, iface;
-		kkill_nproc_ctx *kpc = NULL;
 
 		if (config != 1) {
 			/* Nothing currently needs it, so we haven't implemented it yet... */
@@ -344,24 +395,26 @@ char **pnames		/* List of process names 
 			p->cconfig = 1;
 
 			if (p->cconfig != config) {
+#if 0
 				if ((rv = ioctl(p->usbd->fd, USBDEVFS_SETCONFIGURATION, &config)) != 0) {
 					a1logd(p->log, 1, "icoms_usb_setconfig failed with %d\n",rv);
 					return ICOM_SYS;
 				}
 				p->cconfig = config;
 				a1logd(p->log, 6, "usb_open_port: set config %d OK\n",config);
+#else
+				a1logd(p->log, 6, "usb_open_port: set config %d unimplemented\n",config);
+#endif
 			}
 
 			/* We're done */
 			break;
 		}
 
-		if (kpc != NULL)
-			kpc->del(kpc); 
-
 		/* Claim all the interfaces */
 		for (iface = 0; iface < p->nifce; iface++) {
 
+#if 0
 			if ((rv = ioctl(p->usbd->fd, USBDEVFS_CLAIMINTERFACE, &iface)) < 0) {
 				struct usbdevfs_getdriver getd;
 				getd.interface = iface;
@@ -386,6 +439,30 @@ char **pnames		/* List of process names 
 					return ICOM_SYS;
 				}
 			}
+#endif
+		}
+
+		for (int i = 0; i < 16 ; i++) {
+			int flg;
+			char epdpath[33];
+			if (p->ep[i].valid && p->ep[i+16].valid)
+				flg = O_RDWR;
+			else if (p->ep[i].valid)
+				flg = O_WRONLY;
+			else if (p->ep[i+16].valid)
+				flg = O_RDONLY;
+			else
+				continue;
+
+			snprintf(epdpath, sizeof(epdpath), "%s.%02d", i);
+			int fd = open(epdpath, flg);
+
+			if (p->ep[i].valid && p->ep[i+16].valid)
+				p->ep[i].fd = p->ep[i+16].fd = fd;
+			else if (p->ep[i].valid)
+				p->ep[i].fd = fd;
+			else if (p->ep[i+16].valid)
+				p->ep[i+16].fd = fd;
 		}
 
 		/* Clear any errors. */
@@ -407,25 +484,26 @@ char **pnames		/* List of process names 
 			p->rd_qa = 8;
 		a1logd(p->log, 8, "usb_open_port: 'serial' read quanta = packet size = %d\n",p->rd_qa);
 
+#if 0
 		/* Start the reaper thread to handle URB completions */
 		if ((rv = pipe(p->usbd->sd_pipe)) < 0) {
 			a1loge(p->log, ICOM_SYS, "usb_open_port: creat pipe failed with %d\n",rv);
 			return ICOM_SYS;
 		}
 		pthread_mutex_init(&p->usbd->lock, NULL);
-		
+
 		p->usbd->running = 1;
 		if ((rv = pthread_create(&p->usbd->thread, NULL, urb_reaper, (void*)p)) < 0) {
 			p->usbd->running = 0;
 			a1loge(p->log, ICOM_SYS, "usb_open_port: creating urb reaper thread failed with %s\n",rv);
 			return ICOM_SYS;
 		}
+#endif
 
 		p->is_open = 1;
 		a1logd(p->log, 8, "usb_open_port: USB port is now open\n");
 	}
 
-#endif  // ~~99
 	/* Install the cleanup signal handlers, and add to our cleanup list */
 	usb_install_signal_handlers(p);
 
@@ -525,7 +603,7 @@ a1logd(p->log, 8, "icoms_usb_transaction
 			req.nourbs--;
 		}
 	}
-	
+
 	if (cancelt != NULL) {
 		amutex_lock(cancelt->cmtx);
 		cancelt->hcancel = (void *)&req;
@@ -549,7 +627,7 @@ a1logd(p->log, 8, "icoms_usb_transaction
 			ts.tv_nsec -= 1000000000L;
 			ts.tv_sec++;
 		}
-		
+
 		for(;;) {	/* Ignore spurious wakeups */
 			if ((rv = pthread_cond_timedwait(&req.cond, &req.lock, &ts)) != 0) {
 				if (rv != ETIMEDOUT) {
@@ -568,7 +646,7 @@ a1logd(p->log, 8, "icoms_usb_transaction
 					/* Since cancelling failed, we can't wait for them to be reaped */
 					goto done;
 				}
-	
+
 				/* Wait for the cancelled URB's to be reaped */
 				for (;req.nourbs > 0;) {	/* Ignore spurious wakeups */
 					if ((rv = pthread_cond_wait(&req.cond, &req.lock)) != 0) {
