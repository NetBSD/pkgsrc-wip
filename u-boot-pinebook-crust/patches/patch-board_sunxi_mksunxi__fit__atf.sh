$NetBSD$

Add SCP firmware into FIT image.

From https://github.com/crust-firmware/u-boot/

--- board/sunxi/mksunxi_fit_atf.sh.orig	2019-07-15 12:45:54.389576712 +0000
+++ board/sunxi/mksunxi_fit_atf.sh
@@ -1,13 +1,14 @@
 #!/bin/sh
 #
-# script to generate FIT image source for 64-bit sunxi boards with
-# ARM Trusted Firmware and multiple device trees (given on the command line)
+# script to generate FIT image source for 64-bit sunxi boards with ARM Trusted
+# Firmware, SCP firmware, and multiple device trees (given on the command line)
 #
 # usage: $0 <dt_name> [<dt_name> [<dt_name] ...]
 
 [ -z "$BL31" ] && BL31="bl31.bin"
+[ -z "$SCP" ] && SCP="scp.bin"
 
-if [ ! -f $BL31 ]; then
+if [ ! -f "$BL31" ]; then
 	echo "WARNING: BL31 file $BL31 NOT found, resulting binary is non-functional" >&2
 	echo "Please read the section on ARM Trusted Firmware (ATF) in board/sunxi/README.sunxi64" >&2
 	BL31=/dev/null
@@ -15,15 +16,17 @@ fi
 
 if grep -q "^CONFIG_MACH_SUN50I_H6=y" .config; then
 	BL31_ADDR=0x104000
+	SCP_ADDR=0x110000
 else
 	BL31_ADDR=0x44000
+	SCP_ADDR=0x4c000
 fi
 
 cat << __HEADER_EOF
 /dts-v1/;
 
 / {
-	description = "Configuration to load ATF before U-Boot";
+	description = "Configuration to load ATF and SCP before U-Boot";
 	#address-cells = <1>;
 
 	images {
@@ -32,6 +35,7 @@ cat << __HEADER_EOF
 			data = /incbin/("u-boot-nodtb.bin");
 			type = "standalone";
 			arch = "arm64";
+			os = "u-boot";
 			compression = "none";
 			load = <0x4a000000>;
 		};
@@ -40,14 +44,28 @@ cat << __HEADER_EOF
 			data = /incbin/("$BL31");
 			type = "firmware";
 			arch = "arm64";
+			os = "arm-trusted-firmware";
 			compression = "none";
 			load = <$BL31_ADDR>;
 			entry = <$BL31_ADDR>;
 		};
 __HEADER_EOF
 
+if [ -f "$SCP" ]; then
+	cat << __SCP_EOF
+		scp {
+			description = "SCP Firmware";
+			data = /incbin/("$SCP");
+			type = "firmware";
+			arch = "or1k";
+			compression = "none";
+			load = <$SCP_ADDR>;
+		};
+__SCP_EOF
+fi
+
 cnt=1
-for dtname in $*
+for dtname
 do
 	cat << __FDT_IMAGE_EOF
 		fdt_$cnt {
@@ -67,21 +85,27 @@ cat << __CONF_HEADER_EOF
 
 __CONF_HEADER_EOF
 
+if [ -f "$SCP" ]; then
+	LOADABLES='"uboot", "scp"'
+else
+	LOADABLES='"uboot"'
+fi
+
 cnt=1
-for dtname in $*
+for dtname
 do
 	cat << __CONF_SECTION_EOF
 		config_$cnt {
 			description = "$(basename $dtname .dtb)";
-			firmware = "uboot";
-			loadables = "atf";
+			firmware = "atf";
+			loadables = $LOADABLES;
 			fdt = "fdt_$cnt";
 		};
 __CONF_SECTION_EOF
 	cnt=$((cnt+1))
 done
 
-cat << __ITS_EOF
+cat << __FOOTER_EOF
 	};
 };
-__ITS_EOF
+__FOOTER_EOF
