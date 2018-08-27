$NetBSD$

--- vendor/golang.org/x/sys/unix/zsyscall_solaris_amd64.go.orig	2018-08-10 17:16:53.000000000 +0000
+++ vendor/golang.org/x/sys/unix/zsyscall_solaris_amd64.go
@@ -70,6 +70,7 @@ import (
 //go:cgo_import_dynamic libc_mlock mlock "libc.so"
 //go:cgo_import_dynamic libc_mlockall mlockall "libc.so"
 //go:cgo_import_dynamic libc_mprotect mprotect "libc.so"
+//go:cgo_import_dynamic libc_msync msync "libc.so"
 //go:cgo_import_dynamic libc_munlock munlock "libc.so"
 //go:cgo_import_dynamic libc_munlockall munlockall "libc.so"
 //go:cgo_import_dynamic libc_nanosleep nanosleep "libc.so"
@@ -185,6 +186,7 @@ import (
 //go:linkname procMlock libc_mlock
 //go:linkname procMlockall libc_mlockall
 //go:linkname procMprotect libc_mprotect
+//go:linkname procMsync libc_msync
 //go:linkname procMunlock libc_munlock
 //go:linkname procMunlockall libc_munlockall
 //go:linkname procNanosleep libc_nanosleep
@@ -301,6 +303,7 @@ var (
 	procMlock,
 	procMlockall,
 	procMprotect,
+	procMsync,
 	procMunlock,
 	procMunlockall,
 	procNanosleep,
@@ -972,6 +975,18 @@ func Mprotect(b []byte, prot int) (err e
 	if e1 != 0 {
 		err = e1
 	}
+	return
+}
+
+func Msync(b []byte, flags int) (err error) {
+	var _p0 *byte
+	if len(b) > 0 {
+		_p0 = &b[0]
+	}
+	_, _, e1 := sysvicall6(uintptr(unsafe.Pointer(&procMsync)), 3, uintptr(unsafe.Pointer(_p0)), uintptr(len(b)), uintptr(flags), 0, 0, 0)
+	if e1 != 0 {
+		err = e1
+	}
 	return
 }
 
