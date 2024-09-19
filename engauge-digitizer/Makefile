# $NetBSD: Makefile,v 1.2 2012/09/28 22:07:34 asau Exp $
#

VER=		5.2
DISTNAME=	engauge_${VER}
PKGNAME=	engauge-${VER}
CATEGORIES=	graphics
MASTER_SITES=	http://downloads.sourceforge.net/project/digitizer/Engauge%20Digitizer/digitizer-${VER}/
EXTRACT_SUFX=	.tgz

MAINTAINER=	slitvinov@gmail.com
HOMEPAGE=	http://digitizer.sourceforge.net/
COMMENT=	Converts an image file with graph or map into numbers
LICENSE=	gnu-gpl-v2


WRKSRC=		${WRKDIR}/engauge-${VER}
USE_LANGUAGES=	c++

USE_TOOLS+=	gmake
QMAKE=		${QTDIR}/bin/qmake

do-configure:
	cd ${WRKSRC} && \
	${QMAKE} -unix digitizer.pro ${CONFIG_OPTIONS} ${MAKE_ENV}

INSTALLATION_DIRS=	bin
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/engauge ${DESTDIR}${PREFIX}/bin

.include "../../math/fftw/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
