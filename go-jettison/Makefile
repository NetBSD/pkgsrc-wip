# $NetBSD$

DISTNAME=	go-jettison-0.7.1
GITHUB_PROJECT=	jettison
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=wI2L/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/wI2L/jettison/
COMMENT=	Fast and flexible JSON encoder for Go
LICENSE=	mit

GO_SRCPATH=	github.com/wI2L/jettison
GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}

USE_TOOLS+=	bash:run

REPLACE_BASH+=	ci/bench.sh ci/test.sh

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
