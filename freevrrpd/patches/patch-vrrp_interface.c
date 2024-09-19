$NetBSD$

Use (hopefully) equivalent ioctls for NetBSD, and exclude references
to struct elements it does not have.

--- vrrp_interface.c.orig	2015-02-04 00:39:49.000000000 +0000
+++ vrrp_interface.c
@@ -63,7 +63,11 @@ vrrp_interface_mac_set(char *if_name, st
 	ifr.ifr_addr.sa_len = ETHER_ADDR_LEN;
 	ifr.ifr_addr.sa_family = AF_LINK;
 	bcopy(ethaddr, ifr.ifr_addr.sa_data, ETHER_ADDR_LEN);
+#if defined(__FreeBSD__) || defined(__OpenBSD__)	
 	if (ioctl(sd, SIOCSIFLLADDR, (caddr_t) & ifr) == -1) {
+#else /* __NetBSD__ */		
+	if (ioctl(sd, SIOCGLIFADDR, (caddr_t) & ifr) == -1) {
+#endif		
 		syslog(LOG_ERR, "cannot set mac address for interface %s (ioctl): %s", if_name, strerror(errno));
 		return -1;
 	}
@@ -214,16 +218,20 @@ vrrp_interface_set_flags(char *if_name, 
 		close(sd);
 		return -1;
 	}
+#if defined(__FreeBSD__)	
 	flags = (ifr.ifr_flags & 0xffff) | (ifr.ifr_flagshigh << 16);
-
+#else /* NetBSD */
+	flags = (ifr.ifr_flags & 0xffff);
+#endif	
         if (value < 0) {
                 value = -value;
                 flags &= ~value;
         } else
                 flags |= value;
         ifr.ifr_flags = flags & 0xffff;
+#if defined(__FreeBSD__)
         ifr.ifr_flagshigh = flags >> 16;
-
+#endif
 	if (ioctl(sd, SIOCSIFFLAGS, (caddr_t)&ifr) < 0) {
 		close(sd);
 		return -1;
@@ -236,12 +244,20 @@ vrrp_interface_set_flags(char *if_name, 
 
 char
 vrrp_interface_promiscuous(char *if_name) {
+#if defined(__FreeBSD__)
 	return vrrp_interface_set_flags(if_name, IFF_PPROMISC);
+#else /* __NetBSD__ */
+	return vrrp_interface_set_flags(if_name, IFF_PROMISC);
+#endif	
 }
 
 char
 vrrp_interface_nopromiscuous(char *if_name) {
+#if defined(__FreeBSD__)
 	return vrrp_interface_set_flags(if_name, -IFF_PPROMISC);
+#else /* __NetBSD__ */
+	return vrrp_interface_set_flags(if_name, -IFF_PROMISC);
+#endif	
 }
 
 char 
