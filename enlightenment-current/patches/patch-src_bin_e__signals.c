$NetBSD$
Unsupported Signal on Non Linux Systems

--- src/bin/e_signals.c.orig	2025-04-19 01:41:14.744630370 +0000
+++ src/bin/e_signals.c
@@ -107,8 +107,8 @@ _e_siginfo(int sig, siginfo_t *info)
       NAME(SEGV_ACCERR);
 #ifdef __linux__
       NAME(SEGV_BNDERR);
-#endif
       NAME(SEGV_PKUERR);
+#endif
       NUMX(info->si_code);
     } break;
    case SIGILL:
