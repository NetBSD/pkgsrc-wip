$NetBSD: patch-yasr_main.c,v 1.1 2024/03/11 07:52:38 wiz Exp $

Remove non-portable use of WCHAR_T in iconv code.
Remove the enforcing of UTF-8 (but the code is expeting multibyte
encodings or ASCII).
Fix the reading of char after space using right cursor key.
Use defined constants in buffer sizes when they are used elsewhere.
Remove unused argument of gulp().
Fix bug: buf[] used instead of kbuf[].
Fix bug: the reading of master can be truncated even just getting one char at
a time (bug in NetBSD's pty implementation?), the code has to take that
into account.
Simplify formatting now that we are there, but according to the rest of the code.

--- yasr/main.c.orig	2026-08-05 17:05:38.000000000 +0000
+++ yasr/main.c
@@ -42,8 +42,10 @@ char *conffile = NULL;
 static int size, wsize;
 static int master, slave;
 char *conffile = NULL;
-unsigned char buf[256];
-wchar_t wide_buf[256];
+#define BUF_SIZE 256
+#define WIDE_BUF_SIZE 256
+char buf[BUF_SIZE];
+wchar_t wide_buf[WIDE_BUF_SIZE];
 char usershell[OPT_STR_SIZE];
 static struct termios t;
 Win *win;
@@ -53,9 +55,10 @@ static int speaking = 1;
 Ui ui;
 Uirev rev;
 static int speaking = 1;
-int kbuf[100];
+#define KBUF_SIZE 100
+int kbuf[KBUF_SIZE];
 int kbuflen = 0;
-static wchar_t okbuf[100];
+static wchar_t okbuf[KBUF_SIZE];
 static int okbuflen = 0;
 static int oldcr = 0, oldcc = 0, oldch = 0;
 Voices voices;
@@ -311,40 +314,22 @@ getkey_buf ()
 static int
 getkey_buf ()
 {
-  char *b1, *b2;
-  size_t s1, s2;
   wchar_t ch;
   int key;
   int result;
 
-  s1 = size;
-  s2 = sizeof (wchar_t);
-  b1 = (char *) buf;
-  b2 = (char *) &ch;
-  iconv (ih_inp, NULL, NULL, NULL, NULL);
-  result = iconv (ih_inp, &b1, &s1, &b2, &s2);
-  if (result != -1)
-  {
-    if (!s1)
-      return ch;
-  }
+  result = mbtowc(&ch, buf, size);
+  if (result == size && result != -1)
+    return (int)ch;
   key = (int) buf[0];
   if (size > 1)
-  {
     key = (key << 8) + buf[1];
-  }
   if (size > 2)
-  {
     key = (key << 8) + buf[2];
-  }
   if (size > 3)
-  {
     key = (key << 8) + buf[3];
-  }
   if (key >> 8 == 0x1b4f)
-  {
     key += 0x000c00;
-  }
 
   /* Convert high-bit meta keys to escape form */
 #ifndef __linux__
@@ -359,11 +344,9 @@ getinput ()
 {
   int key;
 
-  size = read (0, buf, 255);
+  size = read (0, buf, BUF_SIZE);
   if (size <= 0)
-  {
     finish (0);
-  }
   key = getkey_buf ();
   if (key == ui.disable)
   {
@@ -389,9 +372,7 @@ getinput ()
 
   tts_silence ();
   if (ui.silent == -1)
-  {
     ui.silent = 0;
-  }
   ui.silent = -ui.silent;
   if (ui.meta)
   {
@@ -405,9 +386,7 @@ getinput ()
     okbuflen = tts.oflag = 0;
   }
   if (!ui_keypress (key))
-  {
     (void) write (master, buf, size);
-  }
 }
 
 static void
@@ -422,9 +401,7 @@ wincpy (Win ** d, Win * s)
   (*d)->cc = s->cc;
   (*d)->mode = s->mode;
   for (i = 0; i < s->rows; i++)
-  {
     (void) memcpy ((*d)->row[i], s->row[i], s->cols * CHARSIZE);
-  }
   (void) memcpy (&(*d)->savecp, &s->savecp, sizeof (Curpos));
 }
 
@@ -434,9 +411,7 @@ win_end (Win * win)
   int i;
 
   for (i = 0; i < win->rows; i++)
-  {
     free (win->row[i]);
-  }
   free (win->row);
   free (win->tab);
 }
@@ -454,9 +429,7 @@ win_scrollup ()
   tmpc = win->row[win_scrollmin];
   (void) memset (tmpc, 0, win->cols * CHARSIZE);
   for (i = win_scrollmin; i < win_scrollmax; i++)
-  {
     win->row[i] = win->row[i + 1];
-  }
   win->row[i] = tmpc;
   win->cr--;
 }
