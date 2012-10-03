# $NetBSD: Makefile,v 1.7 2012/10/03 21:24:36 asau Exp $
#

DISTNAME=		oqtplayer-0.5-src
PKGNAME=		${DISTNAME:C/-src//}
PKGREVISION=		2
CATEGORIES=		security net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=openquicktime/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.openquicktime.org/
COMMENT=		Small OpenQuickTime (TM) player, using SDL

WRKSRC=			${WRKDIR}/OQTPlayer-0.5
INSTALLATION_DIRS+=	bin share/oqtplayer

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/oqtplayer ${DESTDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/readme ${DESTDIR}${PREFIX}/share/oqtplayer/

.include "../../devel/SDL/buildlink3.mk"
.include "../../multimedia/openquicktime/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
