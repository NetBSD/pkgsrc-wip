# $NetBSD$

PKG_OPTIONS_VAR=		PKG_OPTIONS.nlopt
PKG_SUPPORTED_OPTIONS=		guile octave python
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

PLIST_SRC=		PLIST

CMAKE_CONFIGURE_ARGS+=		-DNLOPT_SWIG:BOOL=TRUE
CMAKE_CONFIGURE_ARGS+=		-DNLOPT_FORTRAN:BOOL=FALSE	# just builds tests
CMAKE_CONFIGURE_ARGS+=		-DNLOPT_MATLAB:BOOL=FALSE

.if !empty(PKG_OPTIONS:Mguile)
.include "../../lang/guile30/buildlink3.mk"
# DEPENDS+=			guile30-slib>=3.2.1:../../devel/guile30-slib
CMAKE_CONFIGURE_ARGS+=		-DCMAKE_PREFIX_PATH=${PREFIX}/guile/3.0
# CMAKE_INSTALL_RPATH doesn't work, so do it this way.
LDFLAGS+=			${COMPILER_RPATH_FLAG}${PREFIX}/guile/3.0/lib
CMAKE_CONFIGURE_ARGS+=		-DNLOPT_GUILE:BOOL=TRUE
PLIST_SRC+=			PLIST.guile
.else
CMAKE_CONFIGURE_ARGS+=		-DNLOPT_GUILE:BOOL=FALSE
.endif


.if !empty(PKG_OPTIONS:Moctave)
.include "../../math/octave/buildlink3.mk"
CMAKE_CONFIGURE_ARGS+=		-DNLOPT_OCTAVE:BOOL=TRUE
PLIST_SRC+=			PLIST.octave
PLIST_SUBST+=			OCTAVE_VERSION=9.2.0
.else
CMAKE_CONFIGURE_ARGS+=		-DNLOPT_OCTAVE:BOOL=FALSE
.endif


.if !empty(PKG_OPTIONS:Mpython)
.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
CMAKE_CONFIGURE_ARGS+=		-DNLOPT_PYTHON:BOOL=TRUE
PLIST_SRC+=			PLIST.python
PLIST_SUBST+=			PYSITELIB=${PYSITELIB}
PLIST_SUBST+=			PYTHON_VERSION=${PYTHON_VERSION}
.else
CMAKE_CONFIGURE_ARGS+=		-DNLOPT_PYTHON:BOOL=FALSE
.endif
