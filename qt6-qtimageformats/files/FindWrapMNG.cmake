#
# We have to do this instead of using pkgconfig directly in configure.cmake.
# If we use it directly in configure.cmake cmake complains about 
# CMAKE_FIND_LIBRARY_PREFIXES and CMAKE_FIND_LIBRARY_SUFFIXES not being
# set and that add_library used for imported target creation in
# pkg_check_modules is not scriptable.
# A version of this has been filed upstream
# https://codereview.qt-project.org/c/qt/qtimageformats/+/335598
#
find_package(PkgConfig)
pkg_check_modules(MNG IMPORTED_TARGET libmng>1.0.9)
if(TARGET PkgConfig::MNG)
set(WrapMNG_FOUND TRUE)
endif()
