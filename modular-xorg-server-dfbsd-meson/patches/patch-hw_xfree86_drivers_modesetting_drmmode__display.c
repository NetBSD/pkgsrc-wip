$NetBSD$

Option to revert effects of upstream:

2018-02-27	Add RandR leases with modesetting driver support [v6]

commit	e4e3447603b5fd3a38a92c3f972396d1f81168ad

Option from OpenBSD xenocara for randr backlight setting

--- hw/xfree86/drivers/modesetting/drmmode_display.c.orig	2019-03-05 16:34:21.000000000 +0000
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
+        if (ret) {
+            ErrorF("failed to set scanout pixmap cpu\n");
+            return FALSE;
+        }
+#endif
     }
     *target = ppix;
     return TRUE;
@@ -2579,6 +2589,10 @@ drmmode_property_ignore(drmModePropertyP
     return FALSE;
 }
 
+#if defined(RANDR_BACKLIGHT)
+static Atom backlight_atom;
+#endif
+
 static void
 drmmode_output_create_resources(xf86OutputPtr output)
 {
@@ -2757,7 +2771,52 @@ drmmode_output_set_property(xf86OutputPt
 static Bool
 drmmode_output_get_property(xf86OutputPtr output, Atom property)
 {
+#if defined(RANDR_BACKLIGHT)
+    drmmode_output_private_ptr drmmode_output = output->driver_private;
+    drmmode_ptr drmmode = drmmode_output->drmmode;
+    drmModeObjectPropertiesPtr props;
+    int i;
+
+    if (property != backlight_atom)
+        return TRUE;
+
+    props = drmModeObjectGetProperties(drmmode->fd, drmmode_output->output_id,
+				       DRM_MODE_OBJECT_CONNECTOR);
+    if (!props)
+        return FALSE;
+
+    for (i = 0; i < drmmode_output->num_props; i++) {
+        drmmode_prop_ptr p = &drmmode_output->props[i];
+        int j;
+
+        if (p->atoms[0] != property)
+    continue;
+
+        for (j = 0; j < props->count_props; j++) {
+	    if (props->props[j] == p->mode_prop->prop_id) {
+                INT32 value;
+                int err;
+
+                value = p->value = props->prop_values[j];
+                err = RRChangeOutputProperty(output->randr_output, p->atoms[0],
+                                             XA_INTEGER, 32, PropModeReplace, 1,
+                                             &value, FALSE, TRUE);
+                if (err != 0) {
+                    xf86DrvMsg(output->scrn->scrnIndex, X_ERROR,
+                               "RRChangeOutputProperty error, %d\n", err);
+                }
+
+                drmModeFreeObjectProperties(props);
+                return TRUE;
+            }
+        }
+    }
+
+    drmModeFreeObjectProperties(props);
+    return FALSE;
+#else
     return TRUE;
+#endif
 }
 
 static const xf86OutputFuncsRec drmmode_output_funcs = {
@@ -2837,7 +2896,11 @@ static int parse_path_blob(drmModeProper
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
@@ -3202,6 +3265,7 @@ drmmode_xf86crtc_resize(ScrnInfoPtr scrn
     return FALSE;
 }
 
+#if !defined(REVERT_RANDR_LEASE)
 static void
 drmmode_validate_leases(ScrnInfoPtr scrn)
 {
@@ -3239,6 +3303,7 @@ drmmode_validate_leases(ScrnInfoPtr scrn
 
     free(lessees);
 }
+#endif
 
 static int
 drmmode_create_lease(RRLeasePtr lease, int *fd)
@@ -3491,8 +3556,10 @@ drmmode_set_desired_modes(ScrnInfoPtr pS
         }
     }
 
+#if !defined(REVERT_RANDR_LEASE)
     /* Validate leases on VT re-entry */
     drmmode_validate_leases(pScrn);
+#endif
 
     return TRUE;
 }
@@ -3699,8 +3766,10 @@ drmmode_handle_uevents(int fd, void *clo
         drmmode_output_init(scrn, drmmode, mode_res, i, TRUE, 0);
     }
 
+#if !defined(REVERT_RANDR_LEASE)
     /* Check to see if a lessee has disappeared */
     drmmode_validate_leases(scrn);
+#endif
 
     if (changed) {
         RRSetChanged(xf86ScrnToScreen(scrn));
