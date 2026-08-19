$NetBSD$

Use system libyuv instead of bundled submodule (empty in GitHub tarball).
Create symlinks in src/third_party/libyuv/include so source files
referencing bundled include paths resolve to system headers.

Wrap the interface include dir and library in BUILD_INTERFACE/INSTALL_INTERFACE
generator expressions so the installed CMake export does not bake absolute
pkgsrc WRKDIR buildlink paths into tg_owtTargets.cmake; consumers link
libyuv via their own buildlink3.mk instead.

--- cmake/libyuv.cmake.orig	2026-04-09 10:24:34.000000000 +0300
+++ cmake/libyuv.cmake
@@ -1,158 +1,27 @@
-add_library(libyuv OBJECT EXCLUDE_FROM_ALL)
-init_target(libyuv)
+add_library(libyuv INTERFACE)
 add_library(tg_owt::libyuv ALIAS libyuv)

-link_libjpeg(libyuv)
+find_path(LIBYUV_INCLUDE_DIR libyuv.h PATH_SUFFIXES libyuv)
+find_library(LIBYUV_LIBRARY NAMES yuv)

-set(libyuv_loc ${third_party_loc}/libyuv)
-
-nice_target_sources(libyuv ${libyuv_loc}
-PRIVATE
-    include/libyuv.h
-    include/libyuv/basic_types.h
-    include/libyuv/compare.h
-    include/libyuv/compare_row.h
-    include/libyuv/convert.h
-    include/libyuv/convert_argb.h
-    include/libyuv/convert_from.h
-    include/libyuv/convert_from_argb.h
-    include/libyuv/cpu_id.h
-    include/libyuv/loongson_intrinsics.h
-    include/libyuv/macros_msa.h
-    include/libyuv/mjpeg_decoder.h
-    include/libyuv/planar_functions.h
-    include/libyuv/rotate.h
-    include/libyuv/rotate_argb.h
-    include/libyuv/rotate_row.h
-    include/libyuv/row.h
-    include/libyuv/scale.h
-    include/libyuv/scale_argb.h
-    include/libyuv/scale_rgb.h
-    include/libyuv/scale_row.h
-    include/libyuv/scale_uv.h
-    include/libyuv/version.h
-    include/libyuv/video_common.h
-
-    # Source Files
-    source/compare.cc
-    source/compare_common.cc
-    source/compare_gcc.cc
-    source/compare_win.cc
-    source/convert.cc
-    source/convert_argb.cc
-    source/convert_from.cc
-    source/convert_from_argb.cc
-    source/convert_jpeg.cc
-    source/convert_to_argb.cc
-    source/convert_to_i420.cc
-    source/cpu_id.cc
-    source/mjpeg_decoder.cc
-    source/mjpeg_validate.cc
-    source/planar_functions.cc
-    source/rotate.cc
-    source/rotate_any.cc
-    source/rotate_argb.cc
-    source/rotate_common.cc
-    source/rotate_gcc.cc
-    source/rotate_win.cc
-    source/row_any.cc
-    source/row_common.cc
-    source/row_gcc.cc
-    source/row_win.cc
-    source/scale.cc
-    source/scale_any.cc
-    source/scale_argb.cc
-    source/scale_common.cc
-    source/scale_gcc.cc
-    source/scale_uv.cc
-    source/scale_win.cc
-    source/video_common.cc
-
-    # LSX
-    source/rotate_lsx.cc
-    source/row_lasx.cc
-    source/row_lsx.cc
-    source/scale_lsx.cc
-
-    # ARM neon
-    source/compare_neon.cc
-    source/compare_neon64.cc
-    source/rotate_neon.cc
-    source/rotate_neon64.cc
-    source/row_neon.cc
-    source/row_neon64.cc
-    source/scale_neon.cc
-    source/scale_neon64.cc
-
-    # MSA Source Files
-    source/compare_msa.cc
-    source/rotate_msa.cc
-    source/row_msa.cc
-    source/scale_msa.cc
-
-    # RISC-V RVV
-    source/row_rvv.cc
-    source/scale_rvv.cc
+target_include_directories(libyuv
+INTERFACE
+    $<BUILD_INTERFACE:${LIBYUV_INCLUDE_DIR}>
 )

-remove_target_sources(libyuv ${libyuv_loc}
-
-    # MSA Source Files
-    source/compare_msa.cc
-    source/rotate_msa.cc
-    source/row_msa.cc
-    source/scale_msa.cc
+target_link_libraries(libyuv
+INTERFACE
+    $<BUILD_INTERFACE:${LIBYUV_LIBRARY}>
+    $<INSTALL_INTERFACE:yuv>
 )

-if (arm_use_neon)
-    target_compile_definitions(libyuv
-    PRIVATE
-        LIBYUV_NEON
-    )
-else()
-    target_compile_definitions(libyuv
-    PRIVATE
-        LIBYUV_DISABLE_NEON
-    )
-    remove_target_sources(libyuv ${libyuv_loc}
-
-        # ARM neon
-        source/compare_neon.cc
-        source/compare_neon64.cc
-        source/rotate_neon.cc
-        source/rotate_neon64.cc
-        source/row_neon.cc
-        source/row_neon64.cc
-        source/scale_neon.cc
-        source/scale_neon64.cc
-    )
+# Create symlinks in src/third_party/libyuv/include so source files using
+# the bundled include paths resolve to system libyuv headers.
+set(libyuv_shim_dir ${CMAKE_CURRENT_SOURCE_DIR}/src/third_party/libyuv/include)
+file(MAKE_DIRECTORY ${libyuv_shim_dir})
+if (NOT EXISTS ${libyuv_shim_dir}/libyuv)
+    file(CREATE_LINK ${LIBYUV_INCLUDE_DIR}/libyuv ${libyuv_shim_dir}/libyuv SYMBOLIC)
 endif()
-
-if (riscv_use_rvv)
-    target_compile_definitions(libyuv
-    PRIVATE
-        USE_RVV
-    )
-else()
-    target_compile_definitions(libyuv
-    PRIVATE
-        LIBYUV_DISABLE_RVV
-    )
-    remove_target_sources(libyuv ${libyuv_loc}
-
-        # RISC-V RVV
-        source/row_rvv.cc
-        source/scale_rvv.cc
-    )
+if (NOT EXISTS ${libyuv_shim_dir}/libyuv.h)
+    file(CREATE_LINK ${LIBYUV_INCLUDE_DIR}/libyuv.h ${libyuv_shim_dir}/libyuv.h SYMBOLIC)
 endif()
-
-target_include_directories(libyuv
-PUBLIC
-    $<BUILD_INTERFACE:${libyuv_loc}/include>
-    $<INSTALL_INTERFACE:${webrtc_includedir}/third_party/libyuv/include>
-)
-
-target_compile_definitions(libyuv
-PRIVATE
-    HAVE_JPEG
-)
