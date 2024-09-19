# xrandr
if(ENABLE_X11 AND X_FOUND AND XRANDR_FOUND)
  find_package(X QUIET)
  find_package(XRandR QUIET)
  add_executable(${APP_NAME_LC}-xrandr ${CORE_SOURCE_DIR}/xbmc-xrandr.c)
  target_link_libraries(${APP_NAME_LC}-xrandr ${SYSTEM_LDFLAGS} ${X_LIBRARIES} m ${XRANDR_LIBRARIES})
endif()
