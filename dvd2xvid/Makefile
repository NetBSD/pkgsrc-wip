# $NetBSD: Makefile,v 1.3 2010/06/13 22:46:59 thomasklausner Exp $
#

DISTNAME=	dvd2xvid-0.5.0
PKGREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	http://www.neoversum.org/download/

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	http://www.neoversum.org/
COMMENT=	Simple GUI for MEncoder to rip DVDs

USE_TOOLS+=	gmake
USE_LANGUAGES=	c++
USE_LIBTOOL=	yes

DEPENDS+=	mencoder-[0-9]*:../../multimedia/mencoder
DEPENDS+=	transcode>=0.6.10:../../multimedia/transcode
DEPENDS+=	gmplayer-[0-9]*:../../multimedia/gmplayer
BUILD_DEPENDS+=	qt3-libs>=3.3:../../x11/qt3
BUILD_DEPENDS+=	libdvdread>=0.9.4:../../multimedia/libdvdread
BUILD_DEPENDS+=	xvidcore>=1.0:../../multimedia/xvidcore

INSTALLATION_DIRS=	bin share/dvd2xvid share/dvd2xvid/icons

do-build:
	cd ${WRKSRC} && QTDIR=${PREFIX}/qt3 gmake dvd2xvid
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dvd2xvid ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/dvd2xvid/icons
	${INSTALL_DATA} ${WRKSRC}/icons/* ${PREFIX}/share/dvd2xvid/icons

.include "../../multimedia/xvidcore/buildlink3.mk"
.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
