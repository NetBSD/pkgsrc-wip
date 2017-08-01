# $NetBSD: Makefile,v 1.6 2012/09/24 16:56:26 asau Exp $
#

DISTNAME=	Chinput-3.0.2
PKGREVISION=	1
CATEGORIES=	inputmethod
MASTER_SITES=	${MASTER_SITE_GENTOO:=distfiles/}

MAINTAINER=	rxg@NetBSD.org
#HOMEPAGE=	http://www.opencjk.org/~yumj/project-chinput.html
COMMENT=	Chinese input server

USE_X11BASE=	yes

BUILD_TARGET=	chinput

EGDIR=		${PREFIX}/share/examples/${PKGBASE}
CONF_FILES=	${EGDIR}/Chinput.ad ${PKG_SYSCONFDIR}/Chinput.ad

post-patch:
	${SED} -e 's:/usr/dict:'${LOCALBASE}/lib/unicon':g' < \
		${WRKSRC}/src/init.c > ${WRKSRC}/src/init.c.tmp
	${SED} -e 's:/usr/lib/ZWinPro:'${PREFIX}/etc':g' < \
		${WRKSRC}/src/init.c.tmp > ${WRKSRC}/src/init.c
	${MV} ${WRKSRC}/resource/Chinput.ad ${WRKSRC}/resource/Chinput.ad.tmp
	${SED} -e 's:/usr/lib/unicon2:'${LOCALBASE}/lib/unicon':g' < \
		${WRKSRC}/resource/Chinput.ad.tmp > \
		${WRKSRC}/resource/Chinput.ad

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/chinput ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/resource/Chinput.ad ${DESTDIR}${EGDIR}/

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/Chinput
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DESTDIR}${PREFIX}/share/doc/Chinput

.include "../../inputmethod/unicon-im/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
