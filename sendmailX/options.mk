# $NetBSD: options.mk,v 1.5 2005/07/28 13:27:46 adrian_p Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.sendmailX
PKG_SUPPORTED_OPTIONS=	tls sasl

.include "../../mk/bsd.options.mk"

###
### Use OpenSSL libraries for SMTP STARTTLS support
###
.if !empty(PKG_OPTIONS:Mtls)
.	include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-TLS
CFLAGS+=		-DSM_USE_TLS
.else
CONFIGURE_ENV+=		ac_cv_header_openssl_ssl_h=no
.endif

###
### Use SASLv2 for SMTP AUTH
###
.if !empty(PKG_OPTIONS:Msasl)
.	include "../../security/cyrus-sasl2/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-SASL
CFLAGS+=		-DSM_USE_SASL
.endif
