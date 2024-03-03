$NetBSD$

Remove non-portable use of WCHAR_T in iconv code.
Remove the enforcing of UTF-8

--- yasr/main.c.orig	2023-04-08 21:22:57.000000000 +0000
+++ yasr/main.c
@@ -33,14 +33,14 @@
 #include <sys/types.h>
 #include <sys/wait.h>
 #include <langinfo.h>
-#include <iconv.h>
-iconv_t ih_inp;
 static int cpid;
 static int size, wsize;
 static int master, slave;
 char *conffile = NULL;
-unsigned char buf[256];
-wchar_t wide_buf[256];
+#define BUF_MAX 256
+#define WIDE_BUF_MAX 256
+char buf[BUF_MAX];
+wchar_t wide_buf[WIDE_BUF_MAX];
 char usershell[OPT_STR_SIZE];
 static struct termios t;
 Win *win;
@@ -307,23 +307,13 @@ is_separator (int ch)
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
   {
@@ -355,7 +345,7 @@ getinput ()
 {
   int key;
 
-  size = read (0, buf, 255);
+  size = read (0, buf, BUF_MAX);
   if (size <= 0)
   {
     finish (0);
@@ -533,41 +523,44 @@ oldgulp (unsigned char *buf, int *size, 
     if (ep)
     {
       n = buf + *size - *ep;
-      (void) memmove (buf, *ep, 256 - n);
-      *size = n + read (master, buf + n, 255 - n);
+      (void) memmove (buf, *ep, BUF_MAX - n);
+      *size = n + read (master, buf + n, BUF_MAX - 1  - n);
       buf[*size] = '\0';
       (void) write (1, buf + n, *size - n);
       *ep = buf;
       return ((char *) buf + n);
     }
-    *size = read (master, buf, 255);
+    *size = read (master, buf, BUF_MAX - 1);
     buf[*size] = '\0';
     (void) write (1, buf, *size);
     return ((char *) buf);
   }
-  *size += read (master, buf + *size, 255 - *size);
+  *size += read (master, buf + *size, BUF_MAX - 1 - *size);
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
+  char *bmb, tmpch[BUF_MAX];
+  wchar_t *bwc, tmpwc[WIDE_BUF_MAX];
+  size_t smb;
+
+  if (bytes_left){
+    memcpy (tmpch, bytes_left_start, bytes_left);
+    memcpy (buf, tmpch, bytes_left);
   }
-  size = read (master, buf + bytes_left, 255 - bytes_left - leave);
+  size = read (master, buf + bytes_left, BUF_MAX - bytes_left - 1);
   if (size < 0)
   {
     perror ("read");
@@ -577,32 +570,45 @@ read_buf (int leave)
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
-  {
-
-    iconv (ih_inp, NULL, NULL, NULL, NULL);
-    if (iconv (ih_inp, &b1, &s1, &b2, &s2) == (size_t) -1)
+  bmb = buf;
+  bwc = wide_buf + leave;
+  if (leave != 0 && leave < wsize){
+    memcpy (tmpwc, wide_buf + wsize - leave, sizeof (wchar_t) * leave);
+    memcpy (wide_buf, tmpwc, sizeof (wchar_t) * leave);
+  }
+  smb = size;
+  wsize = 0;
+  while (smb > 0 && wsize < (WIDE_BUF_MAX - 1))
+  {
+    mbcharsize = mbtowc (bwc, bmb, smb);
+    if (mbcharsize == 0) /* it reached buf[size] */
+    {
+      bytes_left = 0;
+      bytes_left_start = NULL;
+      wsize = bwc - wide_buf;
+      wide_buf[wsize] = 0;
+      return;
+    }
+    if (mbcharsize == -1)
     {
-      if (errno == EINVAL)	/* incomplete sequence at end of buffer */
+      if (errno == EILSEQ)	/* incomplete sequence at end of buffer */
       {
 	break;
       }
       /* invalid multibyte sequence - should we ignore or insert
          some character meaning 'invalid'? */
-      b1++;
-      s1--;
-    }
-  }
-  bytes_left = s1;
-  bytes_left_start = b1;
-  wsize = (wchar_t *) b2 - wide_buf;
+      bmb++;
+      smb--;
+      continue;
+    }
+    bwc++;
+    bmb += mbcharsize;
+    smb -= mbcharsize;
+    wsize = bwc - wide_buf;
+  }
+  bytes_left = smb;
+  bytes_left_start = bmb;
+  wsize = bwc - wide_buf;
   wide_buf[wsize] = 0;
 }
 
@@ -1108,7 +1114,7 @@ getoutput ()
 #ifdef TERMTEST
   (void) printf ("size=%d buf=%s\n", size, buf);
 #endif
-
+  
   if (!size)
   {
     finish (0);
@@ -1253,8 +1259,9 @@ getoutput ()
       tts.oflag = oldoflag;
     }
   }
-  if (ch == 13 || ch == 10 || ch == 32)
-  {
+
+
+  if (ch == 13 || ch == 10){
     tts_flush ();
   }
   if (size > 1)
@@ -1264,10 +1271,6 @@ getoutput ()
     else
       return;
   }
-  else if (ch == 32 || ch == 13)
-  {
-    tts_flush ();
-  }
   if (tts.oflag || kbuf[0] == 13 || kbuf[0] == 3 || ui.silent)
   {
     tts.oflag = stathit = 0;
@@ -1288,7 +1291,7 @@ getoutput ()
     case 1:			/* cursor moved right one character */
       if ((realchar (win->row[win->cr][win->cc - 1].wchar) == kbuf[0] &&
 	   realchar (oldch) != kbuf[0]) ||
-	  ((y_isblank (oldch) && kbuf[0] == 32)))
+		  ((y_isblank (oldch) && kbuf[0] == 32)))
       {
 	break;
       }
@@ -1470,17 +1473,6 @@ main (int argc, char *argv[])
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
