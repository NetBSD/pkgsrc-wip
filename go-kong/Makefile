# $NetBSD$

DISTNAME=	kong-0.2.6
PKGNAME=	go-${DISTNAME}
MASTER_SITES=	${MASTER_SITE_GITHUB:=alecthomas/}
CATEGORIES=	devel
GITHUB_PROJECT=	kong
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	https://github.com/alecthomas/kong/
COMMENT=	Command-line parser for Go
LICENSE=	mit

GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	github.com/alecthomas/kong

.include "../../devel/go-errors/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
