$NetBSD$

* check for X11 libs on all systems that support X11 not just linux
* make QT_FEATURE_xcb_glx available everywhere so that glx can enabled
  on other platforms than linux
* Fix use of system libmd4c

--- src/gui/configure.cmake.orig	2021-01-26 18:29:22.000000000 +0000
+++ src/gui/configure.cmake
@@ -41,6 +41,7 @@ qt_find_package(gbm PROVIDED_TARGETS gbm
 qt_find_package(WrapSystemHarfbuzz 2.6.0 PROVIDED_TARGETS WrapSystemHarfbuzz::WrapSystemHarfbuzz MODULE_NAME gui QMAKE_LIB harfbuzz)
 qt_find_package(Libinput PROVIDED_TARGETS Libinput::Libinput MODULE_NAME gui QMAKE_LIB libinput)
 qt_find_package(JPEG PROVIDED_TARGETS JPEG::JPEG MODULE_NAME gui QMAKE_LIB libjpeg)
+qt_find_package(md4c PROVIDED_TARGETS md4c::md4c MODULE_NAME gui QMAKE_LIB libmd4c)
 qt_find_package(WrapSystemPNG PROVIDED_TARGETS WrapSystemPNG::WrapSystemPNG MODULE_NAME gui QMAKE_LIB libpng)
 if(QT_FEATURE_system_zlib)
     qt_add_qmake_lib_dependency(libpng zlib)
@@ -53,78 +54,78 @@ qt_find_package(Vulkan PROVIDED_TARGETS 
 if((LINUX) OR QT_FIND_ALL_PACKAGES_ALWAYS)
     qt_find_package(Wayland PROVIDED_TARGETS Wayland::Server MODULE_NAME gui QMAKE_LIB wayland_server)
 endif()
-if((LINUX) OR QT_FIND_ALL_PACKAGES_ALWAYS)
+if((X11_PLATFORM) OR QT_FIND_ALL_PACKAGES_ALWAYS)
     qt_find_package(X11 PROVIDED_TARGETS X11::X11 MODULE_NAME gui QMAKE_LIB xlib)
 endif()
-if((LINUX) OR QT_FIND_ALL_PACKAGES_ALWAYS)
+if((X11_PLATFORM) OR QT_FIND_ALL_PACKAGES_ALWAYS)
     qt_find_package(X11 PROVIDED_TARGETS ${X11_SM_LIB} ${X11_ICE_LIB} MODULE_NAME gui QMAKE_LIB x11sm)
 endif()
-if((LINUX) OR QT_FIND_ALL_PACKAGES_ALWAYS)
+if((X11_PLATFORM) OR QT_FIND_ALL_PACKAGES_ALWAYS)
     qt_find_package(XCB 1.11 PROVIDED_TARGETS XCB::XCB MODULE_NAME gui QMAKE_LIB xcb)
 endif()
-if((LINUX) OR QT_FIND_ALL_PACKAGES_ALWAYS)
+if((X11_PLATFORM) OR QT_FIND_ALL_PACKAGES_ALWAYS)
     qt_find_package(XCB 0.3.9 COMPONENTS ICCCM PROVIDED_TARGETS XCB::ICCCM MODULE_NAME gui QMAKE_LIB xcb_icccm)
 endif()
 qt_add_qmake_lib_dependency(xcb_icccm xcb)
-if((LINUX) OR QT_FIND_ALL_PACKAGES_ALWAYS)
+if((X11_PLATFORM) OR QT_FIND_ALL_PACKAGES_ALWAYS)
     qt_find_package(XCB 0.3.9 COMPONENTS IMAGE PROVIDED_TARGETS XCB::IMAGE MODULE_NAME gui QMAKE_LIB xcb_image)
 endif()
 qt_add_qmake_lib_dependency(xcb_image xcb_shm xcb)
-if((LINUX) OR QT_FIND_ALL_PACKAGES_ALWAYS)
+if((X11_PLATFORM) OR QT_FIND_ALL_PACKAGES_ALWAYS)
     qt_find_package(XCB 0.3.9 COMPONENTS KEYSYMS PROVIDED_TARGETS XCB::KEYSYMS MODULE_NAME gui QMAKE_LIB xcb_keysyms)
 endif()
 qt_add_qmake_lib_dependency(xcb_keysyms xcb)
-if((LINUX) OR QT_FIND_ALL_PACKAGES_ALWAYS)
+if((X11_PLATFORM) OR QT_FIND_ALL_PACKAGES_ALWAYS)
     qt_find_package(XCB 0.3.9 COMPONENTS RENDERUTIL PROVIDED_TARGETS XCB::RENDERUTIL MODULE_NAME gui QMAKE_LIB xcb_renderutil)
 endif()
 qt_add_qmake_lib_dependency(xcb_renderutil xcb xcb_render)
-if((LINUX) OR QT_FIND_ALL_PACKAGES_ALWAYS)
+if((X11_PLATFORM) OR QT_FIND_ALL_PACKAGES_ALWAYS)
     qt_find_package(XCB COMPONENTS RANDR PROVIDED_TARGETS XCB::RANDR MODULE_NAME gui QMAKE_LIB xcb_randr)
 endif()
 qt_add_qmake_lib_dependency(xcb_randr xcb)
-if((LINUX) OR QT_FIND_ALL_PACKAGES_ALWAYS)
+if((X11_PLATFORM) OR QT_FIND_ALL_PACKAGES_ALWAYS)
     qt_find_package(XCB COMPONENTS SHAPE PROVIDED_TARGETS XCB::SHAPE MODULE_NAME gui QMAKE_LIB xcb_shape)
 endif()
 qt_add_qmake_lib_dependency(xcb_shape xcb)
-if((LINUX) OR QT_FIND_ALL_PACKAGES_ALWAYS)
+if((X11_PLARFORM) OR QT_FIND_ALL_PACKAGES_ALWAYS)
     qt_find_package(XCB COMPONENTS SHM PROVIDED_TARGETS XCB::SHM MODULE_NAME gui QMAKE_LIB xcb_shm)
 endif()
 qt_add_qmake_lib_dependency(xcb_shm xcb)
-if((LINUX) OR QT_FIND_ALL_PACKAGES_ALWAYS)
+if((X11_PLATFORM) OR QT_FIND_ALL_PACKAGES_ALWAYS)
     qt_find_package(XCB COMPONENTS SYNC PROVIDED_TARGETS XCB::SYNC MODULE_NAME gui QMAKE_LIB xcb_sync)
 endif()
 qt_add_qmake_lib_dependency(xcb_sync xcb)
-if((LINUX) OR QT_FIND_ALL_PACKAGES_ALWAYS)
+if((X11_PLATFORM) OR QT_FIND_ALL_PACKAGES_ALWAYS)
     qt_find_package(XCB COMPONENTS XFIXES PROVIDED_TARGETS XCB::XFIXES MODULE_NAME gui QMAKE_LIB xcb_xfixes)
 endif()
 qt_add_qmake_lib_dependency(xcb_xfixes xcb)
-if((LINUX) OR QT_FIND_ALL_PACKAGES_ALWAYS)
+if((X11_PLATFORM) OR QT_FIND_ALL_PACKAGES_ALWAYS)
     qt_find_package(X11_XCB PROVIDED_TARGETS X11::XCB MODULE_NAME gui QMAKE_LIB xcb_xlib)
 endif()
 qt_add_qmake_lib_dependency(xcb_xlib xcb xlib)
-if((LINUX) OR QT_FIND_ALL_PACKAGES_ALWAYS)
+if((X11_PLATFORM) OR QT_FIND_ALL_PACKAGES_ALWAYS)
     qt_find_package(XCB COMPONENTS XKB PROVIDED_TARGETS XCB::XKB MODULE_NAME gui QMAKE_LIB xcb_xkb)
 endif()
 qt_add_qmake_lib_dependency(xcb_xkb xcb)
-if((LINUX) OR QT_FIND_ALL_PACKAGES_ALWAYS)
+if((X11_PLATFORM) OR QT_FIND_ALL_PACKAGES_ALWAYS)
     qt_find_package(XCB COMPONENTS RENDER PROVIDED_TARGETS XCB::RENDER MODULE_NAME gui QMAKE_LIB xcb_render)
 endif()
 qt_add_qmake_lib_dependency(xcb_render xcb)
-if((LINUX) OR QT_FIND_ALL_PACKAGES_ALWAYS)
+if((X11_PLATFORM) OR QT_FIND_ALL_PACKAGES_ALWAYS)
     qt_find_package(XCB COMPONENTS GLX PROVIDED_TARGETS XCB::GLX MODULE_NAME gui QMAKE_LIB xcb_glx)
 endif()
 qt_add_qmake_lib_dependency(xcb_glx xcb)
-if((LINUX) OR QT_FIND_ALL_PACKAGES_ALWAYS)
+if((X11_PLATFORM) OR QT_FIND_ALL_PACKAGES_ALWAYS)
     qt_find_package(XCB 1.12 COMPONENTS XINPUT PROVIDED_TARGETS XCB::XINPUT MODULE_NAME gui QMAKE_LIB xcb_xinput)
 endif()
 qt_add_qmake_lib_dependency(xcb_xinput xcb)
-if((LINUX) OR QT_FIND_ALL_PACKAGES_ALWAYS)
+if((X11_PLATFORM) OR QT_FIND_ALL_PACKAGES_ALWAYS)
     qt_find_package(XKB 0.5.0 PROVIDED_TARGETS XKB::XKB MODULE_NAME gui QMAKE_LIB xkbcommon)
 endif()
-if((LINUX) OR QT_FIND_ALL_PACKAGES_ALWAYS)
+if((X11_PLATFORM) OR QT_FIND_ALL_PACKAGES_ALWAYS)
     qt_find_package(XKB_COMMON_X11 0.5.0 PROVIDED_TARGETS PkgConfig::XKB_COMMON_X11 MODULE_NAME gui QMAKE_LIB xkbcommon_x11)
 endif()
-if((LINUX) OR QT_FIND_ALL_PACKAGES_ALWAYS)
+if((X11_PLATFORM) OR QT_FIND_ALL_PACKAGES_ALWAYS)
     qt_find_package(XRender 0.6 PROVIDED_TARGETS PkgConfig::XRender MODULE_NAME gui QMAKE_LIB xrender)
 endif()
 qt_add_qmake_lib_dependency(xrender xlib)
@@ -891,7 +892,7 @@ qt_feature("xcb-glx-plugin" PRIVATE
     CONDITION QT_FEATURE_xcb_xlib AND QT_FEATURE_opengl AND NOT QT_FEATURE_opengles2
     EMIT_IF QT_FEATURE_xcb
 )
-qt_feature("xcb-glx" PRIVATE
+qt_feature("xcb-glx" PUBLIC
     LABEL "  XCB GLX"
     CONDITION XCB_GLX_FOUND
     EMIT_IF QT_FEATURE_xcb AND QT_FEATURE_xcb_glx_plugin
@@ -957,7 +958,7 @@ qt_feature("textmarkdownreader" PUBLIC
 qt_feature("system-textmarkdownreader" PUBLIC
     SECTION "Kernel"
     LABEL "  Using system libmd4c"
-    CONDITION libs.libmd4c OR FIXME
+    CONDITION QT_FEATURE_textmarkdownreader AND TARGET md4c::md4c
     ENABLE INPUT_libmd4c STREQUAL 'system'
     DISABLE INPUT_libmd4c STREQUAL 'qt'
 )
