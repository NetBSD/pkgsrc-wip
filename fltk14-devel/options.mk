# $NetBSD$

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS_VAR=	PKG_OPTIONS.fltk14
PKG_SUPPORTED_OPTIONS=	opengl pango x11 xdbe xft2 xinerama
# FLTK has native backends for macOS and Windows (Cygwin)
# Enabling the "x11" option forces X11 backend on such systems.
# Most users want the native backends.
.if ${OPSYS} == "Darwin" || ${OPSYS} == "Cygwin"
PKG_SUGGESTED_OPTIONS=	opengl pango xdbe xft2 xinerama
.else
PKG_SUGGESTED_OPTIONS=	opengl pango x11 xdbe xft2 xinerama
.endif
PLIST_VARS+=		opengl

.include "../../mk/bsd.options.mk"

# "opengl" option: Enable support for OpenGL based rendering
# Disabling this option removes expensive dependencies for X11 backend.
# Attention: Some packages that use FLTK need this option (disable with care)
.if !empty(PKG_OPTIONS:Mopengl)
.  if !empty(PKG_OPTIONS:Mx11)
.    include "../../graphics/MesaLib/buildlink3.mk"
.    include "../../graphics/glu/buildlink3.mk"
.  endif
CONFIGURE_ARGS+=	--enable-gl
PLIST.opengl=		yes
.else
CONFIGURE_ARGS+=	--disable-gl
.endif

# "pango" option [X11 backend]: Use Pango for client side font rendering
# This option enables glyph substitution (mixing of multiple fonts).
# Most users want that, but it adds additional dependencies compared to
# FLTK 1.3 (disable this option to get the former behaviour).
# Attention: This option requires the "xft2" option to be enabled too.
.if !empty(PKG_OPTIONS:Mpango)
.  if empty(PKG_OPTIONS:Mxft2)
PKG_FAIL_REASON+=	"pango option requires xft2 option."
.  endif
.  if !empty(PKG_OPTIONS:Mx11)
.    include "../../devel/pango/buildlink3.mk"
.  endif
CONFIGURE_ARGS+=	--enable-pango
.else
CONFIGURE_ARGS+=	--disable-pango
.endif

# "x11" option [X11 backend]: Use X11 backend
# For some systems there are native backends available, do not use them.
# Attention: Forcing X11 backend requires X Window system to be installed.
.if !empty(PKG_OPTIONS:Mx11)
.  include "../../x11/libX11/buildlink3.mk"
.  include "../../x11/libXcursor/buildlink3.mk"
.  include "../../x11/libXext/buildlink3.mk"
.  include "../../x11/libXfixes/buildlink3.mk"
.  include "../../x11/libXrender/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-x11
.else
CONFIGURE_ARGS+=	--disable-x11
.endif

# "xdbe" option [X11 backend]: Use X double buffer extension (DBE)
# On older systems double buffering can be very slow. Disabling this option can
# make the GUI more responsive. The drawback is potential flickering, e.g. in
# a text field while a scrollbar is moved.
.if !empty(PKG_OPTIONS:Mxdbe)
CONFIGURE_ARGS+=	--enable-xdbe
.else
CONFIGURE_ARGS+=	--disable-xdbe
.endif

# "xft2" option [X11 backend]: Use X FreeType interface library
# Enables client side font rendering. Most users want that, because it works
# better with Unicode.
# Disabling this option uses the original core X11 font system and removes all
# font related dependencies (the X server is used for font rendering and client
# programs become extremely lightweight).
# Attention: X servers may be misconfigured for core fonts (disable with care).
.if !empty(PKG_OPTIONS:Mxft2)
.  if !empty(PKG_OPTIONS:Mx11)
.    include "../../x11/libXft/buildlink3.mk"
.  endif
CONFIGURE_ARGS+=	--enable-xft
.else
CONFIGURE_ARGS+=	--disable-xft
.endif

# "xinerama" option [X11 backend]: Use X11 XINERAMA extension
# Enables support for two or more physical displays.
.if !empty(PKG_OPTIONS:Mxinerama)
.  if !empty(PKG_OPTIONS:Mx11)
.    include "../../x11/libXinerama/buildlink3.mk"
.  endif
CONFIGURE_ARGS+=	--enable-xinerama
.else
CONFIGURE_ARGS+=	--disable-xinerama
.endif
