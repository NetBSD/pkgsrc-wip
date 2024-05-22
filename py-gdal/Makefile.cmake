# The overall plan is to run cmake in the package root, and then just
# build the bindings.

# The supplied cmakefiles are buggy in that absent spatialite,
# FindSPATIALITE will find an empty version string and then invoke a
# REGEX operation with the wrong number of arguments.  This is too
# hard to fix, so tell the build not to build things, and then
# specifically not to use spatialite.  Observting that this isn't
# enough, set a fake version to avoid cmake trying to find it (badly).
# This is ok because we don't actually want it at all.  Not filed
# upstream, hoping this isn't as bad in 3.9.
CMAKE_CONFIGURE_ARGS+=	-DGDAL_BUILD_OPTIONAL_DRIVERS=OFF
CMAKE_CONFIGURE_ARGS+=	-DOGR_BUILD_OPTIONAL_DRIVERS=OFF
CMAKE_CONFIGURE_ARGS+=	-DGDAL_USE_SPATIALITE=OFF
CMAKE_CONFIGURE_ARGS+=	-DSPATIALITE_VERSION_STRING=0.0-missing

BUILD_DIRS=		swig/python

.include "../../devel/cmake/build.mk"