@@ -476,9 +449,7 @@ win_lf ()
     tmpc = win->row[win_scrollmin];
     (void) memset (tmpc, 0, win->cols * CHARSIZE);
     for (i = win_scrollmin; i < win_scrollmax; i++)
-    {
       win->row[i] = win->row[i + 1];
-    }
     win->row[i] = tmpc;
     win->cr--;
   }
@@ -494,9 +465,7 @@ win_scrolldown ()
   tmpc = win->row[win_scrollmax];
   (void) memset (tmpc, 0, CHARSIZE * win->cols);
   for (i = win_scrollmax - 1; i >= win->cr; i--)
-  {
     win->row[i + 1] = win->row[i];
-  }
   win->row[win->cr] = tmpc;
 }
 
@@ -537,41 +506,44 @@ oldgulp (unsigned char *buf, int *size, unsigned char 
     if (ep)
     {
       n = buf + *size - *ep;
-      (void) memmove (buf, *ep, 256 - n);
-      *size = n + read (master, buf + n, 255 - n);
+      (void) memmove (buf, *ep, BUF_SIZE - n);
+      *size = n + read (master, buf + n, BUF_SIZE - 1  - n);
       buf[*size] = '\0';
       (void) write (1, buf + n, *size - n);
       *ep = buf;
       return ((char *) buf + n);
     }
-    *size = read (master, buf, 255);
+    *size = read (master, buf, BUF_SIZE - 1);
     buf[*size] = '\0';
     (void) write (1, buf, *size);
     return ((char *) buf);
   }
-  *size += read (master, buf + *size, 255 - *size);
+  *size += read (master, buf + *size, BUF_SIZE - 1 - *size);
   buf[*size] = '\0';
   return ((char *) (buf + os));
 }
 
 #endif
 
-/*!
+/*
 function reads portion of data into buf and converts
 to wide string, leaving 'leave' character in wide_buf;
 */
