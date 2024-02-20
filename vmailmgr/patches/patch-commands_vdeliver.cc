$NetBSD$

--- commands/vdeliver.cc.orig	2024-02-20 03:26:27.764197339 +0000
+++ commands/vdeliver.cc
@@ -262,7 +262,7 @@ void inject(mystring sender, mystring re
     close(pipe2[1]);
     if((dup2(pipe1[0], 0) != 0) || (dup2(pipe2[0], 1) != 1))
       exit(111);
-    execl(qq.c_str(), qq.c_str(), 0);
+    execl(qq.c_str(), qq.c_str(), (char *)0);
     die_temp("Exec of qmail-queue failed.");
   default:
     close(pipe1[0]);
