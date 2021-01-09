# $NetBSD$

DISTNAME=	ewma-20201216
PKGNAME=	go-${DISTNAME}
GITHUB_PROJECT=	ewma
GITHUB_TAG=	507017d748aae584fd5fa8c7448e0105598a0647
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=VividCortex/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/VividCortex/ewma/
COMMENT=	Exponentially Weighted Moving Average algorithms for Go
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}
GO_SRCPATH=	github.com/VividCortex/${GITHUB_PROJECT}

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
