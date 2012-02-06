$NetBSD: patch-lib__uuid__gen_uuid.c,v 1.1 2012/02/06 20:15:18 fhajny Exp $

Ignore SIOCGIFHWADDR, for SunOS>snv_124.
--- lib/uuid/gen_uuid.c.orig	2004-09-18 00:38:27.000000000 +0000
+++ lib/uuid/gen_uuid.c
@@ -178,7 +178,7 @@ static int get_node_id(unsigned char *no
 	for (i = 0; i < n; i+= ifreq_size(*ifrp) ) {
 		ifrp = (struct ifreq *)((char *) ifc.ifc_buf+i);
 		strncpy(ifr.ifr_name, ifrp->ifr_name, IFNAMSIZ);
-#ifdef SIOCGIFHWADDR
+#if defined(SIOCGIFHWADDR) && !defined(sun)
 		if (ioctl(sd, SIOCGIFHWADDR, &ifr) < 0)
 			continue;
 		a = (unsigned char *) &ifr.ifr_hwaddr.sa_data;
