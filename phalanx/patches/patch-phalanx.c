$NetBSD: patch-phalanx.c,v 1.1 2015/05/06 21:50:36 f8l Exp $

Makes get_book_file check permisions for each directory.
Simplifies learn book opening logic using these checks.
Adds warning when the learn book cannot be created.

Before this change, it was checked if the learn book
directory was writable, but if the learn book file
did not exist in that directory, it was not created.
The current directory was used as a fallback.
This change moves the permission checks
to get_book_file, so it returns the first writable
location and falls back to the current directory
when such a location is not found.
The current directory is no longer the only location
in which the learn book can be created if not found.

--- phalanx.c.orig	2014-12-23 09:42:54.000000000 +0000
+++ phalanx.c
@@ -44,6 +44,15 @@ exit(0);
 }
 
 
+void make_path(char *path, unsigned path_size, char *dirname, char *filename)
+{
+#ifdef GNUFUN
+    snprintf(path,path_size-1,"%s/%s",dirname,filename);
+#else
+    sprintf(path,"%s/%s",dirname,filename);
+#endif
+}
+
 char *get_book_file(char *bookdir,char *env_variable,
 		    char *path,char *name,int mode)
 {
@@ -51,19 +60,23 @@ char *get_book_file(char *bookdir,char *
   char *aux;
   
   if(bookdir)			/* Specified in options? */
-    path = bookdir;
-  else if((aux=getenv(env_variable))) /* In an environment variable? */
-    path = aux;
-  else if(!access(name,mode))	/* In the current directory? */
-    path = ".";
+  {
+    make_path(file,256,bookdir,name);
+    if(!access(file,mode))
+      return strdup(file);
+  }
+  if((aux=getenv(env_variable))) /* In an environment variable? */
+  {
+    make_path(file,256,aux,name);
+    if(!access(file,mode))
+      return strdup(file);
+  }
+  if(!access(name,mode))	/* In the current directory? */
+    path=".";
   else				/* Desperacy now, use compile time file. */
     ;
 
-#ifdef GNUFUN
-  snprintf(file,255,"%s/%s",path,name);
-#else
-  sprintf(file,"%s/%s",path,name);
-#endif
+  make_path(file,256,path,name);
   return strdup(file);
 }
 
@@ -388,14 +401,15 @@ if( Flag.learn )
 	{
 #		define LFSZ 65536
 		int b[LFSZ];
-		char filename[256];
 		memset( b, 0, LFSZ*sizeof(int) );
-  		sprintf(filename,"./%s",LEARN_FILE);
-		free( LbookDir );
-		LbookDir = strdup( filename );
 		Learn.f = fopen(LbookDir,"w+");
-		if( fwrite( b, sizeof(int), LFSZ, Learn.f ) == LFSZ )
-		printf("telluser Phalanx: created learn file %s\n",LbookDir);
+		if( Learn.f != NULL && fwrite( b, sizeof(int), LFSZ, Learn.f ) == LFSZ )
+			printf("telluser Phalanx: created learn file %s\n",LbookDir);
+		else
+		{
+			Learn.f = NULL;
+			printf("telluser Phalanx: Failed to create learn file %s\n",LbookDir);
+		}
 	}
 } else Learn.f = NULL;
 
