$NetBSD$

Unsupported Signal (SEGV_PKUERR) under NetBSD.
Merged upstream: https://git.enlightenment.org/enlightenment/enlightenment/pulls/139
Works under FreeBSD according to the discussion as found in the above PR.

--- src/bin/e_signals.c.orig	2025-03-17 17:18:54.000000000 +0000
+++ src/bin/e_signals.c
@@ -108,7 +108,9 @@ _e_siginfo(int sig, siginfo_t *info)
 #ifdef __linux__
       NAME(SEGV_BNDERR);
 #endif
+#ifndef __NetBSD__
       NAME(SEGV_PKUERR);
+#endif
       NUMX(info->si_code);
     } break;
    case SIGILL:
