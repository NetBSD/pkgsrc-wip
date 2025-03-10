# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.bigloo
PKG_SUPPORTED_OPTIONS=	alsa avahi emacs flac pgp gstreamer libuv mpg123 pulseaudio sqlite
PKG_SUGGESTED_OPTIONS=	libuv sqlite

.include "../../mk/bsd.options.mk"

#PLIST_SRC=	PLIST
PLIST_VARS=	alsa avahi pgp libuv pulseaudio sqlite

###
###  Support ALSA
###
.if !empty(PKG_OPTIONS:Malsa)
CONFIGURE_ARGS+=	--enable-alsa
.include "../../audio/alsa-lib/buildlink3.mk"
PLIST.alsa=	yes
.else
CONFIGURE_ARGS+=	--disable-alsa
.endif

###
###  Support Avahi
###
.if !empty(PKG_OPTIONS:Mavahi)
CONFIGURE_ARGS+=	--enable-avahi
PLIST.avahi=	yes
.include "../../net/avahi/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-avahi
.endif

###
###  Add Full BEE and Emacs support
###
.if !empty(PKG_OPTIONS:Memacs)
CONFIGURE_ARGS+=	--bee=full
CONFIGURE_ARGS+=	--lispdir=${EMACS_LISPPREFIX}
.include "../../editors/emacs/modules.mk"
.include "../../audio/flac/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--emacs=no
CONFIGURE_ARGS+=	--bee=partial
.endif


###
###  Support FLAC audio file manipulation
###
.if !empty(PKG_OPTIONS:Mflac)
CONFIGURE_ARGS+=	--enable-flac
.include "../../audio/flac/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-flac
.endif

###
###  Support PGP
###
.if !empty(PKG_OPTIONS:Mpgp)
CONFIGURE_ARGS+=	--enable-openpgp
PLIST.pgp=		yes
.else
CONFIGURE_ARGS+=	--disable-openpgp
.endif

###
###  Support gstreamer
###
.if !empty(PKG_OPTIONS:Mgstreamer)
CONFIGURE_ARGS+=	--enable-gstreamer
.include "../../multimedia/gstreamer1/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-gstreamer
.endif

###
###  Support libuv
###
.if !empty(PKG_OPTIONS:Mlibuv)
CONFIGURE_ARGS+=	--enable-libuv
PLIST.libuv=	yes
.include "../../devel/libuv/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-libuv
.endif

###
###  Support mpg123
###
.if !empty(PKG_OPTIONS:Mmpg123)
CONFIGURE_ARGS+=	--enable-mpg123
.include "../../audio/mpg123/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-mpg123
.endif

###
###  Support pulseaudio
###
.if !empty(PKG_OPTIONS:Mpulseaudio)
CONFIGURE_ARGS+=	--enable-pulseaudio
PLIST.pulseaudio=	yes
.include "../../audio/pulseaudio/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-pulseaudio
.endif


###
###  Support SQLite
###
.if !empty(PKG_OPTIONS:Msqlite)
CONFIGURE_ARGS+=	--enable-sqlite
CONFIGURE_ARGS+=	--enable-pkglib
PLIST.sqlite=	yes
.include "../../databases/sqlite3/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-sqlite
CONFIGURE_ARGS+=	--disable-pkglib
.endif
