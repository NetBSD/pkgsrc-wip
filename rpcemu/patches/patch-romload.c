$NetBSD: patch-romload.c,v 1.1.1.1 2011/09/28 14:55:43 ryo-on Exp $

* For fix build, commented out

--- romload.c.orig	2010-09-19 19:25:37.000000000 +0000
+++ romload.c
@@ -144,16 +144,16 @@ void loadroms(void)
         }
 
 #ifdef _RPCEMU_BIG_ENDIAN /*Byte swap*/
-#error "It's defined..."
+//#error "It's defined..."
 //printf("Byte swapping...\n");
-		for (c=0;c<0x800000;c+=4)
+/*		for (c=0;c<0x800000;c+=4)
 		{
                                 uint32_t temp;
 				temp=rom[c>>2];
 				temp=((temp&0xFF000000)>>24)|((temp&0x00FF0000)>>8)|((temp&0x0000FF00)<<8)|((temp&0x000000FF)<<24);
 //				temp=((temp>>24)&0xFF)|((temp>>8)&0xFF00)|((temp<<8)&0xFF0000)|((temp<<24)|0xFF000000);
 				rom[c>>2]=temp;
-		}
+		}*/
 #endif
         /*Patch ROM for 8 meg vram!*/
         if (rom[0x14820>>2]==0xE3560001 && /*Check for ROS 4.02 startup*/
