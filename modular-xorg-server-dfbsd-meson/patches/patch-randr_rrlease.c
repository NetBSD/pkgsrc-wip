$NetBSD$

Option to revert effects of upstream:

2018-02-27	Add RandR leases with modesetting driver support [v6]

commit	e4e3447603b5fd3a38a92c3f972396d1f81168ad

--- randr/rrlease.c.orig	2018-10-15 15:59:33.000000000 +0000
+++ randr/rrlease.c
@@ -101,6 +101,7 @@ RRLeaseAlloc(ScreenPtr screen, RRLease l
 Bool
 RRCrtcIsLeased(RRCrtcPtr crtc)
 {
+#if !defined(REVERT_RANDR_LEASE)
     ScreenPtr screen = crtc->pScreen;
     rrScrPrivPtr scr_priv = rrGetScrPriv(screen);
     RRLeasePtr lease;
@@ -111,6 +112,7 @@ RRCrtcIsLeased(RRCrtcPtr crtc)
             if (lease->crtcs[c] == crtc)
                 return TRUE;
     }
+#endif
     return FALSE;
 }
 
@@ -120,6 +122,7 @@ RRCrtcIsLeased(RRCrtcPtr crtc)
 Bool
 RROutputIsLeased(RROutputPtr output)
 {
+#if !defined(REVERT_RANDR_LEASE)
     ScreenPtr screen = output->pScreen;
     rrScrPrivPtr scr_priv = rrGetScrPriv(screen);
     RRLeasePtr lease;
@@ -130,6 +133,7 @@ RROutputIsLeased(RROutputPtr output)
             if (lease->outputs[o] == output)
                 return TRUE;
     }
+#endif
     return FALSE;
 }
 
@@ -172,10 +176,12 @@ RRLeaseFree(RRLeasePtr lease)
 void
 RRTerminateLease(RRLeasePtr lease)
 {
+#if !defined(REVERT_RANDR_LEASE)
     ScreenPtr screen = lease->screen;
     rrScrPrivPtr scr_priv = rrGetScrPriv(screen);
 
     scr_priv->rrTerminateLease(screen, lease);
+#endif
 }
 
 /*
