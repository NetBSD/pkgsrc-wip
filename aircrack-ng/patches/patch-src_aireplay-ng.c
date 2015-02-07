$NetBSD: patch-src_aireplay-ng.c,v 1.1 2015/02/07 01:35:39 tnn2 Exp $

--- src/aireplay-ng.c.orig	2014-10-21 02:13:52.000000000 +0000
+++ src/aireplay-ng.c
@@ -743,7 +743,7 @@ int attack_check(unsigned char* bssid, c
         if((ap_chan != iface_chan) && (iface_chan != -1 || !opt.ignore_negative_one))
         {
             PCT; printf("%s is on channel %d, but the AP uses channel %d\n", wi_get_ifname(wi), iface_chan, ap_chan);
-            return -1;
+	    wi_set_channel(wi, ap_chan);
         }
     }
 
