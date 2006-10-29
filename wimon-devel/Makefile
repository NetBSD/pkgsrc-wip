# $NetBSD: Makefile,v 1.7 2006/10/29 08:32:57 shattered Exp $
#

DISTNAME=	wimon-0.3
CATEGORIES=	net
MASTER_SITES=	http://imil.net/wimon/

MAINTAINER=	imil@gcu.info
HOMEPAGE=	http://imil.net/wimon/
COMMENT=	Tool that shows a real-time graph of your wireless connection

PKG_INSTALLATION_TYPES=	overwrite pkgviews

ONLY_FOR_PLATFORM=	FreeBSD-*-* NetBSD-*-* OpenBSD-*-*

WRKSRC=		${WRKDIR}/wimon

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wimon ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/wimon.8 ${PREFIX}/${PKGMANDIR}/man8/wimon.8

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
