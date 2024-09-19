$NetBSD$

Add support for NetBSD.

FIXME: This is a complete copypasto of virtualbox_{free,open}bsd.go and they
FIXME: should be probably unified in a single virtualbox_bsd.go file instead
FIXME: of keeping 3 copies around.

--- drivers/virtualbox/virtualbox_netbsd.go.orig	2021-07-17 11:49:06.626017745 +0000
+++ drivers/virtualbox/virtualbox_netbsd.go
@@ -0,0 +1,13 @@
+package virtualbox
+
+func detectVBoxManageCmd() string {
+	return detectVBoxManageCmdInPath()
+}
+
+func getShareDriveAndName() (string, string) {
+	return "hosthome", "/home"
+}
+
+func isHyperVInstalled() bool {
+	return false
+}