-static int bytes_left;
+static int bytes_left = 0;
 static char *bytes_left_start;
 static void
 read_buf (int leave)
 {
-  char *b1, *b2;
-  size_t s1, s2;
-  if (bytes_left)
-  {
-    memcpy (buf, bytes_left_start, bytes_left);
+  int mbcharsize;
+  char *mbb;
+  wchar_t *wcb, tmpb[WIDE_BUF_SIZE];
+  size_t mbs;
+
+  if (bytes_left){
+    memcpy (tmpb, bytes_left_start, bytes_left);
+    memcpy (buf, tmpb, bytes_left);
   }
-  size = read (master, buf + bytes_left, 255 - bytes_left - leave);
+  size = read (master, buf + bytes_left, BUF_SIZE - bytes_left - 1);
   if (size < 0)
   {
     perror ("read");
@@ -581,39 +553,43 @@ read_buf (int leave)
   size += bytes_left;
   buf[size] = 0;
   bytes_left = 0;
-  b1 = (char *) buf;
-  b2 = (char *) (wide_buf + leave);
-  if (leave)
-    memcpy (wide_buf, wide_buf + wsize - leave,
-	    sizeof (wchar_t) * (wsize - leave));
-  s1 = size;
-  s2 = (255 - leave) * sizeof (wchar_t);
-  while (s1 > 0)
+  mbb = buf;
+  wcb = wide_buf + leave;
+  if (leave != 0 && leave < wsize){
+    memcpy (tmpb, wide_buf + wsize - leave, sizeof (wchar_t) * leave);
+    memcpy (wide_buf, tmpb, sizeof (wchar_t) * leave);
+  }
+  mbs = size;
+  wsize = leave;
+  while (mbs > 0 && wsize < (WIDE_BUF_SIZE - 1))
   {
-
-    iconv (ih_inp, NULL, NULL, NULL, NULL);
-    if (iconv (ih_inp, &b1, &s1, &b2, &s2) == (size_t) -1)
+    mbcharsize = mbrtowc (wcb, mbb, mbs, NULL);
+    /* '\0's will not be copyed to wide_buf */
+    if (mbcharsize <= 0)
     {
-      if (errno == EINVAL)	/* incomplete sequence at end of buffer */
-      {
-	break;
-      }
+      if (mbcharsize == (size_t)-2)    /* incomplete sequence at end of buffer */
+        break;
       /* invalid multibyte sequence - should we ignore or insert
          some character meaning 'invalid'? */
-      b1++;
-      s1--;
+      mbb++;
+      mbs--;
+      continue;
     }
+    wcb++;
+    wsize++;
+    mbb += mbcharsize;
+    mbs -= mbcharsize;
   }
-  bytes_left = s1;
-  bytes_left_start = b1;
-  wsize = (wchar_t *) b2 - wide_buf;
-  wide_buf[wsize] = 0;
+  bytes_left = mbs;
+  bytes_left_start = mbb;
+  wide_buf[wsize] = L'\0';
 }
 
 static wchar_t *
-gulp (wchar_t *cp, wchar_t **ep)
+gulp (wchar_t **ep)
 {
   int leave;
+
   if (!ep)
     leave = 0;
   else
@@ -623,7 +599,7 @@ gulp (wchar_t *cp, wchar_t **ep)
   read_buf (leave);
   if (ep)
     *ep = wide_buf;
-  return wide_buf;
+  return wide_buf + leave;
 }
 
 static void
@@ -631,12 +607,10 @@ kbsay ()
 {
   if (!ui.kbsay)
     return;
-  if (buf[0] == 8 || kbuf[0] == 127)
+  if (kbuf[0] == 8 || kbuf[0] == 127)
   {
     if ((ui.kbsay == 2) && (okbuflen != 0))
-    {
       okbuf[--okbuflen] = 0;
-    }
 
     /*tts_say(_("back")); */
     return;
@@ -648,10 +622,8 @@ kbsay ()
   }
 
   /* ui.kbsay == 2 -- handle word echo */
-  if (okbuflen < sizeof (kbuf) - 1 && is_char (kbuf[0]))
-  {
+  if (okbuflen < KBUF_SIZE - 1 && is_char (kbuf[0]))
     okbuf[okbuflen++] = kbuf[0];
-  }
 }
 
 #define MIN(a, b) ((a)>(b)? (b): (a))
@@ -660,9 +632,7 @@ strwtol (wchar_t **p)
 {
   long t = 0;
   while (iswdigit (**p))
-  {
     t = 10 * t + *(*p)++ - '0';
-  }
   return t;
 }
 
@@ -675,24 +645,33 @@ win_csi (wchar_t **pp)
   int i;
   int x;
 
+  /* last gulp could be just 1 char... */
+
+  if (!**pp)
+  {
+    if (!gulp (NULL))
+      return;
+    *pp = wide_buf;
+  }
+
   p = *pp;
+
   if (*p == '[')
     p++;
+
+  if (!*p && !(p = gulp (pp)))
+    return;
   if (*p == '?')
     p++;
   while (!*p || iswdigit ((int) *p) || *p == ';')
   {
     if (!*p)
     {
-      if (!(p = gulp (p, pp)))
-      {
-	return;
-      }
+      if (!(p = gulp (pp)))
+        return;
     }
     else
-    {
       p++;
-    }
   }
   p = *pp;
   if (*p == '[')
@@ -701,9 +680,7 @@ win_csi (wchar_t **pp)
     p++;
   }
   if (*p == '?')
-  {
     p++;
-  }
   (void) memset (&parm, 0, sizeof (int) * 16);
   while (numparms < 16 && (*p == ';' || iswdigit ((int) *p)))
   {
@@ -713,15 +690,11 @@ win_csi (wchar_t **pp)
     else
       break;			/* TODO: is this redundant? */
   }
-
   if (*p >= 0x20&& *p <= 0x2f)
     p++;
-
   *pp = p + 1;
   if (ignore)
-  {
     return;
-  }
   switch (*p)
   {
   case '@':			/* insert characters */
@@ -734,9 +707,7 @@ win_csi (wchar_t **pp)
   case 'A':			/* move up */
     win->cr -= PARM1;
     if (win->cr < 0)
-    {
       win->cr = 0;
-    }
     break;
 
   case 'B':			/* move down */
@@ -787,24 +758,18 @@ win_csi (wchar_t **pp)
       (void) memset (win->row[win->cr] + win->cc, 0,
 		     CHARSIZE * (win->cols - win->cc));
       for (i = win->cr + 1; i < win->rows; i++)
-      {
-	(void) memset (win->row[i], 0, win->cols * CHARSIZE);
-      }
+        (void) memset (win->row[i], 0, win->cols * CHARSIZE);
       break;
 
     case 1:			/* erase from start to cursor */
       (void) memset (win->row[win->cr], 0, win->cc);
       for (i = 0; i < win->cr; i++)
-      {
-	(void) memset (win->row[i], 0, win->cols * CHARSIZE);
-      }
+        (void) memset (win->row[i], 0, win->cols * CHARSIZE);
       break;
 
     case 2:			/* erase whole screen */
       for (i = 0; i < win->rows; i++)
-      {
-	(void) memset (win->row[i], 0, win->cols * CHARSIZE);
-      }
+        (void) memset (win->row[i], 0, win->cols * CHARSIZE);
       break;
     }
     break;
@@ -830,29 +795,19 @@ win_csi (wchar_t **pp)
   case 'L':			/* insert rows */
     x = MIN (PARM1, win_scrollmax - win->cr);
     for (i = win_scrollmax; i >= win->cr + x; i--)
-    {
       (void) memcpy (win->row[i], win->row[i - x], win->cols * CHARSIZE);
-    }
     for (i = win->cr; i < win->cr + x; i++)
-    {
       (void) memset (win->row[i], 0, win->cols * CHARSIZE);
-    }
     break;
 
   case 'M':
     x = MIN (PARM1, win_scrollmax - win->cr);
     if (x + win->cr > win_scrollmax)
-    {
       x = win_scrollmax - win->cr;
-    }
     for (i = win->cr; i <= win_scrollmax - x; i++)
-    {
       (void) memcpy (win->row[i], win->row[i + x], win->cols * CHARSIZE);
-    }
     for (i = win_scrollmax - x + 1; i <= win_scrollmax; i++)
-    {
       (void) memset (win->row[i], 0, win->cols * CHARSIZE);
-    }
     break;
 
   case 'P':			/* delete characters */
@@ -865,16 +820,12 @@ win_csi (wchar_t **pp)
 
   case 'S':			/* Scroll up */
     for (i = 0; i < PARM1; i++)
-    {
       win_scrollup ();
-    }
     break;
 
   case 'T':			/* Scroll down */
     for (i = 0; i < PARM1; i++)
-    {
       win_scrolldown ();;
-    }
     break;
 
   case 'X':			/* Erase characters */
@@ -891,9 +842,7 @@ win_csi (wchar_t **pp)
     {
     case 3:
       for (i = 0; i < win->cols; i++)
-      {
-	win->tab[i] = 0;
-      }
+        win->tab[i] = 0;
       break;
 
     case 0:
@@ -963,13 +912,9 @@ win_csi (wchar_t **pp)
   }
 
   if (win->cr >= win->rows)
-  {
     win->cr = win->rows - 1;
-  }
   else if (win->cr < 0)
-  {
     win->cr = 0;
-  }
   if (win->cc >= win->cols - 1)
     win->cc = win->cols - 1;
   else if (win->cc < 0)
@@ -988,7 +933,7 @@ win_osc (wchar_t **pp)
   {
     if (!*p)
     {
-      if (!(p = gulp (p, pp)))
+      if (!(p = gulp (pp)))
 	return;
     }
       p++;
@@ -1008,20 +953,14 @@ win_addchr (wchar_t ch, int tflag)
     win->carry++;
   }
   if (win->mode & 0x08)
-  {
     (void) memmove (win->row[win->cr] + win->cc + 1,
 		    win->row[win->cr] + win->cc,
 		    (win->cols - win->cc - 1) * CHARSIZE);
-  }
   win->row[win->cr][win->cc].attr = win->attr;
   win->row[win->cr][win->cc++].wchar = ch;
   if (tflag)
-  {
     if (ui.silent != 1)
-    {
       tts_addchr (ch);
-    }
-  }
 }
 
 wchar_t
