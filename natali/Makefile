# $NetBSD: Makefile,v 1.11 2014/09/08 12:37:30 thomasklausner Exp $

DISTNAME=	natali-1.25
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ppr/}

MAINTAINER=	hauke@NetBSD.org
HOMEPAGE=	http://ppr.trincoll.edu/
COMMENT=	AT&T/Apple AppleTalk Library Interface for Netatalk

INSTALLATION_DIRS=	lib include/at share/doc/natali

CONFLICTS=	netatalk-asun-[0-9]* netatalk-umich-[0-9]*

MAKE_ENV+=	ATALKINCDIR=-I${BUILDLINK_PREFIX.netatalk}/include
MAKE_ENV+=	ATALKLIBDIR=-L${BUILDLINK_PREFIX.netatalk}/lib

do-install:
	${INSTALL_DATA} ${WRKSRC}/History.txt ${DESTDIR}/${PREFIX}/share/doc/natali
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DESTDIR}/${PREFIX}/share/doc/natali
	${INSTALL_DATA} ${WRKSRC}/appletalk.h ${DESTDIR}/${PREFIX}/include/at
	${INSTALL_DATA} ${WRKSRC}/nbp.h ${DESTDIR}/${PREFIX}/include/at
	${INSTALL_DATA} ${WRKSRC}/pap.h ${DESTDIR}/${PREFIX}/include/at
	${INSTALL_DATA} ${WRKSRC}/libnatali.a ${DESTDIR}/${PREFIX}/lib

.include "../../net/netatalk22/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
