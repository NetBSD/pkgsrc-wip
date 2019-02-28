# $NetBSD$

PKG_OPTIONS_VAR=		PKG_OPTIONS.gnunet
PKG_SUPPORTED_OPTIONS=		doc mdoc idn mysql pgsql tests
PKG_SUGGESTED_OPTIONS=		doc
PLIST_VARS+=			doc
# openssl is currently required by:
# src/transport/gnunet-transport-certificate-creation
# src/gns/gnunet-gns-proxy-setup-ca

.include "../../mk/bsd.options.mk"

# Parts of the testsuite require python3.7
.if !empty(PKG_OPTIONS:Mtests)
.include "../../lang/python/tool.mk"
PYTHON_VERSIONS_ACCEPTED=	37
PYTHON_FOR_BUILD_ONLY=	yes
BUILD_DEPENDS+=		${PYPKGPREFIX}-future-[0-9]*:../../devel/py-future
.endif

# build the doc output. XXX: See README.
.if !empty(PKG_OPTIONS:Mdoc)
USE_TOOLS+=		makeinfo
CONFIGURE_ARGS+=	--enable-documentation
PLIST.doc=		yes
.else
CONFIGURE_ARGS+=	--disable-documentation
.endif

# build the mdoc output. XXX: See README.
.if !empty(PKG_OPTIONS:Mmdoc)
BUILD_DEPENDS+=		texi2mdoc-[0-9]*:../../textproc/texi2mdoc
CONFIGURE_ARGS+=	--enable-texi2mdoc-generation
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
