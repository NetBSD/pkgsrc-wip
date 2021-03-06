$NetBSD$

Add missing <sys/select.h> inclusion.

--- lib/the_Foundation/src/platform/posix/process.c.orig	2021-02-27 17:21:33.000000000 +0000
+++ lib/the_Foundation/src/platform/posix/process.c
@@ -38,6 +38,7 @@ SOFTWARE, EVEN IF ADVISED OF THE POSSIBI
 #include <poll.h>
 #include <unistd.h>
 #include <signal.h>
+#include <sys/select.h>
 #include <sys/wait.h>
 
 struct Impl_Process {
