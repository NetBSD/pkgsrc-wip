# $NetBSD$

DISTNAME=	direnv-2.8.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=direnv/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	terin@terinstock.com
HOMEPAGE=	http://direnv.net/
COMMENT=	Environment switcher for the shell
LICENSE=	mit

BUILD_DEPENDS+=	go>=1.6:../../lang/go

USE_TOOLS+=	gmake

do-install:
	${INSTALL_PROGRAM_DIR} ${DESTDIR}/${PREFIX}/bin
	${INSTALL_MAN_DIR} ${DESTDIR}/${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_PROGRAM} ${WRKSRC}/direnv ${DESTDIR}/${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/*.1 ${DESTDIR}/${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
