$NetBSD$

Use siginfo_t instead of struct siginfo, which may be a union.

--- lib/diagnostics.cpp.orig	2017-12-06 20:02:16.929507800 +0000
+++ lib/diagnostics.cpp
@@ -756,7 +756,7 @@ static char *xtoa(size_t x) {
 #ifdef ANDROID_VOODOO
 void boinc_catch_signal(int signal, struct siginfo *siginfo, void *sigcontext) {
 #else
-void boinc_catch_signal(int signal, struct siginfo *, void *) {
+void boinc_catch_signal(int signal, siginfo_t *, void *) {
 #endif  // ANDROID
 #else
 void boinc_catch_signal(int signal) {
