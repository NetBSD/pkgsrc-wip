$NetBSD$

* Use correct sysctl to determine physical memory on systems
  with large RAM 
* See also: https://github.com/minio/minio/pull/10907

--- pkg/sys/stats_bsd.go.orig	2020-11-17 00:42:33.825154889 +0000
+++ pkg/sys/stats_bsd.go
@@ -24,7 +24,7 @@ import (
 )
 
 func getHwPhysmem() (uint64, error) {
-	totalString, err := syscall.Sysctl("hw.physmem")
+	totalString, err := syscall.Sysctl("hw.physmem64")
 	if err != nil {
 		return 0, err
 	}
