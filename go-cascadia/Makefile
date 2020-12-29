# $NetBSD$

DISTNAME=	go-cascadia-1.0.0
GITHUB_PROJECT=	cascadia
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=andybalholm/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/andybalholm/cascadia/
COMMENT=	CSS selector library in Go
LICENSE=	2-clause-bsd

GO_SRCPATH=	github.com/andybalholm/cascadia/
GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}

.include "../../net/go-net/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
