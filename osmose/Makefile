# $NetBSD$
#
DISTNAME=	Osmose-${PKGVERSION_NOREV:S/./-/g}-QT
PKGNAME=	osmose-0.9.96
CATEGORIES=	emulators
MASTER_SITES=	http://bcz.asterope.fr/osmose/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://bcz.emu-france.com/index.htm
COMMENT=	Sega Master System/Game Gear emulator
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

INSTALLATION_DIRS=	bin
INSTALLATION_DIRS+=	share/doc/${PKGBASE}

QMAKE=${QTDIR}/bin/qmake

do-configure:
	cd ${WRKSRC} && \
	env QTDIR=${QTDIR} ${QMAKE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${DISTNAME} ${DESTDIR}${PREFIX}/bin/osmose
	${INSTALL_DATA} ${WRKSRC}/Readme.txt ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
