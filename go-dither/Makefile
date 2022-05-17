# $NetBSD$

DISTNAME=	go-dither-2.2.0
GITHUB_PROJECT=	dither
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=makeworld-the-better-one/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://github.com/makeworld-the-better-one/dither/
COMMENT=	A fast, correct image dithering library in Go
LICENSE=	mpl-2.0

GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
GO_SRCPATH=	github.com/makeworld-the-better-one/dither

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
