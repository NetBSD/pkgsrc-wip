# $NetBSD$

DISTNAME=	libudev-0.2.1
PKGNAME=	go-${DISTNAME}
GITHUB_PROJECT=	libudev
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=oakmound/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/oakmound/libudev/
COMMENT=	Golang native implementation udev library
LICENSE=	mit

GO_SRCPATH=	github.com/oakmound/libudev
GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
