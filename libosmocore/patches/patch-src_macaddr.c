$NetBSD$

--- src/macaddr.c.orig	2019-01-21 13:50:43.000000000 +0000
+++ src/macaddr.c
@@ -135,6 +135,7 @@ int osmo_get_macaddr(uint8_t *mac_out, c
 
 	memset(&ifr, 0, sizeof(ifr));
 	memcpy(&ifr.ifr_name, dev_name, dev_len + 1);
+#if defined(SIOCGIFHWADDR)
 	rc = ioctl(fd, SIOCGIFHWADDR, &ifr);
 	close(fd);
 
@@ -142,6 +143,17 @@ int osmo_get_macaddr(uint8_t *mac_out, c
 		return rc;
 
 	memcpy(mac_out, ifr.ifr_hwaddr.sa_data, 6);
+#elif defined(SIOCGENADDR)
+	rc = ioctl(fd, SIOCGENADDR, &ifr);
+	close(fd);
+
+	if (rc < 0)
+		return rc;
+
+	memcpy(mac_out, &ifr.ifr_enaddr, 6);
+#else
+	return -1;
+#endif
 
 	return 0;
 }
