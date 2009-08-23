# $NetBSD: options.mk,v 1.2 2009/08/23 20:45:21 udontknow Exp $

PKG_OPTIONS_VAR=        PKG_OPTIONS.mozldap
PKG_SUPPORTED_OPTIONS=  sasl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msasl)
#CONFIGURE_ARGS+=	--with-sasl
CONFIGURE_ARGS+=	--with-sasl-inc=${DESTDIR}${PREFIX}/include/sasl
CONFIGURE_ARGS+=	--with-sasl-lib=${DESTDIR}${PREFIX}/lib
.include "../../security/cyrus-sasl/buildlink3.mk"
.endif
