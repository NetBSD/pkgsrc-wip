$NetBSD$

Use siginfo_t instead of struct siginfo, which may be a union.

--- lib/diagnostics.cpp.orig	2017-01-23 01:26:42.000000000 +0000
+++ lib/diagnostics.cpp
@@ -754,7 +754,7 @@ static char *xtoa(size_t x) {
 #ifdef ANDROID
 void boinc_catch_signal(int signal, struct siginfo *siginfo, void *sigcontext) {
 #else
-void boinc_catch_signal(int signal, struct siginfo *, void *) {
+void boinc_catch_signal(int signal, siginfo_t *, void *) {
 #endif  // ANDROID
 #else
 void boinc_catch_signal(int signal) {
