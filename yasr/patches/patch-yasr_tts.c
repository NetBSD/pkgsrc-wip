$NetBSD: patch-yasr_tts.c,v 1.1 2024/03/11 07:52:38 wiz Exp $

Remove non-portable use of WCHAR_T in iconv code.
Fix comment's alignment.

--- yasr/tts.c.orig	2026-08-05 17:05:38.000000000 +0000
+++ yasr/tts.c
@@ -55,7 +55,8 @@ static Tts_synth synth[] = {
   {NULL, NULL, NULL, NULL, NULL, FALSE, NULL, NULL},
 };
 
-static char *dict[256];
+#define DICT_SIZE 256
+static char *dict[DICT_SIZE];
 static int tts_flushed = 0;
 
 
@@ -69,9 +70,7 @@ dict_read (char *buf)
   {
     c = strtol (buf, &p, 0);
     if (c > 255)
-    {
       return (1);
-    }
     p++;
   }
   else
@@ -90,20 +89,14 @@ dict_write (FILE * fp)
 {
   int i;
 
-  for (i = 0; i < 256; i++)
-  {
+  for (i = 0; i < DICT_SIZE; i++)
     if (dict[i])
     {
       if (i > 31 && i < 127 && i != 35 && i != 91)
-      {
-	(void) fprintf (fp, "%c=%s\n", i, dict[i]);
-      }
+        (void) fprintf (fp, "%c=%s\n", i, dict[i]);
       else
-      {
-	(void) fprintf (fp, "0x%.2x=%s\n", i, dict[i]);
-      }
+        (void) fprintf (fp, "0x%.2x=%s\n", i, dict[i]);
     }
-  }
 }
 
 
@@ -113,9 +106,7 @@ tts_flush ()
 tts_flush ()
 {
   if (tts.outlen)
-  {
     w_speak (tts.buf, tts.outlen);
-  }
 
   tts.outlen = 0;
 
@@ -130,9 +121,7 @@ tts_wait (int usecs)
   if (usecs != -1 && !readable (tts.fd, usecs))
     return;
   while (readable (tts.fd, 0))
-  {
     read (tts.fd, buf, sizeof (buf));
-  }
 }
 #endif
 
@@ -142,9 +131,7 @@ tts_silence ()
   char tmp[1] = { 0 };
 
   if (tts_flushed)
-  {
     return;
-  }
   tts.obufhead = tts.obuftail = tts.flood = 0;
 #ifdef ENABLE_SPEECHD
   if (tts.synth == TTS_SPEECHD)
@@ -209,17 +196,13 @@ tts_obufout (int x)
   int oldoflag;
 
   if (!tts.flood)
-  {
     opt_queue_empty (2);
-  }
   oldoflag = tts.oflag;
   while (tts.obufhead < tts.obuftail)
   {
     len = strlen (tts.obuf + tts.obufhead);
     if (len > 1024)
-    {
       len = 1024;
-    }
     len2 = write (tts.fd, tts.obuf + tts.obufhead, len);
 #ifdef TTSLOG
     (void) write (ofd, tts.obuf + tts.obufhead, len2);
@@ -234,9 +217,7 @@ tts_obufout (int x)
       return;
     }
     while (tts.obufhead < tts.obuftail && !tts.obuf[tts.obufhead])
-    {
       tts.obufhead++;
-    }
   }
   tts.flood = 0;
   tts.oflag = oldoflag;
@@ -251,9 +232,7 @@ tts_addbuf (char *buf, int len, int len2)
 
   tts.flood = 1;
   if (len2 == -1)
-  {
     ptr = buf;
-  }
   else
   {
     ptr = buf + len2;
@@ -267,9 +246,7 @@ tts_addbuf (char *buf, int len, int len2)
       tts.obuf = realloc (tts.obuf, tts.obuflen);
     }
     else
-    {
       tts_obufpack ();
-    }
   }
   (void) memcpy (tts.obuf + tts.obuftail, ptr, len);
   tts.obuftail += len;
@@ -285,13 +262,9 @@ tts_send (char *buf, int len)
   int len2;
 
   if (!len)
-  {
     return;
-  }
   if (tts_flushed)
-  {
     tts_flushed = 0;
-  }
 #ifndef SILENT
   if (!tts.flood)
   {
@@ -302,9 +275,7 @@ tts_send (char *buf, int len)
 #endif
 
     if (len2 < len)
-    {
       tts_addbuf (buf, len, len2);
-    }
   }
   else
     tts_addbuf (buf, len, 0);
@@ -327,10 +298,8 @@ unspeakable (unsigned char ch)
   if (ch < 32)
     return 1;
   while (*p)
-  {
     if (*p++ == ch)
       return 1;
-  }
   return (0);
 }
 
