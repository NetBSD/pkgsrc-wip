# $NetBSD: Makefile,v 1.3 2005/04/19 23:04:35 daprice Exp $
#

DISTNAME=		spearfish_grass50data
PKGNAME=		grass-Spearfish-20030825
CATEGORIES=		geography
MASTER_SITES+=		http://grass.itc.it/sampledata/
MASTER_SITES+=		http://grass.ibiblio.org/sampledata/

MAINTAINER=		mchittur@cs.nmsu.edu
HOMEPAGE=		http://grass.itc.it/sampledata/
COMMENT=		Example data set for Grass 5.0

WRKSRC=			${WRKDIR}/
NO_CONFIGURE=		yes
NO_BUILD=		yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/dataset
	${INSTALL_DATA_DIR} ${PREFIX}/share/dataset/geography
	${INSTALL_DATA_DIR} ${PREFIX}/share/dataset/geography/spearfish
	cd ${WRKSRC}/spearfish/ && 					  \
		${PAX} -rw . ${PREFIX}/share/dataset/geography/spearfish/

.include "../../mk/bsd.pkg.mk"
