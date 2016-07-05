$NetBSD$

Add NetBSD support.

--- src/OSD/OSD_Host.cxx.orig	2016-04-04 14:58:12.000000000 +0000
+++ src/OSD/OSD_Host.cxx
@@ -72,6 +72,7 @@ struct utsname info; 
  if (!strcmp(info.sysname,"SunOS"))          return (OSD_UnixBSD);
  if (!strcmp(info.sysname,"ULTRIX"))         return (OSD_UnixBSD);
  if (!strcmp(info.sysname,"FreeBSD"))        return (OSD_UnixBSD);
+ if (!strcmp(info.sysname,"NetBSD"))         return (OSD_UnixBSD);
  if (!strncmp(info.sysname,"Linux",5))       return (OSD_LinuxREDHAT);
  if (!strncmp(info.sysname,"IRIX", 4))       return (OSD_UnixSystemV);
  if (!strncmp(info.sysname,"OSF", 3))        return (OSD_OSF);
@@ -153,6 +154,7 @@ struct utsname info; 
  if (!strncmp(info.sysname,"OSF",3))        return (OSD_DEC);
  if (!strncmp(info.sysname,"Linux",5))      return (OSD_LIN);
  if (!strcmp(info.sysname,"FreeBSD"))       return (OSD_LIN);
+ if (!strcmp(info.sysname,"NetBSD"))        return (OSD_LIN);
  if (!strncmp(info.sysname,"AIX",3))        return (OSD_AIX);
  if (!strcmp(info.sysname,"Darwin"))        return (OSD_MAC);
  return (OSD_Unavailable);
@@ -344,8 +346,3 @@ Standard_Integer OSD_Host :: Error () co
 }  //end OSD_Host :: Error
 
 #endif
-
-
-
-
-
