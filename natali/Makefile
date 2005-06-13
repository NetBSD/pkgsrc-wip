# $NetBSD: Makefile,v 1.4 2005/06/13 00:47:00 kristerw Exp $

DISTNAME=	natali-1.25
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ppr/}

MAINTAINER=	hauke@Espresso.Rhein-Neckar.DE
HOMEPAGE=	http://ppr.trincoll.edu/
COMMENT=	AT&T/Apple AppleTalk Library Interface for Netatalk


CONFLICTS=	netatalk-asun-[0-9]* netatalk-umich-[0-9]*

.include "../../mk/bsd.prefs.mk"

MAKE_ENV+=	ATALKINCDIR=-I${LOCALBASE}/include
MAKE_ENV+=	ATALKLIBDIR=-L${LOCALBASE}/lib

do-install:
	${INSTALL_DATA} ${WRKSRC}/History.txt ${PREFIX}/share/doc/natali
	${INSTALL_DATA} ${WRKSRC}/README.txt ${PREFIX}/share/doc/natali
	${INSTALL_DATA_DIR} ${PREFIX}/include/at
	${INSTALL_DATA} ${WRKSRC}/appletalk.h ${PREFIX}/include/at
	${INSTALL_DATA} ${WRKSRC}/nbp.h ${PREFIX}/include/at
	${INSTALL_DATA} ${WRKSRC}/pap.h ${PREFIX}/include/at
	${INSTALL_DATA} ${WRKSRC}/libnatali.a ${PREFIX}/lib

.include "../../net/netatalk/buildlink3.mk"

.include "../../mk/install/bsd.pkginstall.mk"
.include "../../mk/bsd.pkg.mk"
