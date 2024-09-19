# $NetBSD: Makefile,v 1.3 2014/02/11 21:04:09 noud4 Exp $
#

DISTNAME=	gsmartcontrol-1.1.3
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gsmartcontrol/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	noud4@users.sourceforge.net
HOMEPAGE=	https://gsmartcontrol.sourceforge.io/
COMMENT=	Hard disk drive health inspection tool
LICENSE=	gnu-gpl-v2 AND gnu-gpl-v3

DEPENDS+=	smartmontools>=5.40:../../sysutils/smartmontools

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config
USE_TOOLS+=	bash:run
REPLACE_BASH=	data/gsmartcontrol-root.in

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtkmm3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
