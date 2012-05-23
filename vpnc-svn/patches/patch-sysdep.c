$NetBSD: patch-sysdep.c,v 1.1.1.1 2012/05/23 15:37:12 hfath Exp $

--- sysdep.c.orig	2012-05-23 13:52:36.000000000 +0000
+++ sysdep.c
@@ -666,7 +666,7 @@ int tun_get_hwaddr(int fd, char *dev, ui
 	}
 
 	return 0;
-#elif defined(SIOCGIFHWADDR)
+#elif defined(SIOCGIFHWADDR) || defined(SIOCGENADDR)
 	struct ifreq ifr;
 
 	/* Use a new socket fd! */
@@ -677,12 +677,20 @@ int tun_get_hwaddr(int fd, char *dev, ui
 	memset(&ifr, 0, sizeof(struct ifreq));
 	strncpy(ifr.ifr_name, dev, IFNAMSIZ);
 
+#if defined(SIOCGIFHWADDR) && !defined(__sun)
 	if (ioctl(fd, SIOCGIFHWADDR, &ifr) < 0) {
 		return -1;
 	}
 
 	memcpy(hwaddr, &ifr.ifr_hwaddr.sa_data, ETH_ALEN);
-
+#endif
+#if defined(SIOCGENADDR)
+	if (ioctl(fd, SIOCGENADDR, &ifr) < 0) {
+		return -1;
+	}
+	
+	memcpy(hwaddr, &ifr.ifr_enaddr, ETH_ALEN);
+#endif
 	return 0;
 #else
 	/* todo: implement using SIOCGLIFADDR */
@@ -751,7 +759,7 @@ void error(int status, int errornum, con
 #endif
 
 #ifndef HAVE_GETLINE
-int getline(char **line, size_t * length, FILE * stream)
+ssize_t getline(char **line, size_t * length, FILE * stream)
 {
 	size_t len;
 #ifdef HAVE_FGETLN
