$NetBSD$

Avoid conflicts with SSP read() macro in NetBSD's <ssp/unistd.h>
(PR lib/43832: ssp causes common names to be defines)

--- qemu_mode/qemu/hw/display/omap_dss.c.orig	2017-05-31 22:53:05.000000000 +0000
+++ qemu_mode/qemu/hw/display/omap_dss.c
@@ -794,18 +794,18 @@ static void omap_rfbi_write(void *opaque
         break;
     case 0x58:	/* RFBI_READ */
         if ((s->rfbi.control & (1 << 2)) && s->rfbi.chip[0])
-            s->rfbi.rxbuf = s->rfbi.chip[0]->read(s->rfbi.chip[0]->opaque, 1);
+	    s->rfbi.rxbuf = (*s->rfbi.chip[0]->read)(s->rfbi.chip[0]->opaque, 1);
         else if ((s->rfbi.control & (1 << 3)) && s->rfbi.chip[1])
-            s->rfbi.rxbuf = s->rfbi.chip[1]->read(s->rfbi.chip[1]->opaque, 1);
+	    s->rfbi.rxbuf = (*s->rfbi.chip[1]->read)(s->rfbi.chip[1]->opaque, 1);
         if (!-- s->rfbi.pixels)
             omap_rfbi_transfer_stop(s);
         break;
 
     case 0x5c:	/* RFBI_STATUS */
         if ((s->rfbi.control & (1 << 2)) && s->rfbi.chip[0])
-            s->rfbi.rxbuf = s->rfbi.chip[0]->read(s->rfbi.chip[0]->opaque, 0);
+	    s->rfbi.rxbuf = (*s->rfbi.chip[0]->read)(s->rfbi.chip[0]->opaque, 0);
         else if ((s->rfbi.control & (1 << 3)) && s->rfbi.chip[1])
-            s->rfbi.rxbuf = s->rfbi.chip[1]->read(s->rfbi.chip[1]->opaque, 0);
+	    s->rfbi.rxbuf = (*s->rfbi.chip[1]->read)(s->rfbi.chip[1]->opaque, 0);
         if (!-- s->rfbi.pixels)
             omap_rfbi_transfer_stop(s);
         break;
