# $NetBSD: Makefile,v 1.4 2005/04/20 00:08:45 daprice Exp $
#

DISTNAME=		msworkbench-0.3
CATEGORIES=		geography
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=msworkbench/}

MAINTAINER=		mchittur@cs.nmsu.edu
HOMEPAGE=		http://msworkbench.sourceforge.net/
COMMENT=		Set of tools for development of MapServer web mapping applications

WRKSRC=			${WRKDIR}/msworkbench

SUBST_CLASSES=		wishpath
SUBST_STAGE.wishpath=	pre-install
SUBST_FILES.wishpath=	install.sh
SUBST_SED.qtbindir=	's:$${PREFIX}:${PREFIX}:g'
SUBST_MESSAGE.wishpath= "Fixing Wish path"

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/bin/${DISTNAME}
	cd ${WRKSRC};${SH} ./install.sh ${PREFIX}/bin/${DISTNAME} ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/${DISTNAME}
	${INSTALL_DATA} ${WRKSRC}/test/*.* ${PREFIX}/share/examples/${DISTNAME}

.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../wip/mapserver/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
