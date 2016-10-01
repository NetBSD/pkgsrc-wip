$NetBSD$

Do not assume what is not Linux or FreeBSD is OSX.

--- src/video_device.c.orig	2016-10-01 08:28:56.147136487 +0000
+++ src/video_device.c
@@ -30,14 +30,18 @@
 
 #include <vpx/vpx_image.h>
 
-#if defined(__linux__) || defined(__FreeBSD__)
+#if defined(__OSX__)
+#import "osx_video.h"
+#else
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <sys/mman.h>
 #include <fcntl.h>
+#ifdef __Linux__
 #include <linux/videodev2.h>
-#else /* __OSX__ */
-#import "osx_video.h"
+#else
+#include <sys/videoio.h>
+#endif
 #endif
 
 #include "line_info.h"
@@ -65,7 +69,7 @@ typedef struct VideoDevice {
     void *cb_data;                          /* Data to be passed to callback */
     int32_t friend_number;                  /* ToxAV friend number */
 
-#if defined(__linux__) || defined(__FreeBSD__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__)
     int fd;                                 /* File descriptor of video device selected/opened */
     struct v4l2_format fmt;
     struct VideoBuffer *buffers;
@@ -132,7 +136,7 @@ static void yuv420tobgr(uint16_t width, 
     }
 }
 
-#if defined(__linux__) || defined(__FreeBSD__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__)
 static void yuv422to420(uint8_t *plane_y, uint8_t *plane_u, uint8_t *plane_v,
                         uint8_t *input, uint16_t width, uint16_t height)
 {
@@ -170,7 +174,7 @@ static int xioctl(int fh, unsigned long 
     return r;
 }
 
-#endif /* __linux__ */
+#endif
 
 /* Meet devices */
 #ifdef VIDEO
@@ -181,7 +185,10 @@ VideoDeviceError init_video_devices()
 {
     size[vdt_input] = 0;
 
-#if defined(__linux__) || defined(__FreeBSD__)
+#if defined(__OSX__)
+    if( osx_video_init((char**)video_devices_names[vdt_input], &size[vdt_input]) != 0 )
+        return vde_InternalError;
+#else /* not __OSX__*/
 
     for (; size[vdt_input] <= MAX_DEVICES; ++size[vdt_input]) {
         int fd;
@@ -216,11 +223,6 @@ VideoDeviceError init_video_devices()
         }
     }
 
-#else /* __OSX__ */
-
-    if ( osx_video_init((char **)video_devices_names[vdt_input], &size[vdt_input]) != 0 )
-        return vde_InternalError;
-
 #endif
 
     size[vdt_output] = 1;
@@ -271,15 +273,15 @@ VideoDeviceError terminate_video_devices
 VideoDeviceError register_video_device_callback(int32_t friend_number, uint32_t device_idx,
         VideoDataHandleCallback callback, void *data)
 {
-#if defined(__linux__) || defined(__FreeBSD__)
+#if defined(__OSX__)
 
-    if ( size[vdt_input] <= device_idx || !video_devices_running[vdt_input][device_idx]
-            || !video_devices_running[vdt_input][device_idx]->fd )
+    if ( size[vdt_input] <= device_idx || !video_devices_running[vdt_input][device_idx] )
         return vde_InvalidSelection;
 
-#else /* __OSX__ */
+#else /* not __OSX__ */
 
-    if ( size[vdt_input] <= device_idx || !video_devices_running[vdt_input][device_idx] )
+    if ( size[vdt_input] <= device_idx || !video_devices_running[vdt_input][device_idx]
+            || !video_devices_running[vdt_input][device_idx]->fd )
         return vde_InvalidSelection;
 
 #endif
@@ -355,7 +357,13 @@ VideoDeviceError open_video_device(Video
     if ( type == vdt_input ) {
         video_thread_paused = true;
 
-#if defined(__linux__) || defined(__FreeBSD__)
+#if defined(__OSX__)
+        if ( osx_video_open_device(selection, &device->video_width, &device->video_height) != 0 ) {
+            free(device);
+            unlock;
+            return vde_FailedStart;
+        }
+#else /* not __OSX__*/
         /* Open selected device */
         char device_address[] = "/dev/videoXX";
         snprintf(device_address + 10 , sizeof(device_address) - 10, "%i", selection);
@@ -482,14 +490,6 @@ VideoDeviceError open_video_device(Video
             return vde_FailedStart;
         }
 
-#else /* __OSX__ */
-
-        if ( osx_video_open_device(selection, &device->video_width, &device->video_height) != 0 ) {
-            free(device);
-            unlock;
-            return vde_FailedStart;
-        }
-
 #endif
 
         /* Create X11 window associated to device */
@@ -666,7 +666,12 @@ void *video_thread_poll (void *arg) // T
                     uint8_t *u = device->input.planes[1];
                     uint8_t *v = device->input.planes[2];
 
-#if defined(__linux__) || defined(__FreeBSD__)
+#if defined(__OSX__)
+                    if ( osx_video_read_device(y, u, v, &video_width, &video_height) != 0 ) {
+                        unlock;
+                        continue;
+                    }
+#else /* not __OSX__*/
                     struct v4l2_buffer buf;
                     memset(&(buf), 0, sizeof(buf));
 
@@ -683,13 +688,6 @@ void *video_thread_poll (void *arg) // T
                     /* Convert frame image data to YUV420 for ToxAV */
                     yuv422to420(y, u, v, data, video_width, video_height);
 
-#else /* __OSX__*/
-
-                    if ( osx_video_read_device(y, u, v, &video_width, &video_height) != 0 ) {
-                        unlock;
-                        continue;
-                    }
-
 #endif
 
                     /* Send frame data to friend through ToxAV */
@@ -726,14 +724,14 @@ void *video_thread_poll (void *arg) // T
                     XFlush(device->x_display);
                     free(img_data);
 
-#if defined(__linux__) || defined(__FreeBSD__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__)
 
                     if ( -1 == xioctl(device->fd, VIDIOC_QBUF, &buf) ) {
                         unlock;
                         continue;
                     }
 
-#endif /* __linux__ */
+#endif
 
                 }
 
@@ -765,7 +763,10 @@ VideoDeviceError close_video_device(Vide
     if ( !device->ref_count ) {
 
         if ( type == vdt_input ) {
-#if defined(__linux__) || defined(__FreeBSD__)
+#if defined(__OSX__)
+
+            osx_video_close_device(device_idx);
+#else /* not __OSX__ */
             enum v4l2_buf_type buf_type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
 
             if ( -1 == xioctl(device->fd, VIDIOC_STREAMOFF, &buf_type) ) {}
@@ -779,8 +780,6 @@ VideoDeviceError close_video_device(Vide
 
             close(device->fd);
 
-#else /* __OSX__ */
-            osx_video_close_device(device_idx);
 #endif
             vpx_img_free(&device->input);
             XDestroyWindow(device->x_display, device->x_window);
@@ -788,7 +787,7 @@ VideoDeviceError close_video_device(Vide
             XCloseDisplay(device->x_display);
             pthread_mutex_destroy(device->mutex);
 
-#if defined(__linux__) || defined(__FreeBSD__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__)
             free(device->buffers);
 #endif /* __linux__ */
 
