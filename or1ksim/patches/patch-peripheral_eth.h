$NetBSD: patch-peripheral_eth.h,v 1.1 2013/10/14 13:00:09 ryo-on Exp $

--- peripheral/eth.h.orig	2011-04-08 10:59:34.000000000 +0000
+++ peripheral/eth.h
@@ -196,19 +196,27 @@
 #define ETH_HLEN      14
 #endif /* __CYGWIN__ */
 
+#ifndef ETH_HLEN
+#define ETH_HLEN      14
+#endif
+
 #define ETH_ALEN    6
 
+#if !defined(__NetBSD__)
 struct ether_addr
 {
   u_int8_t ether_addr_octet[ETH_ALEN];
 };
+#endif
 
+#if !defined(__NetBSD__)
 struct ether_header
 {
   u_int8_t ether_dhost[ETH_ALEN];	/* destination eth addr */
   u_int8_t ether_shost[ETH_ALEN];	/* source ether addr    */
   u_int16_t ether_type;		/* packet type ID field */
 };
+#endif
 
 /* Ethernet protocol ID's */
 #define	ETHERTYPE_PUP		0x0200	/* Xerox PUP */
@@ -216,12 +224,14 @@ struct ether_header
 #define	ETHERTYPE_ARP		0x0806	/* Address resolution */
 #define	ETHERTYPE_REVARP	0x8035	/* Reverse ARP */
 
+#if !defined(__NetBSD__)
 #define	ETHER_ADDR_LEN	ETH_ALEN	/* size of ethernet addr */
 #define	ETHER_TYPE_LEN	2	/* bytes in type field */
 #define	ETHER_CRC_LEN	4	/* bytes in CRC field */
 #define	ETHER_HDR_LEN	ETH_HLEN	/* total octets in header */
 #define	ETHER_MIN_LEN	(ETH_ZLEN + ETHER_CRC_LEN)	/* min packet length */
 #define	ETHER_MAX_LEN	(ETH_FRAME_LEN + ETHER_CRC_LEN)	/* max packet length */
+#endif
 
 /* make sure ethenet length is valid */
 #define	ETHER_IS_VALID_LEN(foo)	\
@@ -235,8 +245,10 @@ struct ether_header
 #define	ETHERTYPE_TRAIL		0x1000	/* Trailer packet */
 #define	ETHERTYPE_NTRAILER	16
 
+#if !defined(__NetBSD__)
 #define	ETHERMTU	ETH_DATA_LEN
 #define	ETHERMIN	(ETHER_MIN_LEN-ETHER_HDR_LEN-ETHER_CRC_LEN)
+#endif
 
 #endif /* HAVE_NET_ETHERNET_H */
 
