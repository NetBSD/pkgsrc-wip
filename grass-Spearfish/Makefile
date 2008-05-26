# $NetBSD: Makefile,v 1.4 2008/05/26 13:59:44 tnn2 Exp $
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
USE_TOOLS+=		pax

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/dataset
	${INSTALL_DATA_DIR} ${PREFIX}/share/dataset/geography
	${INSTALL_DATA_DIR} ${PREFIX}/share/dataset/geography/spearfish
	cd ${WRKSRC}/spearfish/ && 					  \
		pax -rw . ${PREFIX}/share/dataset/geography/spearfish/

.include "../../mk/bsd.pkg.mk"
