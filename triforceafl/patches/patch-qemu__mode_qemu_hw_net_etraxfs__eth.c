$NetBSD$

Avoid conflicts with SSP read() macro in NetBSD's <ssp/unistd.h>
(PR lib/43832: ssp causes common names to be defines)

--- qemu_mode/qemu/hw/net/etraxfs_eth.c.orig	2017-05-31 22:53:05.000000000 +0000
+++ qemu_mode/qemu/hw/net/etraxfs_eth.c
@@ -185,7 +185,7 @@ static void mdio_read_req(struct qemu_md
 
     phy = bus->devs[bus->addr];
     if (phy && phy->read) {
-        bus->data = phy->read(phy, bus->req);
+	bus->data = (*phy->read)(phy, bus->req);
     } else {
         bus->data = 0xffff;
     }
@@ -364,7 +364,7 @@ static void eth_validate_duplex(ETRAXFSE
     int new_mm = 0;
 
     phy = eth->mdio_bus.devs[eth->phyaddr];
-    phy_duplex = !!(phy->read(phy, 18) & (1 << 11));
+    phy_duplex = !!((*phy->read)(phy, 18) & (1 << 11));
     mac_duplex = !!(eth->regs[RW_REC_CTRL] & 128);
 
     if (mac_duplex != phy_duplex) {
