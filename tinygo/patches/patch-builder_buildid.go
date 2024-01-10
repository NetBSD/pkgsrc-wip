$NetBSD$

add NetBSD support

--- builder/buildid.go.orig	2024-01-09 20:26:56.002399163 +0000
+++ builder/buildid.go
@@ -24,7 +24,7 @@ func ReadBuildID() ([]byte, error) {
 	defer f.Close()
 
 	switch runtime.GOOS {
-	case "linux", "freebsd", "android":
+	case "linux", "freebsd", "android", "netbsd":
 		// Read the GNU build id section. (Not sure about FreeBSD though...)
 		file, err := elf.NewFile(f)
 		if err != nil {
