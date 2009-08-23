# $NetBSD: options.mk,v 1.3 2009/08/23 21:06:33 udontknow Exp $

PKG_OPTIONS_VAR=        PKG_OPTIONS.mozldap
PKG_SUPPORTED_OPTIONS=  sasl inet6

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
