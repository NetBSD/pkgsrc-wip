$NetBSD: patch-romload.c,v 1.1.1.1 2011/09/28 14:57:12 ryo-on Exp $

--- romload.c.orig	2011-09-28 02:57:08.000000000 +0000
+++ romload.c
@@ -149,16 +149,16 @@ void loadroms(void)
 	rpclog("romload: Total ROM size %d MB\n", pos / 1048576);
 
 #ifdef _RPCEMU_BIG_ENDIAN /*Byte swap*/
-#error "It's defined..."
+//#error "It's defined..."
 //printf("Byte swapping...\n");
-		for (c=0;c<0x800000;c+=4)
+/* 		for (c=0;c<0x800000;c+=4)
 		{
                                 uint32_t temp;
 				temp=rom[c>>2];
-				temp=((temp&0xFF000000)>>24)|((temp&0x00FF0000)>>8)|((temp&0x0000FF00)<<8)|((temp&0x000000FF)<<24);
+				temp=((temp&0xFF000000)>>24)|((temp&0x00FF0000)>>8)|((temp&0x0000FF00)<<8)|((temp&0x000000FF)<<24); */
 //				temp=((temp>>24)&0xFF)|((temp>>8)&0xFF00)|((temp<<8)&0xFF0000)|((temp<<24)|0xFF000000);
-				rom[c>>2]=temp;
-		}
+/*				rom[c>>2]=temp;
+		}*/
 #endif
         /*Patch ROM for 8 meg vram!*/
         if (rom[0x14820>>2]==0xE3560001 && /*Check for ROS 4.02 startup*/