@@ -438,26 +407,24 @@ tts_out_w (wchar_t *buf, int len)
     while (len > 0)
     {
       if (*buf < 0x80)
-      {
-	obuf[obo++] = *buf;
-      }
+        obuf[obo++] = *buf;
       else if (*buf < 0x800)
       {
-	obuf[obo++] = 0xc0 | (*buf >> 6);
-	obuf[obo++] = 0x80 | (*buf & 0x3f);
+        obuf[obo++] = 0xc0 | (*buf >> 6);
+        obuf[obo++] = 0x80 | (*buf & 0x3f);
       }
       else if (*buf < 0x10000)
       {
-	obuf[obo++] = 0xe0 | (*buf >> 12);
-	obuf[obo++] = 0x80 | ((*buf >> 6) & 0x3f);
-	obuf[obo++] = 0x80 | (*buf & 0x3f);
+        obuf[obo++] = 0xe0 | (*buf >> 12);
+        obuf[obo++] = 0x80 | ((*buf >> 6) & 0x3f);
+        obuf[obo++] = 0x80 | (*buf & 0x3f);
       }
       else
-	obuf[obo++] = ' ';
+        obuf[obo++] = ' ';
       if (obo >= 1020)
       {
-	tts_out ((unsigned char *) obuf, obo);
-	obo = 0;
+        tts_out ((unsigned char *) obuf, obo);
+        obo = 0;
       }
       buf++;
       len--;
@@ -478,63 +445,61 @@ tts_out_w (wchar_t *buf, int len)
       p++;
       for (i = 0; i < len; i++)
       {
-	if (buf[i] > 255 || unspeakable ((unsigned char) buf[i]))
-	{
-	  if (obo > 0 && obuf[obo - 1] != ' ')
-	  {
-	    obuf[obo++] = ' ';
-	    tts_send (obuf, obo);
-	    obo = 0;
-	  }
-	  else if (buf[i] < 256 && dict[buf[i]])
-	  {
-	    (void) strcpy (obuf + obo, dict[buf[i]]);
-	    obo = strlen (obuf);
-	  }
-	  obuf[obo++] = 32;
-	}
-	else if (xml)
-	{
-	  switch (buf[i])
-	  {
-	    /* For some reason, &lt; does not work for me with Voxeo */
-	  case '<':
-	    strcpy (obuf + obo, " less than ");
-	    obo += 11;
-	    break;
-	  case '>':
-	    strcpy (obuf + obo, "&gt;");
-	    obo += 4;
-	    break;
-	  case '&':
-	    strcpy (obuf + obo, "&amp;");
-	    obo += 5;
-	    break;
-	  default:
-	    obuf[obo++] = buf[i];
-	    break;
-	  }
-	}
-	else
-	{
-	  if (ui.split_caps && i > 0 && iswlower (buf[i - 1])
-	      && iswupper (buf[i]))
-	  {
-	    obuf[obo++] = ' ';
-	  }
-	  obuf[obo++] = buf[i];
-	}
-	if (obo > (sizeof (obuf) / sizeof (obuf[0])) - 6)
-	{
-	  tts_send (obuf, obo);
-	  obo = 0;
-	}
+        if (buf[i] > 255 || unspeakable ((unsigned char) buf[i]))
+        {
+          if (obo > 0 && obuf[obo - 1] != ' ')
+          {
+            obuf[obo++] = ' ';
+            tts_send (obuf, obo);
+            obo = 0;
+          }
+          else if (buf[i] < 256 && dict[buf[i]])
+          {
+            (void) strcpy (obuf + obo, dict[buf[i]]);
+            obo = strlen (obuf);
+          }
+          obuf[obo++] = 32;
+        }
+        else if (xml)
+        {
+          switch (buf[i])
+          {
+            /* For some reason, &lt; does not work for me with Voxeo */
+          case '<':
+            strcpy (obuf + obo, " less than ");
+            obo += 11;
+            break;
+          case '>':
+            strcpy (obuf + obo, "&gt;");
+            obo += 4;
+            break;
+          case '&':
+            strcpy (obuf + obo, "&amp;");
+            obo += 5;
+            break;
+          default:
+            obuf[obo++] = buf[i];
+            break;
+          }
+        }
+        else
+        {
+          if (ui.split_caps && i > 0 && iswlower (buf[i - 1])
+              && iswupper (buf[i]))
+          {
+            obuf[obo++] = ' ';
+          }
+          obuf[obo++] = buf[i];
+        }
+        if (obo > (sizeof (obuf) / sizeof (obuf[0])) - 6)
+        {
+          tts_send (obuf, obo);
+          obo = 0;
+        }
       }
     }
     else
