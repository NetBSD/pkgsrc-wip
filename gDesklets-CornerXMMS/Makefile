# $NetBSD: Makefile,v 1.1.1.1 2004/01/26 04:46:20 minskim Exp $

DISTNAME=	CornerXMMS-0.0.5
CATEGORIES=	audio
MASTER_SITES=	http://gdesklets.gnomedesktop.org/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	minskim@bawi.org
HOMEPAGE=	http://gdesklets.gnomedesktop.org/categories.php?func=gd_show_app&gd_app_id=53
COMMENT=	Fancy desklet that allows you to control XMMS

DEPENDS+=	gDesklets-[0-9]*:../../wip/gDesklets
DEPENDS+=	${PYPKGPREFIX}-xmms-[0-9]*:../../wip/py-xmms

USE_BUILDLINK2=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

NAME=		CornerXMMS
GDESKLETSDIR=	${LOCALBASE}/share/gdesklets

do-install:
	${INSTALL_DATA_DIR} ${GDESKLETSDIR}/Displays/${NAME}/gfx
	${INSTALL_DATA} ${WRKSRC}/*.display ${GDESKLETSDIR}/Displays/${NAME}
	${INSTALL_DATA} ${WRKSRC}/gfx/*.png \
		${GDESKLETSDIR}/Displays/${NAME}/gfx
	${PYTHONBIN} ${WRKSRC}/Install_${NAME}_Sensor.bin --nomsg \
		${GDESKLETSDIR}/Sensors

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
