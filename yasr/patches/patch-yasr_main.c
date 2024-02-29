$NetBSD$

Remove non-portable use of WCHAR_T in iconv code.
Remove the enforcing of UTF-8
Fix a bug speaking a char when cursor-right is input after space

--- yasr/main.c.orig	2023-04-08 21:22:57.000000000 +0000
+++ yasr/main.c
@@ -33,8 +33,6 @@
 #include <sys/types.h>
 #include <sys/wait.h>
 #include <langinfo.h>
-#include <iconv.h>
-iconv_t ih_inp;
 static int cpid;
 static int size, wsize;
 static int master, slave;
@@ -307,23 +305,10 @@ is_separator (int ch)
 static int
 getkey_buf ()
 {
-  char *b1, *b2;
-  size_t s1, s2;
   wchar_t ch;
   int key;
   int result;
-
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
+ 
   key = (int) buf[0];
   if (size > 1)
   {
@@ -361,6 +346,7 @@ getinput ()
     finish (0);
   }
   key = getkey_buf ();
+
   if (key == ui.disable)
   {
     if (ui.disabled)
@@ -561,8 +547,10 @@ static char *bytes_left_start;
 static void
 read_buf (int leave)
 {
-  char *b1, *b2;
-  size_t s1, s2;
+  int i;
+  char *b1;
+  wchar_t *b2;
+  size_t s1;
   if (bytes_left)
   {
     memcpy (buf, bytes_left_start, bytes_left);
@@ -578,17 +566,16 @@ read_buf (int leave)
   buf[size] = 0;
   bytes_left = 0;
   b1 = (char *) buf;
-  b2 = (char *) (wide_buf + leave);
+  b2 = wide_buf + leave;
   if (leave)
-    memcpy (wide_buf, wide_buf + wsize - leave,
+    memcpy (wide_buf
+	    , wide_buf + wsize - leave,
 	    sizeof (wchar_t) * (wsize - leave));
   s1 = size;
-  s2 = (255 - leave) * sizeof (wchar_t);
   while (s1 > 0)
   {
-
-    iconv (ih_inp, NULL, NULL, NULL, NULL);
-    if (iconv (ih_inp, &b1, &s1, &b2, &s2) == (size_t) -1)
+    i = mbtowc (b2, b1, s1);
+    if (i == -1)
     {
       if (errno == EINVAL)	/* incomplete sequence at end of buffer */
       {
@@ -599,10 +586,13 @@ read_buf (int leave)
       b1++;
       s1--;
     }
+    ++b2;
+    b1 += i;
+    s1 -= i;
   }
   bytes_left = s1;
   bytes_left_start = b1;
-  wsize = (wchar_t *) b2 - wide_buf;
+  wsize = b2 - wide_buf;
   wide_buf[wsize] = 0;
 }
 
@@ -1253,6 +1243,7 @@ getoutput ()
       tts.oflag = oldoflag;
     }
   }
+
   if (ch == 13 || ch == 10 || ch == 32)
   {
     tts_flush ();
@@ -1268,7 +1259,8 @@ getoutput ()
   {
     tts_flush ();
   }
-  if (tts.oflag || kbuf[0] == 13 || kbuf[0] == 3 || ui.silent)
+  /* Workaround cursor move right after space... */
+  if ((tts.oflag || kbuf[0] == 13 || kbuf[0] == 3 || ui.silent) && kbuf[0] != 0x1b5b43)
   {
     tts.oflag = stathit = 0;
     oldcr = win->cr;
@@ -1470,17 +1462,6 @@ main (int argc, char *argv[])
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
