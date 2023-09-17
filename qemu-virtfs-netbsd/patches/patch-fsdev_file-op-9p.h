$NetBSD$

Provide forward declaration of struct statfs.

--- fsdev/file-op-9p.h.orig	2023-08-22 15:34:01.000000000 +0000
+++ fsdev/file-op-9p.h
@@ -119,6 +119,8 @@ typedef union V9fsFidOpenState V9fsFidOp
 
 void cred_init(FsCred *);
 
+struct statfs;
+
 struct FileOperations {
     int (*parse_opts)(QemuOpts *, FsDriverEntry *, Error **errp);
     int (*init)(FsContext *, Error **errp);
