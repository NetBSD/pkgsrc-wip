$NetBSD$

Use siginfo_t instead of struct siginfo, which may be a union.

--- lib/diagnostics.cpp.orig	2016-02-22 14:20:58.000000000 +0000
+++ lib/diagnostics.cpp
@@ -751,7 +751,7 @@ static char *xtoa(size_t x) {
 #endif
 
 #ifdef HAVE_SIGACTION
-void boinc_catch_signal(int signal, struct siginfo *siginfo, void *sigcontext) {
+void boinc_catch_signal(int signal, siginfo_t *siginfo, void *sigcontext) {
 #else
 void boinc_catch_signal(int signal) {
 #endif
