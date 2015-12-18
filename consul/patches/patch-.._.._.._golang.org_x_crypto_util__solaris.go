$NetBSD$

Rudimentary SunOS support based on community patches by @MerlinDMC.

https://github.com/hashicorp/consul/issues/159

--- ../../../golang.org/x/crypto/ssh/terminal/util_solaris.go.orig	2015-12-17 13:38:55.387411381 +0000
+++ ../../../golang.org/x/crypto/ssh/terminal/util_solaris.go
@@ -0,0 +1,86 @@
+// Copyright 2011 The Go Authors. All rights reserved.
+// Use of this source code is governed by a BSD-style
+// license that can be found in the LICENSE file.
+
+// +build solaris
+
+// Package terminal provides support functions for dealing with terminals, as
+// commonly found on UNIX systems.
+//
+// Putting a terminal into raw mode is the most common requirement:
+//
+//     oldState, err := terminal.MakeRaw(0)
+//     if err != nil {
+//             panic(err)
+//     }
+//     defer terminal.Restore(0, oldState)
+package terminal // import "golang.org/x/crypto/ssh/terminal"
+
+import (
+       "fmt"
+       "io"
+       "syscall"
+)
+
+// State contains the state of a terminal.
+type State struct {
+       termios syscall.Termios
+}
+
+// IsTerminal returns true if the given file descriptor is a terminal.
+func IsTerminal(fd int) bool {
+       return false
+}
+
+// MakeRaw put the terminal connected to the given file descriptor into raw
+// mode and returns the previous state of the terminal so that it can be
+// restored.
+func MakeRaw(fd int) (*State, error) {
+       return nil, fmt.Errorf("unsupported")
+}
+
+// GetState returns the current state of a terminal which may be useful to
+// restore the terminal after a signal.
+func GetState(fd int) (*State, error) {
+       return nil, fmt.Errorf("unsupported")
+}
+
+// Restore restores the terminal connected to the given file descriptor to a
+// previous state.
+func Restore(fd int, state *State) error {
+       return fmt.Errorf("unsupported")
+}
+
+// GetSize returns the dimensions of the given terminal.
+func GetSize(fd int) (width, height int, err error) {
+       return 0, 0, fmt.Errorf("unsupported")
+}
+
+// ReadPassword reads a line of input from a terminal without local echo.  This
+// is commonly used for inputting passwords and other sensitive data. The slice
+// returned does not include the \n.
+func ReadPassword(fd int) ([]byte, error) {
+       var buf [16]byte
+       var ret []byte
+       for {
+               n, err := syscall.Read(fd, buf[:])
+               if err != nil {
+                       return nil, err
+               }
+               if n == 0 {
+                       if len(ret) == 0 {
+                               return nil, io.EOF
+                       }
+                       break
+               }
+               if buf[n-1] == '\n' {
+                       n--
+               }
+               ret = append(ret, buf[:n]...)
+               if n < len(buf) {
+                       break
+               }
+       }
+
+       return ret, nil
+}
