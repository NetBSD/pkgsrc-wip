$NetBSD: patch-edge.c,v 1.1 2014/03/28 03:48:22 phonohawk Exp $

On NetBSD we should open /dev/tap when TAP device name is not given.

TODO: This patch should be sent to the upstream.

--- edge.c.orig	2014-03-27 03:34:47.000000000 +0000
+++ edge.c
@@ -2377,7 +2377,7 @@ int main(int argc, char* argv[])
         encrypt_key = strdup( getenv( "N2N_KEY" ));
     }
 
-#ifdef WIN32
+#if defined(__NetBSD__) || defined(WIN32)
     tuntap_dev_name[0] = '\0';
 #endif
     memset(&(eee.supernode), 0, sizeof(eee.supernode));
