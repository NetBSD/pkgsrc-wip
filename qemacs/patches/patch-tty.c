$NetBSD$

--- tty.c.orig	2023-03-09 11:57:59.000000000 +0000
+++ tty.c
@@ -87,7 +87,7 @@ typedef uint32_t TTYChar;
 
 #if defined(CONFIG_UNLOCKIO)
 #  define TTY_PUTC(c,f)         putc_unlocked(c, f)
-#ifdef CONFIG_DARWIN
+#if defined(CONFIG_DARWIN) || defined(__NetBSD__)
 #  define TTY_FWRITE(b,s,n,f)   fwrite(b, s, n, f)
 #else
 #  define TTY_FWRITE(b,s,n,f)   fwrite_unlocked(b, s, n, f)
