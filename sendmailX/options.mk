# $NetBSD: options.mk,v 1.1.1.1 2005/06/21 21:37:58 adrian_p Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.sendmailX
PKG_SUPPORTED_OPTIONS=	starttls sasl2

.if !defined(PKG_OPTIONS.sendmailX)
PKG_DEFAULT_OPTIONS+=	starttls
.endif

.include "../../mk/bsd.options.mk"

###
### Use OpenSSL libraries for SMTP STARTTLS support
###
.if !empty(PKG_OPTIONS:Mstarttls)
.	include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-TLS
CFLAGS+=		-DSM_USE_TLS
.endif

###
### Use SASLv2 for SMTP AUTH
###
.if !empty(PKG_OPTIONS:Msasl2)
.	include "../../security/cyrus-sasl2/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-SASL
CFLAGS+=		-DSM_USE_SASL
.endif
