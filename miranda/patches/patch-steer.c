$NetBSD$

--- steer.c.orig	2026-08-31 16:10:00.000000000 +0000
+++ steer.c
@@ -269,6 +269,7 @@ int main(int argc,char *argv[])
     { char *m;
       /* note search order */
       if((m=getenv("MIRALIB")))miralib=m; else
+      if(checkversion(m="@PREFIX@/lib/miralib"))miralib=m; else
       if(checkversion(m="/usr/lib/miralib"))miralib=m; else
       if(checkversion(m="/usr/local/lib/miralib"))miralib=m; else
       if(checkversion(m="miralib"))miralib=m; else
@@ -581,7 +582,7 @@ int cmdgetchar(void)
   }
   if(lnpos) {
     if(*lnpos)
-      return *lnpos++;
+      return (unsigned char)*lnpos++;
     lnpos = NULL;
     return '\n';  /* end of line */
   }
@@ -1192,7 +1193,7 @@ void finger(char *n) /* find info about 
 
 void diagnose(char *n)
 { int i=0;
-  if(isalpha((int)n[0]))
+  if(isalpha((unsigned char)n[0]))
     while(n[i]&&okid(n[i]))i++;
   if(n[i]){ printf("\"%s\" -- not an identifier\n",n); return; }
   for(i=0;presym[i];i++)
