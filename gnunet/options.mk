# $NetBSD$
#

PKG_OPTIONS_VAR=		PKG_OPTIONS.gnunet
PKG_SUPPORTED_OPTIONS=		doc mdoc ssl libgcrypt idn mysql pgsql tests
PKG_SUGGESTED_OPTIONS=		doc ssl libgcrypt

# openssl is currently required by:
# src/transport/gnunet-transport-certificate-creation
# src/gns/gnunet-gns-proxy-setup-ca

.include "../../mk/bsd.options.mk"

# Parts of the testsuite require python3.7
.if !empty(PKG_OPTIONS:Mtests)
.include "../../lang/python37/buildlink3.mk"
.endif

# libgcrypt is used in preference to openssl, per gnunet configure.ac
.if !empty(PKG_OPTIONS:Mlibgcrypt)
.include "../../security/libgcrypt/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libgcrypt-prefix=${BUILDLINK_PREFIX.libgcrypt}
CONFIGURE_ARGS+=	--without-crypto
.endif

.if !empty(PKG_OPTIONS:Mssl)
.include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-crypto=${BUILDLINK_PREFIX.libgcrypt}
.endif

.if !empty(PKG_OPTIONS:Mdoc)
CONFIGURE_ARGS+=	--enable-documentation
.else
CONFIGURE_ARGS+=	--disable-documentation
.endif

# build the mdoc output.
.if !empty(PKG_OPTIONS:Mmdoc)
BUILD_DEPENDS+=		texi2mdoc-[0-9]*:../../textproc/texi2mdoc
CONFIGURE_ARGS+=	--enable-texi2mdoc-generation
.else
CONFIGURE_ARGS+=	--disable-texi2mdoc-generation
.endif

.if !empty(PKG_OPTIONS:Midn)
.include "../../devel/libidn2/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libidn2=${BUILDLINK_PREFIX.libidn2}
.else
.include "../../devel/libidn/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libidn=${BUILDLINK_PREFIX.libidn}
.endif

### database support
###
.if !empty(PKG_OPTIONS:Mmysql)
.include "../../mk/mysql.buildlink3.mk"
.endif
.if !empty(PKG_OPTIONS:Mpgsql)
.include "../../mk/pgsql.buildlink3.mk"
.endif

