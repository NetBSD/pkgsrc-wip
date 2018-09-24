$NetBSD$

Remove unportable tests from category "posix".

--- tests/error.t.orig	2009-10-01 03:16:44.000000000 +0000
+++ tests/error.t
@@ -14,7 +14,7 @@ name: error-2
 description:
 	Check that failure to execute a command returns the proper
 	exit status.
-category: debian,posix
+category: debian
 stdin:
 	TEMPFILE=$(tempfile --prefix posix)
 	chmod 0 $TEMPFILE
@@ -26,7 +26,7 @@ expected-stdout:
 name: error-3
 description:
 	POSIX says that the shell should exit with 126/127 in some situations
-category: debian,posix
+category: debian
 stdin:
 	i=0
 	echo : >x
