# $NetBSD: Makefile,v 1.2 2005/04/11 21:14:35 tvierling Exp $
#

DISTNAME=		oqtplayer-0.5-src
PKGNAME=		${DISTNAME:C/-src//}
CATEGORIES=		security net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=openquicktime/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.openquicktime.org/
COMMENT=		Small OpenQuickTime (TM) player, using SDL


WRKSRC=			${WRKDIR}/OQTPlayer-0.5

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/oqtplayer
	${INSTALL_PROGRAM} ${WRKSRC}/oqtplayer ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/readme ${PREFIX}/share/oqtplayer/

.include "../../devel/SDL/buildlink3.mk"
.include "../../multimedia/openquicktime/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
