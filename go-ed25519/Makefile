# $NetBSD$

# XXX 0.0.1 is a made-up release number, ask upstream to make a release.
PKGNAME=	go-ed25519-0.0.1
GITHUB_TAG=	5312a61534124124185d41f09206b9fef1d88403
DISTNAME=	ed25519-${GITHUB_TAG}
CATEGORIES=	security devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=agl/}
GITHUB_PROJECT=	ed25519

MAINTAINER=	alnsn@yandex.ru
HOMEPAGE=	https://github.com/agl/ed25519
COMMENT=	Ed25519 for Go
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}
GO_DIST_BASE=	ed25519-${GITHUB_TAG}
GO_SRCPATH=	github.com/agl/ed25519

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
