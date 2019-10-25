# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.fltk14
PKG_SUPPORTED_OPTIONS=	opengl pango xdbe xft2 xinerama
PKG_SUGGESTED_OPTIONS=	opengl pango xdbe xft2 xinerama
PLIST_VARS+=		opengl

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

# "opengl" option: Enable support for OpenGL based rendering
# Disabling this option removes the expensive Mesa dependency.
# Attention: Some packages that use FLTK need this option (disable with care)
.if !empty(PKG_OPTIONS:Mopengl)
.  if ${OPSYS} != "Darwin"
.     include "../../graphics/MesaLib/buildlink3.mk"
.     include "../../graphics/glu/buildlink3.mk"
.  endif
CONFIGURE_ARGS+=	--enable-gl
PLIST.opengl=		yes
.else
CONFIGURE_ARGS+=	--disable-gl
.endif

# "pango" option: Use Pango for client side font rendering with X11 backend
# This option enables glyph substitution (mixing of multiple fonts) for the X11
# backend. Most users want that, but it adds additional dependencies compared
# to FLTK 1.3 (disable this option to get the former behaviour).
# Attention: This option requires the "xft2" option to be enabled too.
.if !empty(PKG_OPTIONS:Mpango)
.  if empty(PKG_OPTIONS:Mxft2)
PKG_FAIL_REASON+=	"pango option requires xft2 option."
.  endif
.  if ${OPSYS} != "Darwin"
#     Untested: Cocoa backend on macOS should use Core Text instead
.     include "../../devel/pango/buildlink3.mk"
.  endif
CONFIGURE_ARGS+=	--enable-pango
.else
CONFIGURE_ARGS+=	--disable-pango
.endif

# "xdbe" option: Use X11 double buffer extension
# On older systems double buffering can be very slow. Disabling this option can
# make the GUI more responsive. The drawback is potential flickering, e.g. in
# a text field while a scrollbar is moved.
# Note: This extension is implemented in X servers, no client library required.
.if !empty(PKG_OPTIONS:Mxdbe)
CONFIGURE_ARGS+=	--enable-xdbe
.else
CONFIGURE_ARGS+=	--disable-xdbe
.endif

# "xft2" option: Use client side font rendering for X11 backend
# Disabling this option uses the original core X11 font system and removes all
# font related dependencies (the X server is used for font rendering and client
# programs become extremely lightweight).
# Attention: X servers may be misconfigured for core fonts (disable with care).
.if !empty(PKG_OPTIONS:Mxft2)
.  if ${OPSYS} != "Darwin"
#     Untested: Cocoa backend on macOS should use Core Text instead
.     include "../../x11/libXft/buildlink3.mk"
.  endif
CONFIGURE_ARGS+=	--enable-xft
.else
CONFIGURE_ARGS+=	--disable-xft
.endif

# "xinerama" option: Enable support for two or more physical displays
.if !empty(PKG_OPTIONS:Mxinerama)
.  if ${OPSYS} != "Darwin"
.     include "../../x11/libXinerama/buildlink3.mk"
.  endif
CONFIGURE_ARGS+=	--enable-xinerama
.else
CONFIGURE_ARGS+=	--disable-xinerama
.endif
