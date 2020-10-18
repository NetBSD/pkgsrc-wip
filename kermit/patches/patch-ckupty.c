$NetBSD: patch-ckupty.c,v 1.1 2015/11/07 23:20:59 dholland Exp $

Always use termios, never sgtty.h.
\todo Explain this more clearly.

This patch appears to be regularizing the use of TERMIO, following the
package's inclusion of mk/termcap.buildlink3.mk.  This is contrary to
upstream's approach which uses each systems's native libs.  Therefore,
this patch should not be submitted to upstream.

--- ckupty.c~	2011-06-13 15:34:13.000000000 +0000
+++ ckupty.c
@@ -79,33 +79,7 @@ char * ptyver = "PTY support 8.0.016, 22
 #endif	/* SUNOS41 */
 
 #ifndef USE_TERMIO
-#ifdef LINUX
-#define USE_TERMIO
-#else
-#ifdef ATTSV
-#define USE_TERMIO
-#else
-#ifdef HPUX
-#define USE_TERMIO
-#else
-#ifdef AIX
-#define USE_TERMIO
-#else
-#ifdef BSD44ORPOSIX
 #define USE_TERMIO
-#else
-#ifdef IRIX60
-#define USE_TERMIO
-#else
-#ifdef QNX
-#define USE_TERMIO
-#endif /* QNX */
-#endif /* IRIX60 */
-#endif /* BSD44ORPOSIX */
-#endif /* AIX */
-#endif /* HPUX */
-#endif /* ATTSV */
-#endif /* LINUX */
 #endif /* USE_TERMIO */
 
 #ifdef QNX
