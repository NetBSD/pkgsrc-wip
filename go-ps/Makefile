# $NetBSD$

DISTNAME=	go-ps-20201120
GITHUB_PROJECT=	go-ps
GITHUB_TAG=	ddafa75
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=mitchellh/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/mitchellh/go-ps/
COMMENT=	Find, list, and inspect processes from Go
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}*
GO_SRCPATH=	github.com/mitchellh/go-ps

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
