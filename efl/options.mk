# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.efl
PKG_SUPPORTED_OPTIONS=	debug g-mainloop gcc8
PKG_SUGGESTED_OPTIONS=	g-mainloop

.include "../../mk/bsd.options.mk"

# Build with debug options
.if !empty(PKG_OPTIONS:Mdebug)
MESON_ARGS+=	-Ddebug-threads=true
CFLAGS+=	-g -ggdb3
.endif

# Use glib to run the main loop in efl
.if !empty(PKG_OPTIONS:Mg-mainloop)
MESON_ARGS+=	-Dglib=true
MESON_ARGS+=	-Dg-mainloop=true
.include "../../devel/libuv/buildlink3.mk"
.endif

# Use gcc8 to build efl
.if !empty(PKG_OPTIONS:Mgcc8)
USE_PKGSRC_GCC=	yes
GCC_REQD=	8
.endif
