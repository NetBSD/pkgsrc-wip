$NetBSD$

- search for miralib in PREFIX/lib

--- steer.c.orig	2026-10-07 17:41:14.374332829 +0000
+++ steer.c
@@ -269,6 +269,7 @@ int main(int argc,char *argv[])
     { char *m;
       /* note search order */
       if((m=getenv("MIRALIB")))miralib=m; else
+      if(checkversion(m="@PREFIX@/lib/miralib"))miralib=m; else
       if(checkversion(m="/usr/lib/miralib"))miralib=m; else
       if(checkversion(m="/usr/local/lib/miralib"))miralib=m; else
       if(checkversion(m="miralib"))miralib=m; else
