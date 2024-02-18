$NetBSD$

--- sync/sync_netbsd.go.orig	2024-02-18 02:01:15.283417425 +0000
+++ sync/sync_netbsd.go
@@ -0,0 +1,114 @@
+//
+// This file is part of serial-discovery.
+//
+// Copyright 2018-2021 ARDUINO SA (http://www.arduino.cc/)
+//
+// This software is released under the GNU General Public License version 3,
+// which covers the main part of arduino-cli.
+// The terms of this license can be found at:
+// https://www.gnu.org/licenses/gpl-3.0.en.html
+//
+// You can be released from the requirements of the above licenses by purchasing
+// a commercial license. Buying such a license is mandatory if you want to modify or
+// otherwise use the software for commercial activities involving the Arduino
+// software without disclosing the source code of your own applications. To purchase
+// a commercial license, send an email to license@arduino.cc.
+//
+
+package sync
+
+import (
+	"fmt"
+	"syscall"
+
+	discovery "github.com/arduino/pluggable-discovery-protocol-handler/v2"
+	"go.bug.st/serial/enumerator"
+)
+
+// Start the sync process, successful events will be passed to eventCB, errors to errorCB.
+// Returns a channel used to stop the sync process.
+// Returns error if sync process can't be started.
+func Start(eventCB discovery.EventCallback, errorCB discovery.ErrorCallback) (chan<- bool, error) {
+	// create kqueue
+	kq, err := syscall.Kqueue()
+	if err != nil {
+		return nil, err
+	}
+
+	// open folder
+	fd, err := syscall.Open("/dev", syscall.O_RDONLY, 0)
+	if err != nil {
+		return nil, err
+	}
+
+	// build kevent
+	ev1 := syscall.Kevent_t{
+		Ident:  uint64(fd),
+		Filter: syscall.EVFILT_VNODE,
+		Flags:  syscall.EV_ADD | syscall.EV_ENABLE | syscall.EV_ONESHOT,
+		Fflags: syscall.NOTE_DELETE | syscall.NOTE_WRITE,
+		Data:   0,
+		Udata:  0,
+	}
+
+	// Run synchronous event emitter
+	closeChan := make(chan bool)
+
+	go func() {
+		defer syscall.Close(fd)
+		defer syscall.Close(kq)
+
+		// Output initial port state: get the current port list to send as initial "add" events
+		current, err := enumerator.GetDetailedPortsList()
+		if err != nil {
+			errorCB(err.Error())
+			return
+		}
+		for _, port := range current {
+			eventCB("add", toDiscoveryPort(port))
+		}
+
+		// wait for events
+		events := make([]syscall.Kevent_t, 10)
+
+		for {
+			t100ms := syscall.Timespec{Nsec: 100_000_000, Sec: 0}
+			n, err := syscall.Kevent(kq, []syscall.Kevent_t{ev1}, events, &t100ms)
+			select {
+			case <-closeChan:
+				return
+			default:
+			}
+			if err == syscall.EINTR {
+				continue
+			}
+			if err != nil {
+				errorCB(fmt.Sprintf("Error decoding serial event: %s", err))
+				break
+			}
+			if n <= 0 {
+				continue
+			}
+
+			// if there is an event retry up to 5 times
+			var enumeratorErr error
+			for retries := 0; retries < 5; retries++ {
+				updates, err := enumerator.GetDetailedPortsList()
+				if err != nil {
+					enumeratorErr = err
+					break
+				}
+				processUpdates(current, updates, eventCB)
+				current = updates
+			}
+			if enumeratorErr != nil {
+				errorCB(fmt.Sprintf("Error enumerating serial ports: %s", enumeratorErr))
+				break
+			}
+		}
+
+		<-closeChan
+	}()
+
+	return closeChan, nil
+}
