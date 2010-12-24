# $NetBSD: Makefile,v 1.5 2010/12/24 13:17:28 noud4 Exp $

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

NAME=StarterBar
GDESKLETSDIR=	${LOCALBASE}/share/gdesklets

post-extract:
	${PYTHONBIN} ${WRKSRC}/Install_${NAME}_Sensor.bin --nomsg ${WRKSRC}

do-install:
	${INSTALL_DATA_DIR} ${GDESKLETSDIR}/Displays/${NAME}/gfx
	${INSTALL_DATA_DIR} ${GDESKLETSDIR}/Sensors/${NAME}/locale
	${INSTALL_DATA} ${WRKSRC}/*.display ${GDESKLETSDIR}/Displays/${NAME}
	${INSTALL_DATA} ${WRKSRC}/gfx/*.png \
		${GDESKLETSDIR}/Displays/${NAME}/gfx
	${INSTALL_DATA} ${WRKSRC}/${NAME}/*.py ${GDESKLETSDIR}/Sensors/${NAME}
	${INSTALL_DATA} ${WRKSRC}/${NAME}/home.desktop \
		${GDESKLETSDIR}/Sensors/${NAME}
	cd ${WRKSRC} && pax -rwpm ${NAME}/locale \
		${GDESKLETSDIR}/Sensors

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
