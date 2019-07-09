# $NetBSD$

PKG_OPTIONS_VAR=		PKG_OPTIONS.gnunet
PKG_SUPPORTED_OPTIONS=		doc mdoc idn mysql pgsql tests experimental bluez
PKG_SUGGESTED_OPTIONS=		mdoc
PLIST_VARS+=			doc mdoc
PLIST_VARS+=			experimental
# openssl is currently required by:
# src/transport/gnunet-transport-certificate-creation
# src/gns/gnunet-gns-proxy-setup-ca

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mtests)
.include "../../lang/python/tool.mk"
PYTHON_FOR_BUILD_ONLY=	yes
.endif

# build the doc output. XXX: See README.
.if !empty(PKG_OPTIONS:Mdoc)
USE_TOOLS+=		makeinfo
INFO_FILES=   yes
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
# for idn2.
.if !empty(PKG_OPTIONS:Midn)
.include "../../devel/libidn2/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libidn2=${BUILDLINK_PREFIX.libidn2}
.else
.include "../../devel/libidn/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libidn=${BUILDLINK_PREFIX.libidn}
.endif

# database support - they don't exclude other databases,
# you can have mysql, pgsql, and the default all built in.
.if !empty(PKG_OPTIONS:Mmysql)
.include "../../mk/mysql.buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
.include "../../mk/pgsql.buildlink3.mk"
.endif

# Experimental
.if !empty(PKG_OPTIONS:Mexperimental)
.include "../../audio/libopus/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../math/glpk/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-experimental
PLIST.experimental=	yes
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
.endif
