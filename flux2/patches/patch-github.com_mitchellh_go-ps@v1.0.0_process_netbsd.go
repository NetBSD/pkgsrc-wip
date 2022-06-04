$NetBSD$

Add NetBSD support via mount_procfs(8)

Shared upstream via:

 <https://github.com/mitchellh/go-ps/pull/59>

--- ../github.com/mitchellh/go-ps@v1.0.0/process_netbsd.go.orig	2022-06-04 19:21:32.628723060 +0000
+++ ../github.com/mitchellh/go-ps@v1.0.0/process_netbsd.go
@@ -0,0 +1,35 @@
+// +build netbsd
+
+package ps
+
+import (
+	"fmt"
+	"io/ioutil"
+	"strings"
+)
+
+// Refresh reloads all the data associated with this process.
+func (p *UnixProcess) Refresh() error {
+	statPath := fmt.Sprintf("/proc/%d/stat", p.pid)
+	dataBytes, err := ioutil.ReadFile(statPath)
+	if err != nil {
+		return err
+	}
+
+	// First, parse out the image name
+	data := string(dataBytes)
+	binStart := strings.IndexRune(data, '(') + 1
+	binEnd := strings.IndexRune(data[binStart:], ')')
+	p.binary = data[binStart : binStart+binEnd]
+
+	// Move past the image name and start parsing the rest
+	data = data[binStart+binEnd+2:]
+	_, err = fmt.Sscanf(data,
+		"%c %d %d %d",
+		&p.state,
+		&p.ppid,
+		&p.pgrp,
+		&p.sid)
+
+	return err
+}
