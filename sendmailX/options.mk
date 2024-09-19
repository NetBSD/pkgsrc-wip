# $NetBSD: options.mk,v 1.8 2006/10/29 08:32:55 shattered Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.sendmailX
PKG_SUPPORTED_OPTIONS=	tls sasl pmilter

.include "../../mk/bsd.options.mk"

###
### Use OpenSSL libraries for SMTP STARTTLS support
###
.if !empty(PKG_OPTIONS:Mtls)
.  include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	-enable-TLS
CFLAGS+=		-DSM_USE_TLS
.else
CONFIGURE_ARGS+=	-disable-TLS
CONFIGURE_ENV+=		ac_cv_header_openssl_ssl_h=no
.endif

###
### Use SASLv2 for SMTP AUTH
###
.if !empty(PKG_OPTIONS:Msasl)
.  include "../../security/cyrus-sasl/buildlink3.mk"
CONFIGURE_ARGS+=	-enable-SASL
CFLAGS+=		-DSM_USE_SASL
.else
CONFIGURE_ARGS+=	-disable-SASL
.endif

###
### Use policy milter protocol
###
.if !empty(PKG_OPTIONS:Mpmilter)
CONFIGURE_ARGS+=	-enable-pmilter
.endif
