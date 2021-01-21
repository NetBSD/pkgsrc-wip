# $NetBSD$

DISTNAME=	go-perks-1.0.1
PKGREVISION=	1
GITHUB_PROJECT=	perks
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=beorn7/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/beorn7/perks/
COMMENT=	Effective Computation of Things
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
GO_SRCPATH=	github.com/beorn7/${GITHUB_PROJECT}

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
