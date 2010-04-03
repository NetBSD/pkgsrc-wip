# $NetBSD: Makefile,v 1.8 2010/04/03 09:48:34 hfath Exp $

DISTNAME=	natali-1.25
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ppr/}

MAINTAINER=	hauke@Espresso.Rhein-Neckar.DE
HOMEPAGE=	http://ppr.trincoll.edu/
COMMENT=	AT&T/Apple AppleTalk Library Interface for Netatalk

PKG_DESTDIR_SUPPORT=	user-destdir
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

.include "../../net/netatalk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