@@ -1041,12 +980,8 @@ bol (int cr, int cc)
 
   rptr = win->row[cr];
   for (i = 0; i < cc; i++)
-  {
     if (y_isblank (rptr[i].wchar))
-    {
       return (0);
-    }
-  }
 
   return (1);
 }
@@ -1061,12 +996,8 @@ eol (int cr, int cc)
 
   rptr = win->row[cr];
   for (i = cc + 1; i < win->cols; i++)
-  {
     if (y_isblank (rptr[i].wchar))
-    {
       return (0);
-    }
-  }
 
   return (1);
 }
@@ -1082,16 +1013,10 @@ firstword (int cr, int cc)
   rptr = win->row[cr];
   i = cc;
   while (i && !y_isblank (rptr[i].wchar))
-  {
     i--;
-  }
   for (; i; i--)
-  {
     if (!y_isblank (rptr[i].wchar))
-    {
       return (0);
-    }
-  }
 
   return (1);
 }
@@ -1106,20 +1031,12 @@ lastword (int cr, int cc)
 
   rptr = win->row[cr];
   if (y_isblank (rptr[i].wchar))
-  {
     i++;
-  }
   while (i < win->cols && !y_isblank (rptr[i].wchar))
-  {
     i++;
-  }
   while (i < win->cols)
