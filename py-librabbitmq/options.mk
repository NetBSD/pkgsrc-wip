# $NetBSD: options.mk,v 1.1 2014/09/22 01:33:50 othyro Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.py-librabbitmq
PKG_SUPPORTED_OPTIONS=	doc popt static
PKG_SUGGESTED_OPTIONS+=	openssl popt

PKG_OPTIONS_OPTIONAL_GROUPS=	ssl
PKG_OPTIONS_GROUP.ssl=		gnutls openssl polarssl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdoc)
TOOL_DEPENDS+=		doxygen-[0-9]*:../../devel/doxygen
TOOL_DEPENDS+=		xmlto-[0-9]*:../../textproc/xmlto
CONFIGURE_ARGS+=	--enable-docs=yes
.else
CONFIGURE_ARGS+=	--enable-docs=no
.endif

.if !empty(PKG_OPTIONS:Mopenssl)
.include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ssl=openssl
.elif !empty(PKG_OPTIONS:Mgnutls)
.include "../../security/gnutls/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ssl=gnutls
.elif !empty(PKG_OPTIONS:Mpolarssl)
.include "../../security/polarssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ssl=polarssl
.else
CONFIGURE_ARGS+=	--with-ssl=no
.endif

.if !empty(PKG_OPTIONS:Mpopt)
.include "../../devel/popt/buildlink3.mk"
TOOL_DEPENDS+=		xmlto-[0-9]*:../../textproc/xmlto
CONFIGURE_ARGS+=	--enable-tools=yes
.else
CONFIGURE_ARGS+=	--enable-tools=no
.endif

.if !empty(PKG_OPTIONS:Mstatic)
CONFIGURE_ARGS+=	--enable-static=yes
.else
CONFIGURE_ARGS+=	--enable-shared=yes
.endif
