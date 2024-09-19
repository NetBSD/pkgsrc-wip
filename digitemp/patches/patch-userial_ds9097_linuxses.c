$NetBSD: patch-userial_ds9097_linuxses.c,v 1.1.1.1 2011/10/29 06:08:03 errellion Exp $

--- userial/ds9097/linuxses.c.orig	2007-06-07 21:25:58.000000000 +0000
+++ userial/ds9097/linuxses.c
@@ -55,7 +55,7 @@ struct termios term_orig[MAX_PORTNUM]; /
 SMALLINT owAcquire(int portnum, char *port_zstr)
 {  
    /* Open the serial port */
-   if ((fd[portnum] = open(port_zstr, O_RDWR)) == -1)
+   if ((fd[portnum] = open(port_zstr, O_RDWR|O_NONBLOCK)) == -1)
      {
 	OWERROR(OWERROR_GET_SYSTEM_RESOURCE_FAILED);
 	perror("owAcquire: failed to open device");