-  {
     if (!y_isblank (rptr[i++].wchar))
-    {
       return (0);
-    }
-  }
 
   return (1);
 }
@@ -1143,14 +1060,13 @@ getoutput ()
   static int stathit = 0, oldoflag = 0;
 
   read_buf (0);
+
 #ifdef TERMTEST
   (void) printf ("size=%d buf=%s\n", size, buf);
 #endif
 
   if (!size)
-  {
     finish (0);
-  }
   p = wide_buf;
 
   while (p - wide_buf < wsize)
@@ -1163,37 +1079,33 @@ getoutput ()
 
     case 8:
       if (win->cc)
-	win->cc--;
+        win->cc--;
       else if (win->carry && win->cr)
       {
-	win->cr--;
-	win->cc = win->cols - 1;
-	win->carry--;
+        win->cr--;
+        win->cc = win->cols - 1;
+        win->carry--;
       }
       if ((kbuf[0] == 8 || kbuf[0] == 127) && !tts.oflag && !ui.silent)
       {
-	kbsay ();
-	ui_saychar (win->cr, win->cc);
+        kbsay ();
+        ui_saychar (win->cr, win->cc);
       }
       if (tts.outlen)
-      {
-	tts.outlen--;
-      }
+        tts.outlen--;
       break;
 
     case 9:
       for (i = win->cc + 1; i < win->cols; i++)
       {
-	if (win->tab[i])
-	{
-	  win->cc = i;
-	  break;
-	}
+        if (win->tab[i])
+        {
+          win->cc = i;
+          break;
+        }
       }
       if (i == win->cols)
