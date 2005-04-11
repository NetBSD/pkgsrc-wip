# $NetBSD: Makefile,v 1.4 2005/04/11 21:12:20 tvierling Exp $

DISTNAME=	rssgrab-0.5
PKGNAME=	gDesklets-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	http://gdesklets.gnomedesktop.org/files/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://gdesklets.gnomedesktop.org/categories.php?func=gd_show_app&gd_app_id=101
COMMENT=	RSS/RDF News Feed Grabber

DEPENDS+=	gDesklets-[0-9]*:../../wip/gDesklets

NO_CONFIGURE=	yes
NO_BUILD=	yes

NAME=rssgrab
GDESKLETSDIR=		${LOCALBASE}/share/gdesklets

PYTHON_PATCH_SCRIPTS=	${NAME}/feedparser.py

post-extract:
	${PYTHONBIN} ${WRKSRC}/Install_${NAME}_Sensor.bin --nomsg ${WRKSRC}

do-install:
	${INSTALL_DATA_DIR} ${GDESKLETSDIR}/Displays/${NAME}/gfx
	${INSTALL_DATA_DIR} ${GDESKLETSDIR}/Sensors/${NAME}
	${INSTALL_DATA} ${WRKSRC}/*.display ${GDESKLETSDIR}/Displays/${NAME}
	${INSTALL_DATA} ${WRKSRC}/gfx/*.png \
		${GDESKLETSDIR}/Displays/${NAME}/gfx
	${INSTALL_DATA} ${WRKSRC}/${NAME}/*.py ${GDESKLETSDIR}/Sensors/${NAME}

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
