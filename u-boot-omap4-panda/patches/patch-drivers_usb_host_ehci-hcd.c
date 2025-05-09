$NetBSD$

--- drivers/usb/host/ehci-hcd.c.orig	2025-05-03 07:57:06.649117012 +0000
+++ drivers/usb/host/ehci-hcd.c
@@ -15,6 +15,8 @@
 #include <asm/cache.h>
 #include <asm/unaligned.h>
 #include <usb.h>
+#include <asm/arch/ehci.h>
+#include <asm/ehci-omap.h>
 #include <asm/io.h>
 #include <malloc.h>
 #include <memalign.h>
@@ -1132,6 +1134,35 @@ static int ehci_common_init(struct ehci_
 }
 
 #if !CONFIG_IS_ENABLED(DM_USB)
+static struct omap_usbhs_board_data usbhs_bdata = {
+	.port_mode[0] = OMAP_EHCI_PORT_MODE_PHY,
+	.port_mode[1] = OMAP_USBHS_PORT_MODE_UNUSED,
+	.port_mode[2] = OMAP_USBHS_PORT_MODE_UNUSED,
+};
+
+int ehci_hcd_init(int index, enum usb_init_type init,
+		struct ehci_hccr **hccr, struct ehci_hcor **hcor)
+{
+	int ret;
+	unsigned int utmi_clk;
+
+	/* Now we can enable our port clocks */
+	utmi_clk = readl((void *)CM_L3INIT_HSUSBHOST_CLKCTRL);
+	utmi_clk |= HSUSBHOST_CLKCTRL_CLKSEL_UTMI_P1_MASK;
+	setbits_le32((void *)CM_L3INIT_HSUSBHOST_CLKCTRL, utmi_clk);
+
+	ret = omap_ehci_hcd_init(index, &usbhs_bdata, hccr, hcor);
+	if (ret < 0)
+		return ret;
+
+	return 0;
+}
+
+int ehci_hcd_stop(int index)
+{
+	return omap_ehci_hcd_stop();
+}
+
 int usb_lowlevel_stop(int index)
 {
 	ehci_shutdown(&ehcic[index]);
