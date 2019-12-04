# $NetBSD$

PKG_OPTIONS_VAR=		PKG_OPTIONS.gnunet

PKG_SUPPORTED_OPTIONS+=		doc mdoc idn mysql pgsql tests
PKG_SUPPORTED_OPTIONS+=		experimental bluez pulseaudio
PKG_SUPPORTED_OPTIONS+=		opus ogg sqlite3 json
PKG_SUPPORTED_OPTIONS+=		gstreamer perl verbose-logging
# Should we name this qrcode instead?
PKG_SUPPORTED_OPTIONS+=		zbar

# mdoc should be fixed in 0.11.9, missing files were included
# post-0.11.8.
# in 0.11.9 when fixed for pkgsrc, add back idn.
PKG_SUGGESTED_OPTIONS+=		doc sqlite3 json opus ogg gstreamer idn

# bluez is still in pkgsrc-wip, and I should test this
# before claiming bluez from pkgsrc-wip on Linux works.
# However, this is a supported option for GNUnet.
# gnunet-qr needs zbar with video support. v4l2 only works
# on Linux.
.if ${OPSYS} == "Linux"
PKG_SUGGESTED_OPTIONS+=		bluez
PKG_SUGGESTED_OPTIONS+=		zbar
.endif

PLIST_VARS+=			doc mdoc conversations
PLIST_VARS+=			experimental json
PLIST_VARS+=			pgsql mysql sqlite3
PLIST_VARS+=			linux freebsd bluez
PLIST_VARS+=			linuxfreebsd zbar
PLIST_VARS+=			perl

# openssl is currently required by:
# src/transport/gnunet-transport-certificate-creation
# src/gns/gnunet-gns-proxy-setup-ca

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mtests)
.include "../../lang/python/tool.mk"
PYTHON_FOR_BUILD_ONLY=	yes
.else
CONFIGURE_ARGS+=	--disable-tests
.endif

.if !empty(PKG_OPTIONS:Mdoc)
USE_TOOLS+=		makeinfo
INFO_FILES=		yes
CONFIGURE_ARGS+=	--enable-documentation
PLIST.doc=		yes
.else
CONFIGURE_ARGS+=	--disable-documentation
.endif

# Build the mdoc output.
.if !empty(PKG_OPTIONS:Mmdoc)
BUILD_DEPENDS+=		texi2mdoc-[0-9]*:../../textproc/texi2mdoc
CONFIGURE_ARGS+=	--enable-texi2mdoc-generation
PLIST.mdoc=		yes
.else
CONFIGURE_ARGS+=	--disable-texi2mdoc-generation
.endif

# idn is mandatory but idn or idn2 can be used with a preference
# for idn2. Use different option content once
# https://bugs.gnunet.org/view.php?id=5948 is fixed.
.if !empty(PKG_OPTIONS:Midn)
.include "../../devel/libidn2/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libidn=no
.else
.include "../../devel/libidn/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libidn=${BUILDLINK_PREFIX.libidn}
.endif

.if !empty(PKG_OPTIONS:Mjson)
.include "../../textproc/jansson/buildlink3.mk"
CONFIGURE_ARGS+=	--with-jansson=${BUILDLINK_PREFIX.jansson}
PLIST.json=		yes
.else
CONFIGURE_ARGS+=	--without-jansson
.endif

# database support - they don't exclude other databases,
# you can have mysql, pgsql, and the default all built in.
# ideally we would check for at least sqlite3 existing, but
# the build won't build when you have none of them.
.if !empty(PKG_OPTIONS:Msqlite3)
.include "../../databases/sqlite3/buildlink3.mk"
PLIST.sqlite3=		yes
.else
CONFIGURE_ARGS+=	--without-sqlite3
.endif

.if !empty(PKG_OPTIONS:Mmysql)
.include "../../mk/mysql.buildlink3.mk"
PLIST.mysql=		yes
.else
CONFIGURE_ARGS+=	--without-mysql
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
.include "../../mk/pgsql.buildlink3.mk"
PLIST.pgsql=		yes
.else
CONFIGURE_ARGS+=	--without-postgres
.endif

.if !empty(PKG_OPTIONS:Mexperimental)
CONFIGURE_ARGS+=	--enable-experimental
PLIST.experimental=	yes
.  if !empty(PKG_OPTIONS:Mverbose-logging)
CONFIGURE_ARGS+=	--enable-logging=verbose
.  endif
.else
CONFIGURE_ARGS+=	--disable-experimental
.endif

# conversation submodule. if gstreamer + opus + ogg
# exists, pulseaudio is not necessary.
.if !empty(PKG_OPTIONS:Mopus)
.include "../../audio/libopus/buildlink3.mk"
PLIST.conversations=	yes
.else
CONFIGURE_ARGS+=	--without-libopus
.endif

.if !empty(PKG_OPTIONS:Mogg)
.include "../../multimedia/libogg/buildlink3.mk"
PLIST.conversations=	yes
.else
CONFIGURE_ARGS+=	--without-libogg
.endif

.if !empty(PKG_OPTIONS:Mgstreamer)
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
PLIST.conversations=	yes
.else
CONFIGURE_ARGS+=	--without-gstreamer
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
.include "../../audio/pulseaudio/buildlink3.mk"
PLIST.conversations=	yes
.else
CONFIGURE_ARGS+=	--without-libpulse
.endif

.if !empty(PKG_OPTIONS:Mzbar)
.include "../../graphics/zbar/buildlink3.mk"
PLIST.zbar=		yes
.else
CONFIGURE_ARGS+=	--without-zbar
.endif

# FIXME: It would be good to provide a build of gnunet against
# 'gnutls build against libdane/unbound' iff unbound is selected,
# causing consequentially a build of gnutls with this setting.
# Since gnunet does build against either of these and gnutls
# without libdane is more common in pkgsrc, this should be
# an option. The conditional below doesn't work.
# .if !empty(PKG_OPTIONS:Munbound) && empty(PKG_BUILD_OPTIONS.gnutls:Munbound)
# PKG_FAIL_REASON+=	"Requires the unbound option enabled in gnutls"
# .endif

.if ${OPSYS} == "Linux" && !empty(PKG_OPTIONS:Mbluez)
# Do we need more for bluez?
.include "../../wip/bluez-libs/buildlink3.mk"
PLIST.bluez=		yes
.else
CONFIGURE_ARGS+=	--without-libbluetooth
.endif

.if ${OPSYS} == "Linux"
PLIST.linux=		yes
.endif

.if ${OPSYS} == "FreeBSD"
PLIST.freebsd=		yes
.endif

.if ${OPSYS} == "Linux" || ${OPSYS} == "FreeBSD"
PLIST.linuxfreebsd=	yes
.endif

# optional gnunet-logread
.if !empty(PKG_OPTIONS:Mperl)
USE_TOOLS+=		perl:run
PLIST.perl=		yes
CONFIGURE_ARGS+=	--with-gnunet-logread
.else
CONFIGURE_ARGS+=	--without-gnunet-logread
.endif