-      {
-	win->cc = i - 1;
-      }
+        win->cc = i - 1;
       break;
 
     case 10:
@@ -1211,36 +1123,34 @@ getoutput ()
       break;			/* may need to change in the future */
 
     case 27:
-      if (!*p && !(p = gulp (p, NULL)))
-      {
-	return;
-      }
+      if (!*p && !(p = gulp (NULL)))
+        return;
       switch (*p++)
       {
       case 'D':
-	win_lf ();
-	break;
+        win_lf ();
+        break;
       case 'E':
-	break;			/* FIXME -- new line */
+        break;			/* FIXME -- new line */
       case 'H':
-	win->tab[win->cc] = 1;
-	break;
+       win->tab[win->cc] = 1;
+       break;
       case 'M':
-	win_rlf ();
-	break;
+        win_rlf ();
+        break;
       case '7':
-	wincpy (&winsave, win);
-	oldcr = oldcc = 255;
-	break;
+        wincpy (&winsave, win);
+        oldcr = oldcc = 255;
+        break;
       case '8':
-	wincpy (&win, winsave);
-	break;
+        wincpy (&win, winsave);
+        break;
       case '[':
-	win_csi (&p);
-	break;
+        win_csi (&p);
+        break;
       case ']':
-	win_osc (&p);
-	break;
+        win_osc (&p);
+	    break;
       }
       break;
 
@@ -1252,37 +1162,27 @@ getoutput ()
 #if 0
       if (special)
       {
-	if (ch == '<')
-	{
-	  speaking = 0;		/* hack for medievia.com */
-	}
-	else if (ch == '>')
-	{
-	  speaking = 1;
-	}
+        if (ch == '<')
+          speaking = 0;		/* hack for medievia.com */
+        else if (ch == '>')
+          speaking = 1;
       }
 #endif
       if (ch == kbuf[0] && win->cr == oldcr && win->cc == oldcc && kbuflen)
       {
 /* this character was (probably) echoed as a result of a keystroke */
-	kbsay ();
-	win_addchr (ch, 0);
-	(void) memmove (kbuf, kbuf + 1, (--kbuflen) * sizeof (int));
+        kbsay ();
+        win_addchr (ch, 0);
+        (void) memmove (kbuf, kbuf + 1, (--kbuflen) * sizeof (int));
       }
       else
-      {
-	win_addchr (ch, speaking && in_speaking_window ());
-      }
+        win_addchr (ch, speaking && in_speaking_window ());
       chr = 1;
     }
     if (!chr && ch != 8 && (stathit == 0 || ch < '0' || ch > '9'))
-    {
       tts_flush ();
-    }
     else
-    {
       chr = 0;
-    }
     if ((!win->cc && win->cr > win->rows - 3) || win->cr == win->rows - 1)
     {
       stathit = win->cr;
@@ -1294,10 +1194,17 @@ getoutput ()
       tts.oflag = oldoflag;
     }
   }
-  if (ch == 13 || ch == 10 || ch == 32)
+  /* If last key was cursor left or cursor right just say char at cursor */
+  if (kbuf[0] == 0x1b5b43 || kbuf[0] == 0x1b5b44)
   {
-    tts_flush ();
+    ui_saychar (win->cr, win->cc);
+    oldcr = win->cr;
+    oldcc = win->cc;
+    oldch = win->row[win->cr][win->cc].wchar;
+    return;
   }
+  if (ch == 13 || ch == 10 || ch == 32)
+    tts_flush ();
   if (size > 1)
   {
     if (!readable (master, 0))
@@ -1306,9 +1213,7 @@ getoutput ()
       return;
   }
   else if (ch == 32 || ch == 13)
