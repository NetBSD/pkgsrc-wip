# $NetBSD$

PKGNAME=	modd-0.8
PKGREVISION=	5
DISTNAME=	modd-${GITHUB_TAG}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=cortesi/}
GITHUB_PROJECT=	modd
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	iku.iwasa@gmail.com
HOMEPAGE=	https://github.com/cortesi/modd
COMMENT=	Developer tool that runs processes and responds to filesystem changes

LICENSE=	mit

EXTRACT_USING=	bsdtar

GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
GO_SRCPATH=	github.com/cortesi/modd/

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/modd ${DESTDIR}${PREFIX}/bin

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
