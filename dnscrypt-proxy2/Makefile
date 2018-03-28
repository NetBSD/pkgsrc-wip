# $NetBSD$

PKGNAME=	dnscrypt2-proxy-2.0.7
DISTNAME=	dnscrypt-proxy-${PKGVERSION_NOREV}
MASTER_SITES=	${MASTER_SITE_GITHUB:=jedisct1/}
CATEGORIES=	net security

COMMENT=	DNS proxy with support for encrypted protocols
HOMEPAGE=	https://github.com/jedisct1/dnscrypt-proxy
LICENSE=	isc

GITHUB_PROJECT=	dnscrypt-proxy
GITHUB_TAG=	${PKGVERSION_NOREV}

GO_SRCPATH=	github.com/jedisct1/dnscrypt-proxy/
GO_DIST_BASE=	${DISTNAME}

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
