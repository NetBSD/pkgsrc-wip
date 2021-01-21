# $NetBSD$

DISTNAME=	go-semver-3.1.1
GITHUB_PROJECT=	semver
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=Masterminds/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/Masterminds/semver/
COMMENT=	Work with Semantic Versions in Go
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
GO_SRCPATH=	github.com/Masterminds/${GITHUB_PROJECT}

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
