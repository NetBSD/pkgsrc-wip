$NetBSD$

Do not assume what is not Linux or FreeBSD is OSX.

--- src/video_device.c.orig	2017-11-15 18:32:08.108030377 +0000
+++ src/video_device.c
@@ -174,7 +174,7 @@ static int xioctl(int fh, unsigned long 
     return r;
 }
 
-#endif /* __linux__ */
+#endif
 
 /* Meet devices */
 #ifdef VIDEO
@@ -185,7 +185,10 @@ VideoDeviceError init_video_devices()
 {
     size[vdt_input] = 0;
 
-#if defined(__linux__) || SYSTEM == BSD
+#if defined(__OSX__)
+    if( osx_video_init((char**)video_devices_names[vdt_input], &size[vdt_input]) != 0 )
+        return vde_InternalError;
+#else /* not __OSX__*/
 
     for (; size[vdt_input] <= MAX_DEVICES; ++size[vdt_input]) {
         int fd;
@@ -220,11 +223,6 @@ VideoDeviceError init_video_devices()
         }
     }
 
-#else /* __OSX__ */
-
-    if ( osx_video_init((char **)video_devices_names[vdt_input], &size[vdt_input]) != 0 )
-        return vde_InternalError;
-
 #endif
 
     size[vdt_output] = 1;
@@ -275,15 +273,15 @@ VideoDeviceError terminate_video_devices
 VideoDeviceError register_video_device_callback(int32_t friend_number, uint32_t device_idx,
         VideoDataHandleCallback callback, void *data)
 {
-#if defined(__linux__) || SYSTEM == BSD
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
@@ -359,7 +357,13 @@ VideoDeviceError open_video_device(Video
     if ( type == vdt_input ) {
         video_thread_paused = true;
 
-#if defined(__linux__) || SYSTEM == BSD
+#if defined(__OSX__)
+        if ( osx_video_open_device(selection, &device->video_width, &device->video_height) != 0 ) {
+            free(device);
+            unlock;
+            return vde_FailedStart;
+        }
+#else /* not __OSX__*/
         /* Open selected device */
         char device_address[] = "/dev/videoXX";
         snprintf(device_address + 10, sizeof(device_address) - 10, "%i", selection);
@@ -486,14 +490,6 @@ VideoDeviceError open_video_device(Video
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
@@ -670,7 +666,12 @@ void *video_thread_poll (void *arg) // T
                     uint8_t *u = device->input.planes[1];
                     uint8_t *v = device->input.planes[2];
 
-#if defined(__linux__) || SYSTEM == BSD
+#if defined(__OSX__)
+                    if ( osx_video_read_device(y, u, v, &video_width, &video_height) != 0 ) {
+                        unlock;
+                        continue;
+                    }
+#else /* not __OSX__*/
                     struct v4l2_buffer buf;
                     memset(&(buf), 0, sizeof(buf));
 
@@ -687,13 +688,6 @@ void *video_thread_poll (void *arg) // T
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
@@ -769,7 +763,10 @@ VideoDeviceError close_video_device(Vide
     if ( !device->ref_count ) {
 
         if ( type == vdt_input ) {
-#if defined(__linux__) || SYSTEM == BSD
+#if defined(__OSX__)
+
+            osx_video_close_device(device_idx);
+#else /* not __OSX__ */
             enum v4l2_buf_type buf_type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
 
             if ( -1 == xioctl(device->fd, VIDIOC_STREAMOFF, &buf_type) ) {}
@@ -783,8 +780,6 @@ VideoDeviceError close_video_device(Vide
 
             close(device->fd);
 
-#else /* __OSX__ */
-            osx_video_close_device(device_idx);
 #endif
             vpx_img_free(&device->input);
             XDestroyWindow(device->x_display, device->x_window);
