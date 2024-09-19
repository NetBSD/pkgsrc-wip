$NetBSD$

--- compiler/systems/t_bsd.pas.orig	2014-12-07 20:27:02.000000000 +0000
+++ compiler/systems/t_bsd.pas
@@ -310,7 +310,10 @@ begin
   if startupfile<>'' then
     begin
      if not librarysearchpath.FindFile(startupfile,false,result) then
-       result:='/usr/lib/'+startupfile
+       if sysutils.DirectoryExists('/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/lib') then
+         result:='/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/lib/'+startupfile
+       else
+         result:='/usr/lib/'+startupfile
     end
   else
     result:='';
