# $NetBSD: options.mk,v 1.1.1.1 2009/08/21 03:45:36 udontknow Exp $

PKG_OPTIONS_VAR=        PKG_OPTIONS.ldapsdk
PKG_SUPPORTED_OPTIONS=  sasl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msasl)
#CONFIGURE_ARGS+=	--with-sasl
CONFIGURE_ARGS+=	--with-sasl-inc=${DESTDIR}${PREFIX}/include/sasl
CONFIGURE_ARGS+=	--with-sasl-lib=${DESTDIR}${PREFIX}/lib
.include "../../security/cyrus-sasl/buildlink3.mk"
.endif
