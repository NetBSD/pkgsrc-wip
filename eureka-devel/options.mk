# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.eureka
PKG_SUPPORTED_OPTIONS=	opengl xdg-utils
PKG_SUGGESTED_OPTIONS=	opengl xdg-utils

.include "../../mk/bsd.options.mk"

.include "../../wip/fltk14-devel/buildlink3.mk"

# Add missing include path for FLTK (eureka does not use fltk-config)
.if empty(PKG_OPTIONS.fltk14-devel:Mcairo)
CXXFLAGS=-I"${PREFIX}/include/cairo"
.endif

# opengl: Use OpenGL for rendering
# If FLTK is compiled without opengl option, it is always disabled here too.
# If FLTK is compiled with opengl option, disabling it here allows to force
# usage of the software renderer (recommended without hardware acceleration).
.if empty(PKG_OPTIONS.fltk14-devel:Mopengl) || empty(PKG_OPTIONS:Mopengl)
CMAKE_ARGS+=	-DENABLE_OPENGL=off
.endif
# xdg-utils: Create dependency for xdg-utils (Portland project)
# Can be used by FLTK for fl_open_uri() on X11.
.if !empty(PKG_OPTIONS:Mxdg-utils)
DEPENDS+=	xdg-utils>=1.1:../../misc/xdg-utils
.endif
