$NetBSD$

--- just.c.orig	2026-06-24 09:34:45.000000000 +0000
+++ just.c
@@ -42,11 +42,11 @@ char *argv[];
   if(j_in){ if(fscanf(j_in,"%d",&width)!=1)width=72;
 	    fclose(j_in); }
   while(argc>1&&argv[1][0]=='-')
-    if(argv[1][1]=='t'&&isdigit(argv[1][2]))
+    if(argv[1][1]=='t'&&(unsigned char)isdigit(argv[1][2]))
     { sscanf(argv[1]+2,"%d",&tolerance);
       argc--; argv++;
     }else
-    if(isdigit(argv[1][1])||argv[1][1]=='-'&&isdigit(argv[1][2]))
+    if(isdigit((unsigned char)argv[1][1])||argv[1][1]=='-'&&isdigit((unsigned char)argv[1][2]))
     { sscanf(argv[1]+1,"%d",&width);
       argc--; argv++;
     }
@@ -98,7 +98,7 @@ char *fn;
       { puts(bp=buf); continue; }
   /*otherwise perform justification up to next indented,blank or frozen line*/
     squeeze(buf);
-    while(bp-buf>(w=width+bs_cor(buf))||!isspace(c=peek(fp))&&c!=EOF&&c!='>')
+    while(bp-buf>(w=width+bs_cor(buf))||!isspace((unsigned char)c=peek(fp))&&c!=EOF&&c!='>')
       if(bp-buf<=w/*idth+bs_cor(buf)*/)
         { pad(); getln(fp,1); }
       else{ /* cut off as much as you can use */
