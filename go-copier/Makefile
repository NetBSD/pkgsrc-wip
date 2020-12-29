# $NetBSD$

DISTNAME=	go-copier-0.1.0
GITHUB_PROJECT=	copier
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=jinzhu/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/jinzhu/copier/
COMMENT=	Copier for golang, copy value from struct to struct and more
LICENSE=	mit

GO_SRCPATH=	github.com/jinzhu/copier
GO_DIST_BASE=   ${GITHUB_PROJECT}-${PKGVERSION_NOREV}

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
