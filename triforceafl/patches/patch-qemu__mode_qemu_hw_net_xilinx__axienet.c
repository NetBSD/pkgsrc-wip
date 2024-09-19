$NetBSD$

Avoid conflicts with SSP read() macro in NetBSD's <ssp/unistd.h>
(PR lib/43832: ssp causes common names to be defines)

--- qemu_mode/qemu/hw/net/xilinx_axienet.c.orig	2017-05-31 22:53:05.000000000 +0000
+++ qemu_mode/qemu/hw/net/xilinx_axienet.c
@@ -210,7 +210,7 @@ static uint16_t mdio_read_req(struct MDI
 
     phy = bus->devs[addr];
     if (phy && phy->read) {
-        data = phy->read(phy, reg);
+        data = (*phy->read)(phy, reg);
     } else {
         data = 0xffff;
     }
