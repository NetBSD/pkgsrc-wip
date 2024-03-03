$NetBSD$

Remove non-portable use of WCHAR_T in iconv code.
Fix comment's alignment.

--- yasr/tts.c.orig	2023-04-08 21:22:57.000000000 +0000
+++ yasr/tts.c
@@ -412,7 +412,6 @@ tts_out_w (wchar_t *buf, int len)
   char *p;
   int i;
   int xml = 0;			/* what's this? */
-
   if (!len)
     return;
   if (tts.synth == TTS_SPEECHD)
@@ -674,21 +673,22 @@ tts_saychar (wchar_t ch)
       tts_printf_ll ("CHAR %c\r\n", ch);
 #else
     else if (ch < 0x80)
-    {
       tts_printf_ll ("CHAR %c\r\n", ch);
-    }
     else
     {
-      char buf[8], *cin, *cout;
+      char tmpbuf[MB_CUR_MAX], buf[MB_CUR_MAX], *cin, *cout;
       size_t l1, l2;
       iconv_t cd;
-      cd = iconv_open ("UTF-8", "WCHAR_T");
+      cd = iconv_open ("UTF-8", nl_langinfo (CODESET));
       if (cd == (iconv_t) - 1)
 	return;
-      l1 = sizeof (wchar_t);
-      l2 = 7;
-      cin = (char *) &ch;
+      l1 = wctomb (tmpbuf, ch);
+      if (l1 == -1)
+	return;
+      l2 = sizeof (buf) - 1;
+      cin = tmpbuf;
       cout = buf;
+      
       iconv (cd, &cin, &l1, &cout, &l2);
       iconv_close (cd);
       *cout = 0;
@@ -704,7 +704,8 @@ tts_saychar (wchar_t ch)
     return;
   }
   if (!synth[tts.synth].charoff)
-  {				/* assume on string does everything */
+  {
+    /* assume on string does everything */
     (void) sprintf (ttsbuf, synth[tts.synth].charon, ch);
     tts_send (ttsbuf, strlen (ttsbuf));
     return;
