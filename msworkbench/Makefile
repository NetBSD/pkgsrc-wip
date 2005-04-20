# $NetBSD: Makefile,v 1.3 2005/04/20 00:07:29 daprice Exp $
#

DISTNAME=		msworkbench-0.3
CATEGORIES=		geography
MASTER_SITES=		http://download.sourceforge.net/msworkbench/

MAINTAINER=		mchittur@cs.nmsu.edu
HOMEPAGE=		http://download.sourceforge.net/msworkbench/
COMMENT=		Set of tools for development of MapServer web mapping applications

WRKSRC=			${WRKDIR}/msworkbench

pre-install:
	${SED} -e 's:$${PREFIX}:${PREFIX}:g' ${WRKSRC}/install.sh > ${WRKSRC}/install.sh.temp
	${MV} ${WRKSRC}/install.sh.temp ${WRKSRC}/install.sh

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/bin/${DISTNAME}
	cd ${WRKSRC};${SH} ./install.sh ${PREFIX}/bin/${DISTNAME} ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/${DISTNAME}
	${INSTALL_DATA} ${WRKSRC}/test/*.* ${PREFIX}/share/examples/${DISTNAME}

.include "../../lang/tcl/buildlink3.mk"
.include "../../wip/mapserver/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
