$NetBSD$

--- vendor/golang.org/x/sys/unix/syscall_solaris.go.orig	2018-08-10 17:16:53.000000000 +0000
+++ vendor/golang.org/x/sys/unix/syscall_solaris.go
@@ -611,6 +611,7 @@ func IoctlGetTermio(fd int, req int) (*T
 //sys	Mlock(b []byte) (err error)
 //sys	Mlockall(flags int) (err error)
 //sys	Mprotect(b []byte, prot int) (err error)
+//sys	Msync(b []byte, flags int) (err error)
 //sys	Munlock(b []byte) (err error)
 //sys	Munlockall() (err error)
 //sys	Nanosleep(time *Timespec, leftover *Timespec) (err error)
