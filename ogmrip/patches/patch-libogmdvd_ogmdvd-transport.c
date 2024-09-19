$NetBSD: patch-libogmdvd_ogmdvd-transport.c,v 1.1 2011/11/19 22:33:08 blckmaxima Exp $

--- libogmdvd/ogmdvd-transport.c.orig	2010-08-22 10:38:34.000000000 +0000
+++ libogmdvd/ogmdvd-transport.c
@@ -220,13 +220,6 @@ typedef off_t off64_t;
 #define pwrite64 pwrite
 #define lseek64  lseek
 
-typedef enum
-{
-  NONE = 0,
-  READ = SCCMD_READ,
-  WRITE = SCCMD_WRITE
-} Direction;
-
 struct _Scsi_Command
 {
   int fd;
@@ -271,13 +264,13 @@ scsi_command_set (Scsi_Command *cmd, siz
 {
   if (index == 0)
   {
-    memset (&req, 0, sizeof (req));
-    req.flags = SCCMD_ESCAPE;
-    req.timeout = 30000;
-    req.senselen = 18; //sizeof(req.sense);
+    memset (&cmd->req, 0, sizeof (cmd->req));
+    cmd->req.flags = SCCMD_ESCAPE;
+    cmd->req.timeout = 30000;
+    cmd->req.senselen = 18; //sizeof(cmd->req.sense);
   }
-  req.cmdlen = index + 1;
-  req.cmd[index] = value;
+  cmd->req.cmdlen = index + 1;
+  cmd->req.cmd[index] = value;
 }
 
 int
@@ -285,24 +278,24 @@ scsi_command_transport (Scsi_Command *cm
 {
   int ret = 0;
 
-  req.databuf = (caddr_t) buf;
-  req.datalen = sz;
-  req.flags |= dir;
+  cmd->req.databuf = (caddr_t) buf;
+  cmd->req.datalen = sz;
+  cmd->req.flags |= dir;
 
-  if (ioctl (fd, SCIOCCOMMAND, &req) < 0)
+  if (ioctl (cmd->fd, SCIOCCOMMAND, &cmd->req) < 0)
     return -1;
-  if (req.retsts == SCCMD_OK)
+  if (cmd->req.retsts == SCCMD_OK)
     return 0;
 
   errno = EIO;
   ret = -1;
-  if (req.retsts == SCCMD_SENSE)
+  if (cmd->req.retsts == SCCMD_SENSE)
   {
-    ret = ERRCODE (req.sense);
+    ret = ERRCODE (cmd->req.sense);
     if (ret == 0)
       ret = -1;
     else
-      CREAM_ON_ERRNO (req.sense);
+      CREAM_ON_ERRNO (cmd->req.sense);
   }
 
   return ret;
