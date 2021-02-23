$NetBSD$

* add function so that libraries such as socket and nsl 
  can be added to tests

--- cmake/QtFeature.cmake.orig	2021-01-26 18:29:22.000000000 +0000
+++ cmake/QtFeature.cmake
@@ -1023,4 +1023,21 @@ function(qt_make_features_available targ
     endforeach()
 endfunction()
 
+# function to add libs to an INTERFACE library target if the lib exists,
+# needed because qt_config_compile test only accepts imported targets in its
+# LIBRARIES argument if PROJECT_PATH is not set.
+function(qt_test_lib_target)
+qt_parse_all_arguments(arg "qt_test_lib_target" "" "TARGET" "LIBS" ${ARGN})
 
+if(TARGET ${arg_TARGET})
+return()
+endif()
+add_library(${arg_TARGET} INTERFACE IMPORTED)
+foreach(_lib ${arg_LIBS})
+find_library(fl_${_lib} NAMES ${_lib})
+if(fl_${_lib})
+target_link_libraries(${arg_TARGET} INTERFACE ${fl_${_lib}})
+endif()
+endforeach()
+
+endfunction()
