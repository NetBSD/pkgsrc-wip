$NetBSD$

Fallback to `-cpu max' on platforms where `-cpu host' is not available.

`-cpu max' enables all features supported by the accelerator in the
current host.

This avoid falling back to a default qemu64 CPU that then ends up in not
honoring accelerator in qemu.Cmdline().

--- pkg/limayaml/defaults.go.orig	2022-06-19 02:01:22.000000000 +0000
+++ pkg/limayaml/defaults.go
@@ -108,6 +108,8 @@ func FillDefault(y, d, o *LimaYAML, file
 		if IsNativeArch(arch) && IsAccelOS() {
 			if HasHostCPU() {
 				cpuType[arch] = "host"
+			} else {
+				cpuType[arch] = "max"
 			}
 		}
 	}
