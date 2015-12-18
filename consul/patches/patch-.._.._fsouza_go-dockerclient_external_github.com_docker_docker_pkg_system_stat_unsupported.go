$NetBSD$

Rudimentary SunOS support based on community patches by @MerlinDMC.

https://github.com/hashicorp/consul/issues/159

--- ../../fsouza/go-dockerclient/external/github.com/docker/docker/pkg/system/stat_unsupported.go.orig	2015-12-17 12:38:21.000000000 +0000
+++ ../../fsouza/go-dockerclient/external/github.com/docker/docker/pkg/system/stat_unsupported.go
@@ -1,4 +1,4 @@
-// +build !linux,!windows,!freebsd
+// +build !linux,!windows,!freebsd,!solaris
 
 package system
 
