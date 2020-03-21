# $NetBSD$

PKGNAME=	devd-0.9
PKGREVISION=	5
DISTNAME=	devd-${GITHUB_TAG}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=cortesi/}
GITHUB_PROJECT=	devd
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	iku.iwasa@gmail.com
HOMEPAGE=	https://github.com/cortesi/devd
COMMENT=	Local webserver for developers

LICENSE=	mit

EXTRACT_USING=	bsdtar

GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
GO_SRCPATH=	github.com/cortesi/devd/

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/devd ${DESTDIR}${PREFIX}/bin

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
