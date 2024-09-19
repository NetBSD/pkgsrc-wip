$NetBSD$

Add support for NetBSD.

FIXME: This is a complete copypasto of os_{free,open}bsd.go and they should be
FIXME: probably unified in a single os_bsd.go file instead of keeping 3 copies
FIXME: around.

--- libmachine/crashreport/os_netbsd.go.orig	2021-07-17 11:49:21.651863398 +0000
+++ libmachine/crashreport/os_netbsd.go
@@ -0,0 +1,12 @@
+package crashreport
+
+import "os/exec"
+
+func localOSVersion() string {
+	command := exec.Command("uname", "-r")
+	output, err := command.Output()
+	if err != nil {
+		return ""
+	}
+	return string(output)
+}
