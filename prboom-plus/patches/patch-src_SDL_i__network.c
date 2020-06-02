$NetBSD$

Fix heap buffer overflows in UDP code (CVE-2019-20797)
Backported from:
https://github.com/coelckers/prboom-plus/commit/1a081d10e6c71a5b5b2db76081227677f06b47b3

--- src/SDL/i_network.c.orig	2014-05-20 04:47:44.000000000 +0000
+++ src/SDL/i_network.c
@@ -248,7 +248,8 @@ size_t I_GetPacket(packet_header_t* buff
   checksum=buffer->checksum;
   buffer->checksum=0;
   if ( (status!=0) && (len>0)) {
-    byte psum = ChecksumPacket(buffer, udp_packet->len);
+/*    byte psum = ChecksumPacket(buffer, udp_packet->len); */
+    byte psum = ChecksumPacket(buffer, len); // https://logicaltrust.net/blog/2019/10/prboom1.html
 /*    fprintf(stderr, "recvlen = %u, stolen = %u, csum = %u, psum = %u\n",
   udp_packet->len, len, checksum, psum); */
     if (psum == checksum) return len;
