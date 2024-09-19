$NetBSD: patch-peripheral_eth.c,v 1.1 2013/10/14 13:00:08 ryo-on Exp $

--- peripheral/eth.c.orig	2011-04-08 10:59:34.000000000 +0000
+++ peripheral/eth.c
@@ -45,8 +45,18 @@
 #include <unistd.h>
 #include <errno.h>
 
+#if defined(__linux__)
 #include <linux/if.h>
 #include <linux/if_tun.h>
+#elif defined(__NetBSD__)
+# include <sys/param.h>
+# include <sys/sockio.h>
+# include <net/if.h>
+# include <net/if_tap.h>
+# include <net/if_ether.h>
+# include <net/if_bridgevar.h>
+# include <net/if_tun.h>
+#endif
 
 /* Package includes */
 #include "arch.h"
@@ -959,7 +969,6 @@ eth_open_file_if (struct eth_device *eth
     }
 }	/* eth_open_file_if () */
 
-
 /* -------------------------------------------------------------------------- */
 /*!Open the external TAP interface to the Ethernet
 
@@ -974,6 +983,7 @@ eth_open_file_if (struct eth_device *eth
 static void
 eth_open_tap_if (struct eth_device *eth)
 {
+#if defined(__linux__)
   struct ifreq       ifr;
 
   /* We don't support re-opening. If it's open, it stays open. */
@@ -1010,6 +1020,47 @@ eth_open_tap_if (struct eth_device *eth)
 #if ETH_DEBUG
       PRINTF ("Opened TAP %s\n", ifr.ifr_name);
 #endif
+#elif defined(__NetBSD__)
+  struct ifreq ifr;
+
+  /* We don't support re-opening. If it's open, it stays open. */
+  if (eth->rtx_fd >= 0)
+    {
+      return;
+    }
+
+  /* Open the TUN/TAP device */
+  eth->rtx_fd = open ("/dev/tun", O_RDWR);
+  if( eth->rtx_fd < 0 )
+    {
+      fprintf (stderr, "Warning: Failed to open TUN/TAP device: %s\n",
+               strerror (errno));
+      eth->rtx_fd = -1;
+      return;
+    }
+
+  /* Turn it into a specific TAP device. If we haven't specified a specific
+     (persistent) device, one will be created, but that requires superuser, or
+     at least CAP_NET_ADMIN capabilities. */
+  memset (&ifr, 0, sizeof(ifr));
+
+  if (ioctl(eth->rtx_fd, TAPGIFNAME, &ifr) < 0)
+    return;
+
+  strncpy (ifr.ifr_name, eth->tap_dev, IFNAMSIZ);
+
+  if (ioctl (eth->rtx_fd, TUNSIFHEAD, (void *) &ifr) < 0)
+    {
+      fprintf (stderr, "Warning: Failed to set TAP device %s: %s\n",
+               eth->tap_dev, strerror (errno));
+      close (eth->rtx_fd);
+      eth->rtx_fd = -1;
+      return;
+    }
+#if ETH_DEBUG
+      PRINTF ("Opened TAP %s\n", ifr.ifr_name);
+#endif
+#endif /* linux, NetBSD */
 }	/* eth_open_tap_if () */
 
 
