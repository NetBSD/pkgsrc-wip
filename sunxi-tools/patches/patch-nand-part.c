$NetBSD: patch-nand-part.c,v 1.1 2015/06/11 20:47:31 tnn2 Exp $

Only use Linux ioctl's on Linux.

--- nand-part.c.orig	2014-04-26 18:59:49.000000000 +0000
+++ nand-part.c
@@ -249,8 +249,10 @@ static int writembrs(int fd, char names[
 		write(fd,mbr,MBR_SIZE);
 	}
 
+#ifdef __linux__
 	if (ioctl(fd, BLKRRPART, NULL))
 		perror("Failed rereading partition table");
+#endif
 
 	return 1;
 }
@@ -312,7 +314,9 @@ int nand_part (int argc, char **argv, co
 		if (writembrs(fd, names, start, lens, user_types, argc, partoffset, force)) {
 			printf("\nverifying new partition tables:\n");
 			checkmbrs(fd);
+#ifdef __linux__
 			printf("rereading partition table... returned %d\n", ioctl(fd, BLKRRPART, 0));
+#endif
 		}
 	}
 	close(fd);
