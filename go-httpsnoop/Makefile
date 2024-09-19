# $NetBSD$

DISTNAME=	httpsnoop-20200910
PKGNAME=	go-${DISTNAME}
GITHUB_PROJECT=	httpsnoop
GITHUB_TAG=	80c3c2123b72a19bf86e424759ce61a51b0f5f1b
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=felixge/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/felixge/httpsnoop/
COMMENT=	Httpsnoop provides an easy way to capture http related metrics
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}
GO_SRCPATH=	github.com/bradfitz/${GITHUB_PROJECT}

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
