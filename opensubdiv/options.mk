# $NetBSD: options.mk,v 1.9 2015/04/13 23:22:03 othyro Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.opensubdiv
PKG_SUPPORTED_OPTIONS=	opengl ptex doc # cuda tbb opencl dx11
PKG_SUGGESTED_OPTIONS=	opengl
PLIST_VARS+=		opengl doc # ptex has no extra PLIST entries

.include 		"../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mopengl)
.include "../../graphics/glew/buildlink3.mk"
CMAKE_ARGS+=	-DGLEW_LOCATION:PATH=${PREFIX}
PLIST.opengl=	yes
.else
CMAKE_ARGS+=	-DNO_OPENGL:BOOL=ON
.endif

.if !empty(PKG_OPTIONS:Mptex)
.include "../../graphics/ptex/buildlink3.mk"
CMAKE_ARGS+=	-DPTEX_LOCATION:PATH=${PREFIX}
.else
CMAKE_ARGS+=	-DNO_PTEX:BOOL=ON
.endif

.if !empty(PKG_OPTIONS:Mdoc)
BUILD_DEPENDS+=	doxygen>=1.8.9.1:../../devel/doxygen
BUILD_DEPENDS+=	${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils
CMAKE_ARGS+=	-DRST2HTML_EXECUTABLE:PATH=${PREFIX}/bin/rst2html-${PYVERSSUFFIX}.py
.include "../../lang/python/pyversion.mk"
PLIST.doc=	yes
.else
CMAKE_ARGS+=	-DNO_DOC:BOOL=ON
.endif