-    {
       obuf[obo++] = *p;
-    }
     p++;
   }
   tts_send (obuf, obo);
@@ -678,9 +643,7 @@ tts_saychar (wchar_t ch)
 #endif
 
   if (!ch)
-  {
     ch = 32;
-  }
   if (tts.synth == TTS_SPEECHD || tts.synth == TTS_MAC)
   {
 #if defined(ENABLE_SPEECHD) || defined(__APPLE__)
@@ -700,21 +663,22 @@ tts_saychar (wchar_t ch)
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
-	return;
-      l1 = sizeof (wchar_t);
-      l2 = 7;
-      cin = (char *) &ch;
+        return;
+      l1 = wctomb (tmpbuf, ch);
+      if (l1 == -1)
+        return;
+      l2 = sizeof (buf) - 1;
+      cin = tmpbuf;
       cout = buf;
+
       iconv (cd, &cin, &l1, &cout, &l2);
       iconv_close (cd);
       *cout = 0;
@@ -730,7 +694,8 @@ tts_saychar (wchar_t ch)
     return;
   }
   if (!synth[tts.synth].charoff)
-  {				/* assume on string does everything */
+  {
+    /* assume on string does everything */
     (void) sprintf (ttsbuf, synth[tts.synth].charon, ch);
     tts_send (ttsbuf, strlen (ttsbuf));
     return;
@@ -751,9 +716,7 @@ tts_saychar (wchar_t ch)
   ttsbuf[0] = ch;
   tts_send (ttsbuf, 1);
   if (synth[tts.synth].saychar_needs_flush)
-  {
     tts_send (synth[tts.synth].say + 2, strlen (synth[tts.synth].say) - 2);
-  }
   while (j)
   {
     j -= 2;
@@ -913,9 +876,7 @@ tts_init (int first_call)
 #ifdef TTSLOG
   ofd = open ("tts.log", O_WRONLY | O_CREAT);
   if (ofd == -1)
-  {
     perror ("open");
-  }
 #endif
 
 #ifdef ENABLE_SPEECHD
@@ -954,17 +915,11 @@ tts_init (int first_call)
   else if (tts.port[0] != '|')
   {
     if (tts.synth == TTS_DECTALK)
-    {
       mode = O_NOCTTY | O_RDWR;
-    }
     else if (tts.synth == TTS_EMACSPEAK_SERVER)
-    {
       mode = O_WRONLY;
-    }
     if (first_call)
-    {
       tts.fd = open (portname, mode);
-    }
     if (tts.fd == -1)
     {
       perror ("tts");
@@ -992,21 +947,15 @@ tts_init (int first_call)
     (void) strcpy (buf, tts.port + 1);
     arg[i = 0] = strtok (buf, " ");
     while (i < 7)
-    {
       if (!(arg[++i] = strtok (NULL, " ")))
-      {
-	break;
-      }
-    }
+        break;
 
     if (first_call)
-    {
       if (openpty (&tts.fd, &tts.fd_slave, NULL, NULL, NULL) == -1)
       {
-	perror ("openpty");
-	exit (1);
+        perror ("openpty");
+        exit (1);
       }
-    }
 
     if (!(tts.pid = fork ()))
     {
@@ -1023,9 +972,7 @@ tts_init (int first_call)
     }
     (void) usleep (10000);
     if (tts.pid == -1)
-    {
       perror ("forkpty");
-    }
   }
   if (tts.synth == TTS_SPEECHD)
   {
@@ -1077,10 +1024,8 @@ tts_addchr (wchar_t ch)
 tts_addchr (wchar_t ch)
 {
   tts.buf[tts.outlen++] = ch;
-  if (tts.outlen > 250)
-  {
+  if (tts.outlen > TTS_BUF_SIZE)
     tts_flush ();
-  }
 }
 
 
@@ -1099,9 +1044,7 @@ tts_initsynth (int *argp)
     }
   }
   if (!ui.silent)
-  {
     tts_say (_("Synthesizer reinitialized."));
-  }
 }
 
 
@@ -1112,9 +1055,7 @@ tts_reinit (int *argp)
   int pid = tts.pid;
 
   if (pid == 0)
-  {
     return;
-  }
 
   tts.reinit = 1;		/* Start reinit */
 
@@ -1124,20 +1065,14 @@ tts_reinit (int *argp)
   if (kill (pid, SIGTERM) != 0)
   {
     if (errno == ESRCH)
-    {
       tts_reinit2 ();
-    }
     else
-    {
       kill (pid, SIGKILL);
-    }
   }
 
   /* wait init completion (tts.fd must be available) */
   while (tts.reinit)
-  {
     usleep (100000);
-  }
 }
 
 
