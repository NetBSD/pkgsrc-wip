# $NetBSD: Makefile,v 1.6 2012/09/28 23:29:43 asau Exp $

DISTNAME=	starterbar-desklet-0.31.3
PKGNAME=	gDesklets-${DISTNAME:S/-desklet//}
CATEGORIES=	x11
MASTER_SITES=	http://www.gdesklets.info/archive/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.gdesklets.info/archive/#S
COMMENT=	Icon bar for GNOME where you can put starters into

DEPENDS=	gDesklets-[0-9]*:../../wip/gDesklets

NO_CONFIGURE=	yes
NO_BUILD=	yes
USE_TOOLS+=	pax

NAME=		StarterBar
GDESKLETSDIR=	${LOCALBASE}/share/gdesklets

post-extract:
	${PYTHONBIN} ${WRKSRC}/Install_${NAME}_Sensor.bin --nomsg ${WRKSRC}

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${GDESKLETSDIR}/Displays/${NAME}/gfx
	${INSTALL_DATA_DIR} ${DESTDIR}${GDESKLETSDIR}/Sensors/${NAME}/locale
	${INSTALL_DATA} ${WRKSRC}/*.display ${DESTDIR}${GDESKLETSDIR}/Displays/${NAME}
	${INSTALL_DATA} ${WRKSRC}/gfx/*.png \
		${DESTDIR}${GDESKLETSDIR}/Displays/${NAME}/gfx
	${INSTALL_DATA} ${WRKSRC}/${NAME}/*.py ${DESTDIR}${GDESKLETSDIR}/Sensors/${NAME}
	${INSTALL_DATA} ${WRKSRC}/${NAME}/home.desktop \
		${DESTDIR}${GDESKLETSDIR}/Sensors/${NAME}
	cd ${WRKSRC} && pax -rwpm ${NAME}/locale \
		${DESTDIR}${GDESKLETSDIR}/Sensors

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
