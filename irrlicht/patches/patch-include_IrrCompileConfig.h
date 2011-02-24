$NetBSD: patch-include_IrrCompileConfig.h,v 1.1.1.1 2011/02/24 15:12:08 pallegra Exp $

--- include/IrrCompileConfig.h.orig	2010-10-24 12:26:28.000000000 +0000
+++ include/IrrCompileConfig.h
@@ -94,7 +94,7 @@
 #endif
 
 //! Define _IRR_COMPILE_WITH_JOYSTICK_SUPPORT_ if you want joystick events.
-#define _IRR_COMPILE_WITH_JOYSTICK_EVENTS_
+//#define _IRR_COMPILE_WITH_JOYSTICK_EVENTS_
 
 //! Maximum number of texture an SMaterial can have, up to 8 are supported by Irrlicht.
 #define _IRR_MATERIAL_MAX_TEXTURES_ 4
@@ -176,7 +176,7 @@ the engine will no longer read .jpeg ima
 //! Define _IRR_USE_NON_SYSTEM_JPEG_LIB_ to let irrlicht use the jpeglib which comes with irrlicht.
 /** If this is commented out, Irrlicht will try to compile using the jpeg lib installed in the system.
 	This is only used when _IRR_COMPILE_WITH_LIBJPEG_ is defined. */
-#define _IRR_USE_NON_SYSTEM_JPEG_LIB_
+//#define _IRR_USE_NON_SYSTEM_JPEG_LIB_
 
 
 //! Define _IRR_COMPILE_WITH_LIBPNG_ to enable compiling the engine using libpng.
@@ -187,7 +187,7 @@ the engine will no longer read .png imag
 //! Define _IRR_USE_NON_SYSTEM_LIBPNG_ to let irrlicht use the libpng which comes with irrlicht.
 /** If this is commented out, Irrlicht will try to compile using the libpng installed in the system.
 	This is only used when _IRR_COMPILE_WITH_LIBPNG_ is defined. */
-#define _IRR_USE_NON_SYSTEM_LIB_PNG_
+//#define _IRR_USE_NON_SYSTEM_LIB_PNG_
 
 
 //! Define _IRR_D3D_NO_SHADER_DEBUGGING to disable shader debugging in D3D9
@@ -347,7 +347,7 @@ ones. */
 //! Define _IRR_USE_NON_SYSTEM_ZLIB_ to let irrlicht use the zlib which comes with irrlicht.
 /** If this is commented out, Irrlicht will try to compile using the zlib
 installed on the system. This is only used when _IRR_COMPILE_WITH_ZLIB_ is
-defined. */
+//defined. */
 #define _IRR_USE_NON_SYSTEM_ZLIB_
 //! Define _IRR_COMPILE_WITH_ZIP_ENCRYPTION_ if you want to read AES-encrypted ZIP archives
 #define _IRR_COMPILE_WITH_ZIP_ENCRYPTION_
@@ -360,7 +360,7 @@ library. */
 /** If this is commented out, Irrlicht will try to compile using the bzlib
 installed on the system. This is only used when _IRR_COMPILE_WITH_BZLIB_ is
 defined. */
-#define _IRR_USE_NON_SYSTEM_BZLIB_
+//#define _IRR_USE_NON_SYSTEM_BZLIB_
 //! Define _IRR_COMPILE_WITH_LZMA_ if you want to use LZMA compressed zip files.
 /** LZMA is a very efficient compression code, known from 7zip. Irrlicht
 currently only supports zip archives, though. */
