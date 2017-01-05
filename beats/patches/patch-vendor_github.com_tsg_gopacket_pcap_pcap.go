$NetBSD$

Just require pcap, fixes NetBSD.

--- vendor/github.com/tsg/gopacket/pcap/pcap.go.orig	2016-12-06 07:41:08.000000000 +0000
+++ vendor/github.com/tsg/gopacket/pcap/pcap.go
@@ -8,14 +8,7 @@
 package pcap
 
 /*
-#cgo linux LDFLAGS: -lpcap
-#cgo freebsd LDFLAGS: -lpcap
-#cgo openbsd LDFLAGS: -lpcap
-#cgo darwin LDFLAGS: -lpcap
-#cgo solaris LDFLAGS: -lpcap
-#cgo windows CFLAGS: -I C:/WpdPack/Include
-#cgo windows,386 LDFLAGS: -L C:/WpdPack/Lib -lwpcap
-#cgo windows,amd64 LDFLAGS: -L C:/WpdPack/Lib/x64 -lwpcap
+#cgo LDFLAGS: -lpcap
 #include <stdlib.h>
 #include <pcap.h>
 
