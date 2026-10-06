$NetBSD$

NetBSD has the same termios and poll(2) helpers as FreeBSD/OpenBSD via
golang.org/x/sys/unix (TIOCGETA/TIOCSETA, IoctlGetTermios/IoctlSetTermios,
PollFd/Poll), so include it in the BSD capabilities build tag.

--- internal/app/capabilities_bsd.go.orig
+++ internal/app/capabilities_bsd.go
@@ -1,1 +1,1 @@
-//go:build freebsd || openbsd
+//go:build freebsd || netbsd || openbsd
