$NetBSD$

Patches from NetBSD xsrc:

Oct 7 15:43:38 2016 UTC

CID 1373515: check return value

Oct 7 15:55:36 2016 UTC

CID 1373518: Memory corruption (off-by-one)

Option to revert effects of upstream:

2018-02-27	Add RandR leases with modesetting driver support [v6]

commit	e4e3447603b5fd3a38a92c3f972396d1f81168ad

--- hw/xfree86/drivers/modesetting/drmmode_display.c.orig	2019-05-30 18:27:34.000000000 +0000
+++ hw/xfree86/drivers/modesetting/drmmode_display.c
@@ -1754,11 +1754,21 @@ drmmode_set_target_scanout_pixmap_cpu(xf
     DamageRegister(&ppix->drawable, ppriv->slave_damage);
 
     if (ppriv->fb_id == 0) {
+#if defined(STRICT_XSRC_NETBSD)
+        int ret = drmModeAddFB(drmmode->fd, ppix->drawable.width,
+#else
         drmModeAddFB(drmmode->fd, ppix->drawable.width,
+#endif
                      ppix->drawable.height,
                      ppix->drawable.depth,
                      ppix->drawable.bitsPerPixel,
                      ppix->devKind, ppriv->backing_bo->handle, &ppriv->fb_id);
+#if defined(STRICT_XSRC_NETBSD)
+	if (ret) {
+	    ErrorF("failed to set scanout pixmap cpu\n");
+	    return FALSE;
+	}
+#endif
     }
     *target = ppix;
     return TRUE;
@@ -2837,7 +2847,11 @@ static int parse_path_blob(drmModeProper
     if (!conn)
         return -1;
     len = conn - (blob_data + 4);
+#if defined(STRICT_XSRC_NETBSD)
+    if (len + 1 >= sizeof(conn_id))
+#else
     if (len + 1> 5)
+#endif
         return -1;
     memcpy(conn_id, blob_data + 4, len);
     conn_id[len] = '\0';
@@ -3202,6 +3216,7 @@ drmmode_xf86crtc_resize(ScrnInfoPtr scrn
     return FALSE;
 }
 
+#if !defined(REVERT_RANDR_LEASE)
 static void
 drmmode_validate_leases(ScrnInfoPtr scrn)
 {
@@ -3239,6 +3254,7 @@ drmmode_validate_leases(ScrnInfoPtr scrn
 
     free(lessees);
 }
+#endif
 
 static int
 drmmode_create_lease(RRLeasePtr lease, int *fd)
@@ -3491,8 +3507,10 @@ drmmode_set_desired_modes(ScrnInfoPtr pS
         }
     }
 
+#if !defined(REVERT_RANDR_LEASE)
     /* Validate leases on VT re-entry */
     drmmode_validate_leases(pScrn);
+#endif
 
     return TRUE;
 }
@@ -3699,8 +3717,10 @@ drmmode_handle_uevents(int fd, void *clo
         drmmode_output_init(scrn, drmmode, mode_res, i, TRUE, 0);
     }
 
+#if !defined(REVERT_RANDR_LEASE)
     /* Check to see if a lessee has disappeared */
     drmmode_validate_leases(scrn);
+#endif
 
     if (changed) {
         RRSetChanged(xf86ScrnToScreen(scrn));
