# $NetBSD$

DISTNAME=	go-atomic-1.7.0
GITHUB_PROJECT=	atomic
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	category
MASTER_SITES=	${MASTER_SITE_GITHUB:=uber-go/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/uber-go/atomic/
COMMENT=	Wrapper types for sync/atomic which enforce atomic access
LICENSE=	mit

GO_SRCPATH=	github.com/uber-go/atomic/
GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
