$NetBSD$

Don't discriminate against unix-like systems.

Pick up paths from pkgsrc.

--- setup.c.orig	2012-12-05 00:18:04.000000000 +0000
+++ setup.c
@@ -39,7 +39,7 @@
 #elif defined(__MINT__)
     #include <mint/osbind.h>
     #include <mint/sysbind.h>
-#elif defined(__linux__)
+#else
   #include <limits.h>
   #include <unistd.h>
 #endif
@@ -71,44 +71,7 @@ int Create_ConfigDirectory(char * config
 void Set_program_directory(const char * argv0,char * program_dir)
 {
   (void)argv0; // unused sometimes
-  
-  // MacOSX
-  #if defined(__macosx__)
-    CFURLRef url = CFBundleCopyBundleURL(CFBundleGetMainBundle());
-    CFURLGetFileSystemRepresentation(url,true,(UInt8*)program_dir,MAXPATHLEN);
-    CFRelease(url);
-    // Append trailing slash
-    strcat(program_dir    ,"/");
-  
-  // AmigaOS and alike: hard-coded volume name.
-  #elif defined(__amigaos4__) || defined(__AROS__) || defined(__MORPHOS__) || defined(__amigaos__)
-    strcpy(program_dir,"PROGDIR:");
-  #elif defined(__MINT__)
-  static char path[1024]={0};
-  char currentDrive='A';
-  currentDrive=currentDrive+Dgetdrv();
-  
-  Dgetpath(path,0);
-  sprintf(program_dir,"%c:\%s",currentDrive,path);
-  // Append trailing slash
-  strcat(program_dir,PATH_SEPARATOR);
-  // Linux: argv[0] unreliable
-  #elif defined(__linux__)
-  if (argv0[0]!='/')
-  {
-    char path[PATH_MAX];
-    readlink("/proc/self/exe", path, sizeof(path));
-    Extract_path(program_dir, path);
-    return;
-  }  
-  Extract_path(program_dir, argv0);
-  
-  // Others: The part of argv[0] before the executable name.    
-  // Keep the last \ or /.
-  // On Windows, Mingw32 already provides the full path in all cases.
-  #else
-    Extract_path(program_dir, argv0);
-  #endif
+  strcpy(program_dir, PREFIX "/bin/");
 }
 
 // Determine which directory contains the read-only data.
@@ -116,23 +79,8 @@ void Set_program_directory(const char *
 // OUT: Write into data_dir. Trailing / or \ is kept.
 void Set_data_directory(const char * program_dir, char * data_dir)
 {
-  // On all platforms, data is relative to the executable's directory
-  strcpy(data_dir,program_dir);
-  // On MacOSX,  it is stored in a special folder:
-  #if defined(__macosx__)
-    strcat(data_dir,"Contents/Resources/");
-  // On GP2X, executable is not in bin/
-  #elif defined (__GP2X__) || defined (__gp2x__) || defined (__WIZ__) || defined (__CAANOO__)
-    strcat(data_dir,"share/grafx2/");
-  //on tos the same directory
-  #elif defined (__MINT__)
-    strcpy(data_dir, program_dir);
-  // All other targets, program is in a "bin" subdirectory
-  #elif defined (__AROS__)
-    strcat(data_dir,"share/grafx2/");
-  #else
-    strcat(data_dir,"../share/grafx2/");
-  #endif
+  (void)program_dir;
+  strcpy(data_dir, PREFIX "/share/grafx2/");
 }
 
 // Determine which directory should store the user's configuration.
