$NetBSD$

Prevent undefined behaviour of tolower().

--- main.c.orig	2026-07-01 12:11:48.956156567 +0000
+++ main.c
@@ -1047,7 +1047,7 @@ static bool IwadWarning(const char *wadn
                "change it (y/n)? ",
                wadname);
         fflush(stdout);
-        response = tolower(ReadResponse());
+        response = tolower((unsigned char) ReadResponse());
         if (response == 'y')
         {
             printf("\n");
