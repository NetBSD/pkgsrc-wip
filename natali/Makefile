# $NetBSD: Makefile,v 1.1.1.1 2003/11/14 21:46:39 hfath Exp $

DISTNAME=	natali-1.25
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ppr/}

MAINTAINER=	hauke@Espresso.Rhein-Neckar.DE
HOMEPAGE=	http://ppr.trincoll.edu/
COMMENT=	AT&T/Apple AppleTalk Library Interface for Netatalk

USE_BUILDLINK2=	YES

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

.include "../../net/netatalk/buildlink2.mk"

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
