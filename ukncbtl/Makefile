# $NetBSD: Makefile,v 1.2 2012/10/07 17:41:39 asau Exp $
#

DISTNAME=	ukncbtl-0.0.1
CATEGORIES=	emulators
MASTER_SITES=	http://ukncbtl.googlecode.com/files/

MAINTAINER=	shattered@NetBSD.org
HOMEPAGE=	http://code.google.com/p/ukncbtl/
COMMENT=	Emulator of 'UKNC', a Soviet school computer
LICENSE=	gnu-lgpl-v3

GIT_REPOSITORIES=	ukncbtl-read-only
GIT_REPO.ukncbtl-read-only=	git@github.com:nzeemin/ukncbtl.git

WRKSRC=		${WRKDIR}/ukncbtl-read-only/src/UKNCBTL.Qt

USE_LANGUAGES=	c++
INSTALLATION_DIRS+=	bin share/ukncbtl

do-configure:
	cd ${WRKSRC} && ${SETENV} QTDIR=${QTDIR} ${QTDIR}/bin/qmake \
		QtUkncBtl.pro

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/QtUkncBtl ${DESTDIR}${PREFIX}/bin
	(cd ${WRKDIR}/ukncbtl-read-only/lib/roms && for m in *.bin; do \
		${INSTALL_DATA} "$$m" ${DESTDIR}${PREFIX}/share/ukncbtl; done)

.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
