# $NetBSD: options.mk,v 1.1 2013/02/28 11:24:15 othyro Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnokii
PKG_SUPPORTED_OPTIONS=	bluetooth debug ical libusb mysql pcsc pgsql readline
PKG_SUPPORTED_OPTIONS+=	sqlite3 x11 xpm
PKG_SUGGESTED_OPTIONS+=	sqlite3 ical libusb pcsc readline xpm
PLIST_VARS+=		mysql pgsql sqlite3

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mbluetooth)
CONFIGURE_ARGS+=	--enable-bluetooth
.else
CONFIGURE_ARGS+=	--disable-bluetooth
.endif

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-fulldebug
.else
CONFIGURE_ARGS+=	--disable-rlpdebug --disable-xdebug
.endif

.if !empty(PKG_OPTIONS:Mical)
.include "../../time/libical/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-libical
.endif

.if !empty(PKG_OPTIONS:Mlibusb)
.include "../../devel/libusb/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-libusb
.endif

.if !empty(PKG_OPTIONS:Mmysql)
.include "../../mk/mysql.buildlink3.mk"
PLIST.mysql=		yes
.else
CONFIGURE_ARGS+=	--disable-mysql
.endif

.if !empty(PKG_OPTIONS:Mpcsc)
.include "../../security/pcsc-lite/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-libpcsclite
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
.include "../../mk/pgsql.buildlink3.mk"
PLIST.pgsql=		yes
.else
CONFIGURE_ARGS+=	--disable-postgres
.endif

.if !empty(PKG_OPTIONS:Mreadline)
.include "../../devel/readline/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-readline
.endif

.if !empty(PKG_OPTIONS:Msqlite3)
.include "../../databases/sqlite3/buildlink3.mk"
PLIST.sqlite3=		yes
.else
CONFIGURE_ARGS+=        --disable-sqlite
.endif

.if !empty(PKG_OPTIONS:Mx11)
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
CONFIGURE_ARGS+=	--with-x
.else
CONFIGURE_ARGS+=	--without-x
.endif

.if !empty(PKG_OPTIONS:Mxpm)
.  if empty(PKG_OPTIONS:Mx11)
.include "../../x11/libXpm/buildlink3.mk"
.  endif
.endif
