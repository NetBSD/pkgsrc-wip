# $NetBSD: Makefile,v 1.1 2013/04/20 19:39:12 noud4 Exp $
#

DISTNAME=	gsmartcontrol-0.8.7
CATEGORIES=	sysutils
MASTER_SITES=	http://artificialtime.com/gsmartcontrol/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	noud4@home.nl
HOMEPAGE=	http://gsmartcontrol.berlios.de
COMMENT=	Hard disk drive health inspection tool
LICENSE=	gnu-gpl-v2 AND gnu-gpl-v3

DEPENDS+=	smartmontools>=5.40:../../sysutils/smartmontools

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtkmm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
