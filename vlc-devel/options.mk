# $NetBSD: options.mk,v 1.4 2008/08/14 20:29:50 hoka_adam Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.vlc-devel
PKG_SUPPORTED_OPTIONS=		qt debug faad arts dbus skins sdl esd
PKG_SUGGESTED_OPTIONS=		qt esd

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		${PKG_SUPPORTED_OPTIONS}

## ESOUND audio backend

.if !empty(PKG_OPTIONS:Mesd)
CONFIGURE_ARGS+=	--enable-esd
.include "../../audio/esound/buildlink3.mk"
PLIST.esd=		yes
.endif

## SDL backend support

.if !empty(PKG_OPTIONS:Msdl)
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
PLIST.sdl=		yes
.else
CONFIGURE_ARGS+=	--disable-sdl
CONFIGURE_ARGS+=	--disable-sdl-image
.endif

## DBUS message bus support
## also libnotify because it uses dbus
## so taking them apart would make no sense.

.if !empty(PKG_OPTIONS:Mdbus)
CONFIGURE_ARGS+=	--enable-dbus
.include "../../sysutils/dbus/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-notify
.include "../../sysutils/libnotify/buildlink3.mk"
PLIST.dbus=		yes
.else
CONFIGURE_ARGS+=	--disable-dbus
.endif

## DEBUG build or release build

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
CONFIGURE_ARGS+=	--disable-optimizations
.else
CONFIGURE_ARGS+=	--enable-release
.endif

## SKINS frontend

.if !empty(PKG_OPTIONS:Mskins)
CONFIGURE_ARGS+=	--enable-skins2
PLIST.skins=		yes
.else
CONFIGURE_ARGS+=	--disable-skins2
.endif

## The new QT frontend using qt4

.if !empty(PKG_OPTIONS:Mqt)
.include "../../x11/qt4-libs/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-qt4
PLIST.qt=		yes
.else
CONFIGURE_ARGS+=	--disable-qt4
.endif

## FAAD support (faad is non-redistributable)

.if !empty(PKG_OPTIONS:Mfaad)
CONFIGURE_ARGS+=	--enable-faad
PLIST.faad=		yes
.include "../../audio/faad2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-faad
.endif

## ARTS audio system support

.if !empty(PKG_OPTIONS:Marts)
CONFIGURE_ARGS+=	--enable-arts
PLIST.arts=		yes
.include "../../audio/arts/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-arts
.endif
