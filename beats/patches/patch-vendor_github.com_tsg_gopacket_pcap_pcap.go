$NetBSD$

Add support for SunOS.

--- vendor/github.com/tsg/gopacket/pcap/pcap.go.orig	2015-12-17 14:53:41.000000000 +0000
+++ vendor/github.com/tsg/gopacket/pcap/pcap.go
@@ -11,6 +11,7 @@ package pcap
 #cgo linux LDFLAGS: -lpcap
 #cgo freebsd LDFLAGS: -lpcap
 #cgo darwin LDFLAGS: -lpcap
+#cgo solaris LDFLAGS: -lpcap
 #cgo windows CFLAGS: -I C:/WpdPack/Include
 #cgo windows,386 LDFLAGS: -L C:/WpdPack/Lib -lwpcap
 #cgo windows,amd64 LDFLAGS: -L C:/WpdPack/Lib/x64 -lwpcap
