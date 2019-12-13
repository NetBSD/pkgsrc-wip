# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.eureka-devel
PKG_SUPPORTED_OPTIONS=	opengl xdg-utils
PKG_SUGGESTED_OPTIONS=	opengl xdg-utils

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

# opengl: Use OpenGL for drawing
# If FLTK is compiled without opengl option, it is ignored.
# If FLTK is compiled with opengl option, removing it here allows to force usage
# of the software renderer (recommended without hardware acceleration).
.if !empty(PKG_OPTIONS:Mopengl)
# Handled by Makefile because the FLTK dependency (not included here yet)
.endif

# xdg-utils: Create dependency for xdg-utils (Portland project)
# Can be used by FLTK for fl_open_uri() on X11
.if !empty(PKG_OPTIONS:Mxdg-utils)
DEPENDS+=	xdg-utils>=1.1:../../misc/xdg-utils
.endif
