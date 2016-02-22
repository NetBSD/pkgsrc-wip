$NetBSD$

Use siginfo_t instead of struct siginfo, which may be a union.

--- lib/diagnostics.h.orig	2016-02-22 14:20:58.000000000 +0000
+++ lib/diagnostics.h
@@ -124,8 +124,8 @@ extern UINT WINAPI diagnostics_unhandled
 extern LONG CALLBACK boinc_catch_signal(EXCEPTION_POINTERS *ExceptionInfo);
 #else
 #ifdef HAVE_SIGACTION
-typedef void (*handler_t)(int, struct siginfo *, void *);
-extern void boinc_catch_signal(int signal, struct siginfo *siginfo, void *sigcontext);
+typedef void (*handler_t)(int, siginfo_t *, void *);
+extern void boinc_catch_signal(int signal, siginfo_t *siginfo, void *sigcontext);
 #else
 typedef void (*handler_t)(int);
 extern void boinc_catch_signal(int signal);