-  {
     tts_flush ();
-  }
   if (tts.oflag || kbuf[0] == 13 || kbuf[0] == 3 || ui.silent)
   {
     tts.oflag = stathit = 0;
@@ -1329,25 +1234,18 @@ getoutput ()
     case 1:			/* cursor moved right one character */
       if ((realchar (win->row[win->cr][win->cc - 1].wchar) == kbuf[0] &&
 	   realchar (oldch) != kbuf[0]) ||
-	  ((y_isblank (oldch) && kbuf[0] == 32)))
-      {
-	break;
-      }
-      if (kbuf[0] == 0x1b5b43 ||
-	  ((ui.curtrack == 2) && (ui.kbsay != 2 || is_separator (kbuf[0]))))
-      {
-	ui_saychar (win->cr, win->cc);
-      }
+                 ((y_isblank (oldch) && kbuf[0] == 32)))
       break;
+      if (ui.curtrack == 2 && (ui.kbsay != 2 || is_separator (kbuf[0])))
+        ui_saychar (win->cr, win->cc);
+      break;
 
     case 0:
       break;
 
     case -1:
-      if (kbuf[0] == 0x1b5b44 || ui.curtrack == 2)
-      {
+      if (ui.curtrack == 2)
 	ui_saychar (win->cr, win->cc);
-      }
       break;
 
     default:
@@ -1356,18 +1254,11 @@ getoutput ()
 	if (eol (win->cr, win->cc))
 	  ui_saychar (win->cr, win->cc);
 	else
-	{
 	  ui_sayword (win->cr, cblank (win->cr, win->cc) ?
 		      win->cc + 1 : win->cc);
-	}
       }
     }
   }
-  else if ((kbuf[0] == 0x1b5b43 && bol (win->cr, win->cc)) ||
-	   (kbuf[0] == 0x1b5b44 && eol (win->cr, win->cc)))
-  {
-    ui_saychar (win->cr, win->cc);
-  }
   else
   {
     switch (win->cr - oldcr)
@@ -1378,46 +1269,36 @@ getoutput ()
 	ui_sayline (win->cr, 1);
 	break;
       }
-      if (win->cc == 0 && (oldcr == win->cols - 1 || kbuf[0] == 0x1b5b43))
+      if (win->cc == 0 && oldcr == win->cols - 1)
       {
-	ui_saychar (win->cr, win->cc);
-	break;
+        ui_saychar (win->cr, win->cc);
+        break;
       }
       if (ui.curtrack < 2)
-      {
-	break;
-      }
+        break;
       if (win->cc && bol (win->cr, win->cc) && lastword (oldcr, oldcc)
-	  && oldcc)
-      {
-	ui_sayword (win->cr, win->cc);
-      }
+          && oldcc)
+        ui_sayword (win->cr, win->cc);
       else
-      {
-	ui_sayline (win->cr, 1);
-      }
+        ui_sayline (win->cr, 1);
       break;
     case -1:			/* cursor moved up a line */
       if (kbuf[0] == 0x1b5b41)
       {
-	ui_sayline (win->cr, 1);
-	break;
+        ui_sayline (win->cr, 1);
+        break;
       }
       if (ui.curtrack < 2)
-	break;
-      if (win->cc == win->cols - 1 && (oldcr == 0 || kbuf[0] == 0x1b5b44))
-      {
-	ui_saychar (win->cr, win->cc);
-      }
+        break;
+      if (win->cc == win->cols - 1 && oldcr == 0)
+        ui_saychar (win->cr, win->cc);
       else if (lastword (win->cr, win->cc) &&
 	       !firstword (win->cr, win->cc) &&
 	       (!win->cc || cblank (win->cr, win->cc - 1)) &&
 	       firstword (oldcr, oldcc))
-      {
-	ui_sayword (win->cr, win->cc);
-      }
+        ui_sayword (win->cr, win->cc);
       else
-	ui_sayline (win->cr, 1);
+        ui_sayline (win->cr, 1);
       break;
     }
   }
@@ -1470,18 +1351,14 @@ parent (void *arg)
       }
     }
     if (FD_ISSET (0, &rf))
-    {
       getinput ();
-    }
     if (FD_ISSET (master, &rf))
     {
       getoutput ();
-      kbuflen = 0;
+      kbuf[0] = kbuflen = 0;
     }
     if (FD_ISSET (tts.fd, &rf))
