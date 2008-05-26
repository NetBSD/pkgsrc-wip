# $NetBSD: Makefile,v 1.4 2008/05/26 13:59:44 tnn2 Exp $

DISTNAME=	starterbar-desklet-0.22.1
PKGNAME=	gDesklets-${DISTNAME:S/-desklet//}
CATEGORIES=	x11
MASTER_SITES=	http://www.gdesklets.org/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.gdesklets.org/
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
