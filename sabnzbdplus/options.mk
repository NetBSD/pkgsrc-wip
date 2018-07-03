# $NetBSD: options.mk,v 1.3 2015/02/07 22:08:46 tnn2 Exp $

# Global and legacy options

PKG_OPTIONS_VAR=	PKG_OPTIONS.sabnzbdplus
PKG_SUPPORTED_OPTIONS=	par2 unrar feedparser yenc openssl
PKG_SUGGESTED_OPTIONS=	par2 unrar feedparser yenc openssl

.include "../../mk/bsd.options.mk"
.include "../../lang/python/application.mk"

###
### par2 support
###
.if !empty(PKG_OPTIONS:Mpar2)
DEPENDS+=	par2-[0-9]*:../../archivers/par2
.endif

###
### unrar support
###
.if !empty(PKG_OPTIONS:Munrar)
DEPENDS+=	unrar-[0-9]*:../../archivers/unrar
.endif

###
### feedparser support
###
.if !empty(PKG_OPTIONS:Mfeedparser)
DEPENDS+=	${PYPKGPREFIX}-feedparser-[0-9]*:../../textproc/py-feedparser
.endif

###
### par2 support
###
.if !empty(PKG_OPTIONS:Myenc)
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-yenc
DEPENDS+=	${PYPKGPREFIX}-yenc-[0-9]*:../../converters/py-yenc
.endif

###
### openssl support
###
.if !empty(PKG_OPTIONS:Mopenssl)
DEPENDS+=	openssl-[0-9]*:../../security/openssl
DEPENDS+=	${PYPKGPREFIX}-OpenSSL-[0-9]*:../../security/py-OpenSSL
.endif
