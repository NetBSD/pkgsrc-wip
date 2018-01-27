# $NetBSD: Makefile,v 1.8 2012/10/03 14:43:26 asau Exp $
#

DISTNAME=		msworkbench-0.3
CATEGORIES=		geography
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=msworkbench/}

MAINTAINER=		mchittur@cs.nmsu.edu
HOMEPAGE=		http://msworkbench.sourceforge.net/
COMMENT=		Set of tools for development of MapServer web mapping applications

DEPENDS+=		mapserver-[0-9]*:../../geography/mapserver

WRKSRC=			${WRKDIR}/msworkbench

SUBST_CLASSES+=		wishpath
SUBST_STAGE.wishpath=	pre-install
SUBST_FILES.wishpath=	install.sh
SUBST_SED.qtbindir=	's:$${PREFIX}:${PREFIX}:g'
SUBST_MESSAGE.wishpath=	Fixing Wish path

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/bin/${DISTNAME}
	cd ${WRKSRC};${SH} ./install.sh ${PREFIX}/bin/${DISTNAME} ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/${DISTNAME}
	${INSTALL_DATA} ${WRKSRC}/test/*.* ${DESTDIR}${PREFIX}/share/examples/${DISTNAME}

.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
