# $NetBSD: Makefile,v 1.1.1.1 2004/07/09 09:00:27 imilh Exp $
#

DISTNAME=	wimon-0.2.1
CATEGORIES=	net
MASTER_SITES=	http://imil.net/wimon/

MAINTAINER=	imil@gcu.info
HOMEPAGE=	http://imil.net/wimon/
COMMENT=	Tool that shows a real-time graph of your wireless connection

PKG_INSTALLATION_TYPES=	overwrite pkgviews

ONLY_FOR_PLATFORM=      FreeBSD-*-* NetBSD-*-* OpenBSD-*-*

WRKSRC=		${WRKDIR}/wimon
USE_BUILDLINK3=	yes

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wimon ${PREFIX}/bin

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
