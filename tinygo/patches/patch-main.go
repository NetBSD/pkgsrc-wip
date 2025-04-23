$NetBSD$

--- main.go.orig	2025-03-19 06:32:48.000000000 +0000
+++ main.go
@@ -1060,6 +1060,31 @@ func findFATMounts(options *compileopts.
 			})
 		}
 		return points, nil
+	case "netbsd":
+		fmt.Fprintln(os.Stderr, "warning: UF2 flashing on NetBSD is experimental.")
+		fmt.Fprintln(os.Stderr, "         Press the BOOT+RESET buttons and mount the umass device")
+		fmt.Fprintln(os.Stderr, "         on a directory with the correct name, for example:")
+		fmt.Fprintln(os.Stderr, "         mount -t msdos /dev/sd0e /mnt/RPI-RP2")
+		tab, err := os.ReadFile("/proc/mounts")
+		if err != nil {
+			return nil, fmt.Errorf("could not list mount points: %w", err)
+		}
+		for _, line := range strings.Split(string(tab), "\n") {
+			fields := strings.Fields(line)
+			if len(fields) <= 2 {
+				continue
+			}
+			fstype := fields[2]
+			if fstype != "msdos" {
+				continue
+			}
+			points = append(points, mountPoint{
+				name: filepath.Base(fields[1]),
+				path: fields[1],
+			})
+			fmt.Fprintf(os.Stderr, "found: %v\n", fields[1])
+		}
+		return points, nil
 	case "windows":
 		// Obtain a list of all currently mounted volumes.
 		cmd := executeCommand(options, "powershell", "-c",
@@ -1104,6 +1129,8 @@ func getDefaultPort(portFlag string, usb
 	switch runtime.GOOS {
 	case "freebsd":
 		ports, err = filepath.Glob("/dev/cuaU*")
+	case "netbsd":
+		ports, err = filepath.Glob("/dev/ttyU*")
 	case "darwin", "linux", "windows":
 		var portsList []*enumerator.PortDetails
 		portsList, err = enumerator.GetDetailedPortsList()
