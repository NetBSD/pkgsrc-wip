# $NetBSD: options.mk,v 1.3 2015/02/07 22:08:46 tnn2 Exp $

# Global and legacy options

PKG_OPTIONS_VAR=	PKG_OPTIONS.sabnzbd
PKG_SUPPORTED_OPTIONS=	feedparser openssl
PKG_SUGGESTED_OPTIONS=	feedparser openssl

.include "../../mk/bsd.options.mk"
.include "../../lang/python/application.mk"

###
### feedparser support
###
.if !empty(PKG_OPTIONS:Mfeedparser)
DEPENDS+=	${PYPKGPREFIX}-feedparser-[0-9]*:../../textproc/py-feedparser
.endif

###
### openssl support
###
.if !empty(PKG_OPTIONS:Mopenssl)
DEPENDS+=	openssl-[0-9]*:../../security/openssl
DEPENDS+=	${PYPKGPREFIX}-OpenSSL-[0-9]*:../../security/py-OpenSSL
.endif
