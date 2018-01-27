# $NetBSD: Makefile,v 1.7 2014/01/25 10:45:27 thomasklausner Exp $

DISTNAME=	rssgrab-0.6.4
PKGNAME=	gDesklets-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	http://www.gdesklets.info/archive/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.gdesklets.info/archive/#R
COMMENT=	RSS/RDF News Feed Grabber

DEPENDS+=	gDesklets-[0-9]*:../../wip/gDesklets

NO_CONFIGURE=	yes
NO_BUILD=	yes

NAME=		rssgrab
GDESKLETSDIR=	${LOCALBASE}/share/gdesklets

REPLACE_PYTHON=	${NAME}/feedparser.py

post-extract:
	${PYTHONBIN} ${WRKSRC}/Install_${NAME}_Sensor.bin --nomsg ${WRKSRC}

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${GDESKLETSDIR}/Displays/${NAME}/gfx
	${INSTALL_DATA_DIR} ${DESTDIR}${GDESKLETSDIR}/Sensors/${NAME}
	${INSTALL_DATA} ${WRKSRC}/*.display ${DESTDIR}${GDESKLETSDIR}/Displays/${NAME}
	${INSTALL_DATA} ${WRKSRC}/gfx/*.png \
		${DESTDIR}${GDESKLETSDIR}/Displays/${NAME}/gfx
	${INSTALL_DATA} ${WRKSRC}/${NAME}/*.py ${DESTDIR}${GDESKLETSDIR}/Sensors/${NAME}

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
