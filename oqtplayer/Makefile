# $NetBSD: Makefile,v 1.1.1.1 2004/04/16 11:21:12 tripledes Exp $
#

DISTNAME=		oqtplayer-0.5-src
PKGNAME=		${DISTNAME:C/-src//}
CATEGORIES=		security net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=openquicktime/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.openquicktime.org/
COMMENT=		Small OpenQuickTime (TM) player, using SDL

USE_BUILDLINK3=		yes

WRKSRC=			${WRKDIR}/OQTPlayer-0.5

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/oqtplayer
	${INSTALL_PROGRAM} ${WRKSRC}/oqtplayer ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/readme ${PREFIX}/share/oqtplayer/

.include "../../devel/SDL/buildlink3.mk"
.include "../../multimedia/openquicktime/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
