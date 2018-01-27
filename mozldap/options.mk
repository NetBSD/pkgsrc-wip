# $NetBSD: options.mk,v 1.4 2012/06/12 15:46:34 thomasklausner Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mozldap
PKG_SUPPORTED_OPTIONS=	sasl inet6
PKG_SUGGESTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msasl)
#CONFIGURE_ARGS+=	--with-sasl
CONFIGURE_ARGS+=	--with-sasl-inc=${DESTDIR}${PREFIX}/include/sasl
CONFIGURE_ARGS+=	--with-sasl-lib=${DESTDIR}${PREFIX}/lib
.include "../../security/cyrus-sasl/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mipv6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif
