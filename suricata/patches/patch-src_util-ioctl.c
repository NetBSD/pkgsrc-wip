$NetBSD$

--- src/util-ioctl.c.orig	2025-09-22 18:04:28.981310802 +0000
+++ src/util-ioctl.c
@@ -196,6 +196,8 @@ int SetIfaceFlags(const char *ifname, in
 #ifdef OS_FREEBSD
     ifr.ifr_flags = flags & 0xffff;
     ifr.ifr_flagshigh = flags >> 16;
+#elif defined __NetBSD__
+    ifr.ifr_flags = flags & IFCAP_MASK;
 #else
     ifr.ifr_flags = (uint16_t)flags;
 #endif
@@ -214,8 +216,13 @@ int SetIfaceFlags(const char *ifname, in
 #ifdef SIOCGIFCAP
 int GetIfaceCaps(const char *ifname)
 {
-    struct ifreq ifr;
-
+#ifdef __NetBSD__
+  struct ifcapreq ifr;
+  #define ifr_name ifcr_name
+#else
+  struct ifreq ifr;
+#endif
+  
     int fd = socket(AF_INET, SOCK_DGRAM, 0);
     if (fd < 0) {
         return -1;
@@ -231,14 +238,22 @@ int GetIfaceCaps(const char *ifname)
     }
 
     close(fd);
+#ifdef __NetBSD__
+    return ifr.ifcr_capabilities & IFCAP_MASK;
+#else
     return ifr.ifr_curcap;
+#endif
 }
 #endif
 #ifdef SIOCSIFCAP
 int SetIfaceCaps(const char *ifname, int caps)
 {
-    struct ifreq ifr;
-
+#ifdef __NetBSD__
+  struct ifcapreq ifr;
+#else
+  struct ifreq ifr;
+#endif
+  
     int fd = socket(AF_INET, SOCK_DGRAM, 0);
     if (fd < 0) {
         return -1;
@@ -246,8 +261,12 @@ int SetIfaceCaps(const char *ifname, int
 
     memset(&ifr, 0, sizeof(ifr));
     strlcpy(ifr.ifr_name, ifname, sizeof(ifr.ifr_name));
+#ifdef __NetBSD__
+    ifr.ifcr_capabilities = caps & IFCAP_MASK;
+#else
     ifr.ifr_reqcap = caps;
-
+#endif
+    
     if (ioctl(fd, SIOCSIFCAP, &ifr) == -1) {
         SCLogError("%s: unable to set caps: %s", ifname, strerror(errno));
         close(fd);
@@ -524,6 +543,11 @@ static int GetIfaceOffloadingBSD(const c
     }
     SCLogDebug("if_caps %X", if_caps);
 
+#ifdef __NetBSD__
+#define IFCAP_RXCSUM (IFCAP_CSUM_IPv4_Rx | IFCAP_CSUM_TCPv4_Rx | IFCAP_CSUM_UDPv4_Rx | \
+		      IFCAP_CSUM_TCPv6_Rx | IFCAP_CSUM_UDPv6_Rx)
+#define IFCAP_TSO (IFCAP_TSOv4 | IFCAP_TSOv6)
+#endif
     if (if_caps & IFCAP_RXCSUM) {
         SCLogWarning("%s: RXCSUM activated can lead to capture problems. Run: ifconfig %s -rxcsum",
                 ifname, ifname);
@@ -568,6 +592,12 @@ static int DisableIfaceOffloadingBSD(Liv
         SCLogPerf("%s: disabling rxcsum offloading", ifname);
         set_caps &= ~IFCAP_RXCSUM;
     }
+
+#ifdef __NetBSD__
+#define IFCAP_TXCSUM (IFCAP_CSUM_IPv4_Tx | IFCAP_CSUM_TCPv4_Tx | IFCAP_CSUM_UDPv4_Tx | \
+		      IFCAP_CSUM_TCPv6_Tx | IFCAP_CSUM_UDPv6_Tx)
+#endif
+
     if (if_caps & IFCAP_TXCSUM) {
         SCLogPerf("%s: disabling txcsum offloading", ifname);
         set_caps &= ~IFCAP_TXCSUM;
