$NetBSD$

--- cmake/external.cmake.orig	2021-02-03 11:42:41.000000000 +0000
+++ cmake/external.cmake
@@ -123,6 +123,68 @@ function(link_libpulse target_name)
     endif()
 endfunction()
 
+# usrsctp
+function(link_usrsctp target_name)
+    if (TG_OWT_PACKAGED_BUILD)
+        find_package(PkgConfig REQUIRED)
+		pkg_check_modules(USRSCTP REQUIRED usrsctp)
+		target_link_libraries(${target_name} PRIVATE ${USRSCTP_LIBRARIES})
+    endif()
+endfunction()
+
+# srtp
+set(TG_OWT_SRTP_INCLUDE_PATH "" CACHE STRING "Include path for srtp2.")
+function(link_srtp target_name)
+    if (TG_OWT_PACKAGED_BUILD)
+		find_library(SRTP NAMES srtp2)
+		target_link_libraries(${target_name} PRIVATE ${SRTP_LIBRARIES})
+    endif()
+endfunction()
+
+# libvpx
+function(link_libvpx target_name)
+    if (TG_OWT_PACKAGED_BUILD)
+        find_package(PkgConfig REQUIRED)
+		pkg_check_modules(LIBVPX REQUIRED vpx)
+		target_link_libraries(${target_name} PRIVATE ${LIBVPX_LIBRARIES})
+    endif()
+endfunction()
+
+# libevent
+function(link_libevent target_name)
+    if (TG_OWT_PACKAGED_BUILD)
+        find_package(PkgConfig REQUIRED)
+		pkg_check_modules(LIBEVENT REQUIRED libevent)
+		target_link_libraries(${target_name} PRIVATE ${LIBEVENT_LIBRARIES})
+    endif()
+endfunction()
+
+# openh264
+function(link_openh264 target_name)
+    if (TG_OWT_PACKAGED_BUILD)
+        find_package(PkgConfig REQUIRED)
+		pkg_check_modules(LIBEVENT REQUIRED openh264)
+		target_link_libraries(${target_name} PRIVATE ${LIBOPENH264_LIBRARIES})
+    endif()
+endfunction()
+
+#libabsl
+function(link_libabsl target_name)
+    if (TG_OWT_PACKAGED_BUILD)
+		find_library(LIBABSL NAMES absl_base)
+		target_link_libraries(${target_name} PRIVATE ${ABSL_LIBRARIES})
+		add_library(tg_owt::libabsl ALIAS libabsl)
+    endif()
+endfunction()
+
+#libyuv
+function(link_libyuv target_name)
+    if (TG_OWT_PACKAGED_BUILD)
+		find_library(LIBYUV NAMES yuv)
+		target_link_libraries(${target_name} PRIVATE ${YUV_LIBRARIES})
+    endif()
+endfunction()
+
 # dl
 function(link_dl target_name)
     if (TG_OWT_PACKAGED_BUILD)
