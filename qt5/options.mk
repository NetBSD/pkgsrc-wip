# $NetBSD: options.mk,v 1.3 2013/05/12 13:18:11 othyro Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.qt5-libs
PKG_SUPPORTED_OPTIONS=	alsa cups dbus debug directfb fontconfig gif glib gstreamer gtk2 iconv icu jpeg mysql opengl openssl pgsql png pulseaudio sqlite sqlite3 tds tests x11 xcb xcursor xext xfixes xim xinerama xrandr xrender xvideo
PKG_SUGGESTED_OPTIONS+=	${PKG_SUPPORTED_OPTIONS:S/debug//1:S/tests//1:S/directfb//1:S/gstreamer//1} unixodbc
			# XXX for testing
PKG_OPTIONS_OPTIONAL_GROUPS=	odbc
PKG_OPTIONS_GROUP.odbc=		iodbc unixodbc

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
.include "../../audio/alsa-lib/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mcups)
.include "../../print/cups/buildlink3.mk"
CONFIGURE_ARGS+=	-cups
.else
CONFIGURE_ARGS+=	-no-cups
.endif

# XXX requires sqlcli.h - What provide this?
#.if !empty(PKG_OPTIONS:Mdb2)
#.include "../../databases/db/buildlink3.mk"
#CONFIGURE_ARGS+=	-qt-sql-db2 -plugin-sql-db2
#.else
CONFIGURE_ARGS+=	-no-sql-db2
#.endif

.if !empty(PKG_OPTIONS:Mdbus)
.include "../../sysutils/dbus/buildlink3.mk"
CONFIGURE_ARGS+=	-dbus
.else
CONFIGURE_ARGS+=	-no-dbus
.endif

.if !empty(PKG_OPTIONS:Mdirectfb)
.include "../../wip/directfb/buildlink3.mk"
CONFIGURE_ARGS+=	-direcfb
.else
CONFIGURE_ARGS+=	-no-directfb
.endif

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	-debug -developer-build -qml-debug
CONFIGURE_ARGS+=	-no-separate-debug-info
.else
CONFIGURE_ARGS+=	-release -no-qml-debug -separate-debug-info
.endif

.if !empty(PKG_OPTIONS:Mfontconfig)
.include "../../fonts/fontconfig/buildlink3.mk"
CONFIGURE_ARGS+=	-fontconfig
.else
CONFIGURE_ARGS+=	-no-fontconfig
.endif

.if !empty(PKG_OPTIONS:Mgif)
.include "../../mk/giflib.buildlink3.mk"
.else
CONFIGURE_ARGS+=	-no-gif
.endif

.if !empty(PKG_OPTIONS:Mglib)
.include "../../devel/glib2/buildlink3.mk"
CONFIGURE_ARGS+=	-glib
CFLAGS+=		-I${BUILDLINK_PREFIX.glib2}/include/glib/glib-2.0
CFLAGS+=		-I${BUILDLINK_PREFIX.glib2}/lib/glib-2.0/include
.else
CONFIGURE_ARGS+=	-no-glib
.endif

.if !empty(PKG_OPTIONS:Mgstreamer)
.include "../../multimedia/gstreamer1/buildlink3.mk"
CFLAGS+=		-I${BUILDLINK_PREFIX.gstreamer1}/include/gstreamer-1.0
CONFIGURE_ARGS+=	-gstreamer
.else
CONFIGURE_ARGS+=	-no-gstreamer
.endif

.if !empty(PKG_OPTIONS:Mgtk2)
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/atk/buildlink3.mk"
CONFIGURE_ARGS+=	-gtkstyle
.else
CONFIGURE_ARGS+=	-no-gtkstyle
.endif

.if !empty(PKG_OPTIONS:Miconv)
.include "../../converters/libiconv/buildlink3.mk"
LDFLAGS+=		-liconv
CONFIGURE_ARGS+=	-iconv
.else
CONFIGURE_ARGS+=	-no-iconv
.endif

.if !empty(PKG_OPTIONS:Micu)
.include "../../textproc/icu/buildlink3.mk"
CONFIGURE_ARGS+=	-icu
.else
CONFIGURE_ARGS+=	-no-icu
.endif

.if !empty(PKG_OPTIONS:Miodbc)
.include "../../databases/iodbc/buildlink3.mk"
CONFIGURE_ARGS+=	-plugin-sql-odbc
.elif !empty(PKG_OPTIONS:Munixodbc)
.include "../../databases/unixodbc/buildlink3.mk"
CONFIGURE_ARGS+=	-plugin-sql-odbc
.else
CONFIGURE_ARGS+=	-no-sql-odbc
.endif

.if !empty(PKG_OPTIONS:Mjpeg)
.include "../../mk/jpeg.buildlink3.mk"
CONFIGURE_ARGS+=        -system-libjpeg
.else
CONFIGURE_ARGS+=        -no-libjpeg
.endif

.if !empty(PKG_OPTIONS:Mjpeg)
.include "../../mk/jpeg.buildlink3.mk"
CONFIGURE_ARGS+=	-system-libjpeg
.else
CONFIGURE_ARGS+=	-no-libjpeg
.endif

.if !empty(PKG_OPTIONS:Mmysql)
.include "../../mk/mysql.buildlink3.mk"
CONFIGURE_ARGS+=	-qt-sql-mysql -plugin-sql-mysql
.else
CONFIGURE_ARGS+=	-no-sql-mysql
.endif

.if !empty(PKG_OPTIONS:Mopengl)
.include "../../graphics/MesaLib/buildlink3.mk"
CONFIGURE_ARGS+=	-opengl
.else
CONFIGURE_ARGS+=	-no-opengl
.endif

.if !empty(PKG_OPTIONS:Mopenssl)
.include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	-openssl
.else
CONFIGURE_ARGS+=	-no-openssl
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
.include "../../mk/pgsql.buildlink3.mk"
CONFIGURE_ARGS+=	-qt-sql-psql -plugin-sql-psql
.else
CONFIGURE_ARGS+=	-no-sql-psql
.endif

.if !empty(PKG_OPTIONS:Mpng)
.include "../../graphics/png/buildlink3.mk"
CONFIGURE_ARGS+=	-system-libpng
.else
CONFIGURE_ARGS+=	-no-png
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
.include "../../audio/pulseaudio/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Msqlite)
.include "../../databases/sqlite/buildlink3.mk"
CONFIGURE_ARGS+=	-qt-sql-sqlite2 -plugin-sql-sqlite2
.else
CONFIGURE_ARGS+=	-no-sql-sqlite2
.endif

.if !empty(PKG_OPTIONS:Msqlite3)
.include "../../databases/sqlite3/buildlink3.mk"
CONFIGURE_ARGS+=	-system-sqlite -qt-sql-sqlite -plugin-sql-sqlite
.else
CONFIGURE_ARGS+=	-no-sql-sqlite
.endif

.if !empty(PKG_OPTIONS:Mtds)
.include "../../databases/freetds/buildlink3.mk"
CONFIGURE_ARGS+=	-qt-sql-tds -plugin-sql-tds
.else
CONFIGURE_ARGS+=	-no-sql-tds
.endif

.if !empty(PKG_OPTIONS:Mtests)
CONFIGURE_ARGS+=	-make tests
.else
CONFIGURE_ARGS+=	-nomake tests
.endif

.if !empty(PKG_OPTIONS:Mx11)
.include "../../x11/libX11/buildlink3.mk"
CONFIGURE_ARGS+=	-xkb
.else
CONFIGURE_ARGS+=	-no-xkb
.endif

.if !empty(PKG_OPTIONS:Mxcb)
.include "../../x11/xcb-util-renderutil/buildlink3.mk"
.include "../../x11/xcb-util-wm/buildlink3.mk"
.include "../../x11/xcb-util-image/buildlink3.mk"
.include "../../x11/xcb-util-keysyms/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
CONFIGURE_ARGS+=	-xcb -system-xcb
.else
CONFIGURE_ARGS+=	-no-xcb
.endif

.if !empty(PKG_OPTIONS:Mxcursor)
.include "../../x11/libXcursor/buildlink3.mk"
CONFIGURE_ARGS+=	-xcursor
.else
CONFIGURE_ARGS+=	-no-xcursor
.endif

.if !empty(PKG_OPTIONS:Mxext)
.include "../../x11/libXext/buildlink3.mk"
CONFIGURE_ARGS+=	-xshape -xsync
.else
CONFIGURE_ARGS+=	-no-xshape -no-xsync
.endif

.if !empty(PKG_OPTIONS:Mxfixes)
.include "../../x11/libXfixes/buildlink3.mk"
CONFIGURE_ARGS+=	-xfixes
.else
CONFIGURE_ARGS+=	-no-xfixes
.endif

.if !empty(PKG_OPTIONS:Mxim)
.include "../../x11/libXi/buildlink3.mk"
CONFIGURE_ARGS+=	-xinput
.else
CONFIGURE_ARGS+=	-no-xinput
.endif

.if !empty(PKG_OPTIONS:Mxinerama)
.include "../../x11/libXinerama/buildlink3.mk"
CONFIGURE_ARGS+=	-xinerama
.else
CONFIGURE_ARGS+=	-no-xinerama
.endif

.if !empty(PKG_OPTIONS:Mxrandr)
.include "../../x11/libXrandr/buildlink3.mk"
CONFIGURE_ARGS+=	-xrandr
.else
CONFIGURE_ARGS+=	-no-xrandr
.endif

.if !empty(PKG_OPTIONS:Mxrender)
.include "../../x11/libXrender/buildlink3.mk"
CONFIGURE_ARGS+=	-xrender
.else
CONFIGURE_ARGS+=	-no-xrender
.endif

.if !empty(PKG_OPTIONS:Mxvideo)
.include "../../x11/libXv/buildlink3.mk"
CONFIGURE_ARGS+=	-xvideo
.else
CONFIGURE_ARGS+=	-no-xvideo
.endif
