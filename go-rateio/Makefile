# $NetBSD$

# XXX 0.0.1 is a made-up release number, ask upstream to make a release.
PKGNAME=	go-rateio-0.0.1
GITHUB_TAG=	e8e00881e5c12090412414be41c04ca9c8a71106
DISTNAME=	rateio-${GITHUB_TAG}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=shazow/}
GITHUB_PROJECT=	rateio

MAINTAINER=	alnsn@NetBSD.org
HOMEPAGE=	https://github.com/shazow/rateio
COMMENT=	Ratelimiting for io-style interfaces in Go
LICENSE=	mit

WRKSRC=		${WRKDIR}
GO_DIST_BASE=	rateio-${GITHUB_TAG}
GO_SRCPATH=	github.com/shazow/rateio

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
