$NetBSD$

Option to revert effects of upstream:

2018-02-27	Add RandR leases with modesetting driver support [v6]

commit	e4e3447603b5fd3a38a92c3f972396d1f81168ad

--- hw/xfree86/drivers/modesetting/drmmode_display.c.orig	2018-10-15 15:59:33.000000000 +0000
+++ hw/xfree86/drivers/modesetting/drmmode_display.c
@@ -3196,6 +3196,7 @@ drmmode_xf86crtc_resize(ScrnInfoPtr scrn
     return FALSE;
 }
 
+#if !defined(REVERT_RANDR_LEASE)
 static void
 drmmode_validate_leases(ScrnInfoPtr scrn)
 {
@@ -3233,6 +3234,7 @@ drmmode_validate_leases(ScrnInfoPtr scrn
 
     free(lessees);
 }
+#endif
 
 static int
 drmmode_create_lease(RRLeasePtr lease, int *fd)
@@ -3485,8 +3487,10 @@ drmmode_set_desired_modes(ScrnInfoPtr pS
         }
     }
 
+#if !defined(REVERT_RANDR_LEASE)
     /* Validate leases on VT re-entry */
     drmmode_validate_leases(pScrn);
+#endif
 
     return TRUE;
 }
@@ -3693,8 +3697,10 @@ drmmode_handle_uevents(int fd, void *clo
         drmmode_output_init(scrn, drmmode, mode_res, i, TRUE, 0);
     }
 
+#if !defined(REVERT_RANDR_LEASE)
     /* Check to see if a lessee has disappeared */
     drmmode_validate_leases(scrn);
+#endif
 
     if (changed) {
         RRSetChanged(xf86ScrnToScreen(scrn));
