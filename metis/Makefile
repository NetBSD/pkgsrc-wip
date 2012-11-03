# $NetBSD: Makefile,v 1.4 2012/11/03 13:42:24 outpaddling Exp $

DISTNAME=		metis-4.0
CATEGORIES=		math
MASTER_SITES=		http://glaros.dtc.umn.edu/gkhome/fetch/sw/metis/

MAINTAINER=		jwbacon@tds.net
HOMEPAGE=		http://glaros.dtc.umn.edu/gkhome/views/metis/
COMMENT=		Unstructured graph partitioning and sparse matrix ordering system

BUILD_TARGET=		default
INSTALLATION_DIRS=	bin lib

LICENSE=	modified-bsd

SUBST_CLASSES+=         log2
SUBST_SED.log2=         -e "s/log2/int_log2/g"
SUBST_STAGE.log2=       post-patch
SUBST_FILES.log2=       Lib/*

do-test:
	cd ${WRKSRC}/Graphs && ./mtest 4elt.graph
	cd ${WRKSRC}/Graphs && ./mtest test.mgraph

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} graphchk kmetis mesh2dual 	\
		mesh2nodal oemetis onmetis partdmesh partnmesh pmetis	\
		${DESTDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/libmetis.a ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/include/metis
	${INSTALL_DATA} ${WRKSRC}/Lib/*.h				\
		${DESTDIR}${PREFIX}/include/metis/
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/metis
	${INSTALL_DATA} ${WRKSRC}/Doc/manual.ps				\
		${DESTDIR}${PREFIX}/share/doc/metis
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/metis
	cd ${WRKSRC}/Graphs && ${INSTALL_DATA} 0README 4elt.graph 	\
		metis.mesh test.mgraph					\
		${DESTDIR}${PREFIX}/share/examples/metis/
	${INSTALL_DATA} ${WRKSRC}/Test/mtest.c				\
		${DESTDIR}${PREFIX}/share/examples/metis

.include "../../mk/bsd.pkg.mk"