-    {
       get_tts_input ();
-    }
   }
   return NULL;
 }
@@ -1512,25 +1389,12 @@ main (int argc, char *argv[])
   bindtextdomain (GETTEXT_PACKAGE, LOCALEDIR);
   textdomain (GETTEXT_PACKAGE);
   strcpy (charmap, nl_langinfo (CODESET));
-  if (!strcmp (charmap, "ANSI_X3.4-1968"))
-    strcpy (charmap, "UTF-8");
-
-  ih_inp = iconv_open ("WCHAR_T", charmap);
-  if (ih_inp == (iconv_t) - 1)
-  {
-    fprintf (stderr, "Codeset %s not supported\n", charmap);
-    exit (1);
-  }
-
-
 #endif
 
   if (argv[0][0] == '-')
     shell = 1;
   if (isatty (0))
-  {
     (void) ioctl (0, TIOCGWINSZ, &winsz);
-  }
   if (!winsz.ws_row)
   {
     winsz.ws_row = 25;
@@ -1571,9 +1435,7 @@ main (int argc, char *argv[])
     }
   }
   if (argv[optind])
-  {
     subprog = argv + optind;
-  }
   readconf ();
 
 #if 0				/* this doesn't work */
@@ -1581,9 +1443,7 @@ main (int argc, char *argv[])
   {
     cp = usershell + strlen (usershell) - 1;
     while (*cp && *cp != '/')
-    {
       cp--;
-    }
     cp++;
     argv[0] = cp;
     (void) execv (usershell, argv);
@@ -1672,9 +1532,7 @@ w_speak (wchar_t *ibuf, int len)
     {
       olen -= nc;
       if (olen)
-      {
-	tts_out_w (wstart, olen);
-      }
+        tts_out_w (wstart, olen);
       olen = 0;
       while (i < len1 && ibuf[i + 1] == lc)
       {
@@ -1690,25 +1548,19 @@ w_speak (wchar_t *ibuf, int len)
     else
     {
       if (!olen)
-	wstart = ibuf + i;
+        wstart = ibuf + i;
       olen++;
       if (ibuf[i] != lc)
-      {
-	nc = 0;
-      }
+        nc = 0;
       if (!iswalnum (ibuf[i]) &&
 	  ibuf[i] != 32 && ibuf[i] != '=' && ibuf[i] >= 0)
-      {
-	lc = ibuf[i];
-      }
+        lc = ibuf[i];
       else
 	lc = 0;
     }
   }
   if (olen)
-  {
     tts_out_w (wstart, olen);
-  }
 }
 
 #if 0
@@ -1730,14 +1582,12 @@ speak (char *ibuf, int len)
     {
       olen -= nc;
       if (olen)
-      {
-	tts_out ((unsigned char *) obuf, olen);
-      }
+        tts_out ((unsigned char *) obuf, olen);
       olen = 0;
       while (i < len1 && ibuf[i + 1] == lc)
       {
-	i++;
-	nc++;
+        i++;
+        nc++;
       }
       tts_saychar (lc);
       tts_out ((unsigned char *) obuf,
@@ -1749,26 +1599,20 @@ speak (char *ibuf, int len)
     {
       obuf[olen++] = ibuf[i];
       if (ibuf[i] != lc)
-      {
-	nc = 0;
-      }
+        nc = 0;
       if (!isalpha ((int) ibuf[i]) && !isdigit ((int) ibuf[i]) &&
 	  ibuf[i] != 32 && ibuf[i] != '=' && ibuf[i] >= 0)
-      {
-	lc = ibuf[i];
-      }
+        lc = ibuf[i];
       else
-	lc = 0;
+        lc = 0;
       if (olen > 250 && !nc)
       {
-	tts_out ((unsigned char *) obuf, olen);
-	olen = 0;
+        tts_out ((unsigned char *) obuf, olen);
+        olen = 0;
       }
     }
   }
   if (olen)
-  {
     tts_out ((unsigned char *) obuf, olen);
-  }
 }
 #endif
