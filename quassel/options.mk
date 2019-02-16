# $NetBSD$

PKG_OPTIONS_VAR=		PKG_OPTIONS.quassel
PKG_SUPPORTED_OPTIONS=		webkit

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} != "SunOS"
PKG_SUGGESTED_OPTIONS=		webkit
.else
PKG_SUGGESTED_OPTIONS=
.endif

.include "../../mk/bsd.options.mk"

# This allows for URL previews in chat.
.if !empty(PKG_OPTIONS:Mwebkit)
CMAKE_ARGS+=	-DWITH_WEBKIT=ON
.include "../../x11/qt5-qtwebkit/buildlink3.mk"
.else
CMAKE_ARGS+=	-DWITH_WEBKIT=OFF
.endif
