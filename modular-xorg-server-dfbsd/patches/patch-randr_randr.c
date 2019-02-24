$NetBSD$

Option to revert effects of upstream:

2018-02-27	Add RandR leases with modesetting driver support [v6]

commit	e4e3447603b5fd3a38a92c3f972396d1f81168ad

--- randr/randr.c.orig	2018-10-15 15:59:33.000000000 +0000
+++ randr/randr.c
@@ -89,12 +89,16 @@ RRCloseScreen(ScreenPtr pScreen)
 {
     rrScrPriv(pScreen);
     int j;
+#if !defined(REVERT_RANDR_LEASE)
     RRLeasePtr lease, next;
+#endif
 
     unwrap(pScrPriv, pScreen, CloseScreen);
 
+#if !defined(REVERT_RANDR_LEASE)
     xorg_list_for_each_entry_safe(lease, next, &pScrPriv->leases, list)
         RRTerminateLease(lease);
+#endif
     for (j = pScrPriv->numCrtcs - 1; j >= 0; j--)
         RRCrtcDestroy(pScrPriv->crtcs[j]);
     for (j = pScrPriv->numOutputs - 1; j >= 0; j--)
@@ -227,6 +231,7 @@ SRRResourceChangeNotifyEvent(xRRResource
     cpswapl(from->window, to->window);
 }
 
+#if !defined(REVERT_RANDR_LEASE)
 static void _X_COLD
 SRRLeaseNotifyEvent(xRRLeaseNotifyEvent * from,
                     xRRLeaseNotifyEvent * to)
@@ -239,6 +244,7 @@ SRRLeaseNotifyEvent(xRRLeaseNotifyEvent
     cpswapl(from->lease, to->lease);
     to->created = from->created;
 }
+#endif
 
 static void _X_COLD
 SRRNotifyEvent(xEvent *from, xEvent *to)
@@ -268,10 +274,12 @@ SRRNotifyEvent(xEvent *from, xEvent *to)
         SRRResourceChangeNotifyEvent((xRRResourceChangeNotifyEvent *) from,
                                    (xRRResourceChangeNotifyEvent *) to);
         break;
+#if !defined(REVERT_RANDR_LEASE)
     case RRNotify_Lease:
         SRRLeaseNotifyEvent((xRRLeaseNotifyEvent *) from,
                             (xRRLeaseNotifyEvent *) to);
         break;
+#endif
     default:
         break;
     }
@@ -291,8 +299,10 @@ RRInit(void)
             return FALSE;
         if (!RRProviderInit())
             return FALSE;
+#if !defined(REVERT_RANDR_LEASE)
         if (!RRLeaseInit())
             return FALSE;
+#endif
         RRGeneration = serverGeneration;
     }
     if (!dixRegisterPrivateKey(&rrPrivKeyRec, PRIVATE_SCREEN, 0))
@@ -360,7 +370,9 @@ RRScreenInit(ScreenPtr pScreen)
     pScrPriv->numCrtcs = 0;
     pScrPriv->crtcs = NULL;
 
+#if !defined(REVERT_RANDR_LEASE)
     xorg_list_init(&pScrPriv->leases);
+#endif
 
     RRMonitorInit(pScreen);
 
@@ -560,11 +572,13 @@ TellChanged(WindowPtr pWin, void *value)
             }
         }
 
+#if !defined(REVERT_RANDR_LEASE)
         if (pRREvent->mask & RRLeaseNotifyMask) {
             if (pScrPriv->leasesChanged) {
                 RRDeliverLeaseEvent(client, pWin);
             }
         }
+#endif
     }
     return WT_WALKCHILDREN;
 }
