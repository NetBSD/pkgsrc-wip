# $NetBSD$

DISTNAME=	tail-1.4.6
PKGNAME=	go-${DISTNAME}
GITHUB_PROJECT=	tail
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=nxadm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/nxadm/tail/
COMMENT=	Go package for reading from continously updated files
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
GO_SRCPATH=	github.com/nxadm/tail


post-install:
	${RM} -rf ${DESTDIR}${PREFIX}/gopkg/src/${GO_SRCPATH}/vendor

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
