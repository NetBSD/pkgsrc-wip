$NetBSD$

Use `-cpu max' instead of `-cpu host' (`-cpu host' seems not supported
at least on NetBSD).

--- pkg/limayaml/defaults.go.orig	2022-05-19 06:28:56.000000000 +0000
+++ pkg/limayaml/defaults.go
@@ -106,7 +106,7 @@ func FillDefault(y, d, o *LimaYAML, file
 	}
 	for arch := range cpuType {
 		if IsNativeArch(arch) {
-			cpuType[arch] = "host"
+			cpuType[arch] = "max"
 		}
 	}
 	for k, v := range d.CPUType {
