# $NetBSD$

PKG_OPTIONS_VAR=		PKG_OPTIONS.worker
PKG_SUPPORTED_OPTIONS=		xft2 lua hal xinerama ssl inotify
PKG_SUGGESTED_OPTIONS=		xft2 xinerama

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mxft2)
CONFIGURE_ARGS+=	--enable-xft
.include	"../../x11/libXft/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-xft
.endif

.if !empty(PKG_OPTIONS:Mlua)
CONFIGURE_ARGS+=	--enable-lua
.include	"../../lang/lua/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-lua
.endif

.if !empty(PKG_OPTIONS:Mhal)
.include	"../../sysutils/hal/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mxinerama)
.include	"../../x11/libXinerama/buildlink3.mk"
.endif

# Used for file checksum support
.if !empty(PKG_OPTIONS:Mssl)
.include	"../../security/openssl/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Minotify)
CONFIGURE_ARGS+=	--enable-inotify
if ${OPSYS} != "Linux" && ${OPSYS} != "SunOS"
.include	"../../devel/libinotify/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-inotify
.endif
