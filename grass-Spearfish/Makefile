# $NetBSD: Makefile,v 1.2 2005/04/11 21:12:34 tvierling Exp $
#

DISTNAME=		spearfish_grass50data
PKGNAME=		grass-Spearfish-20030825
WRKSRC=			${WRKDIR}/
CATEGORIES=		geography
MASTER_SITES+=		http://grass.itc.it/sampledata/
MASTER_SITES+=		http://grass.ibiblio.org/sampledata/

MAINTAINER=		mchittur@cs.nmsu.edu
HOMEPAGE=		http://grass.itc.it/sampledata/
COMMENT=		Example data set for Grass 5.0

NO_CONFIGURE=		yes
NO_BUILD=		yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/dataset
	${INSTALL_DATA_DIR} ${PREFIX}/share/dataset/geography
	${INSTALL_DATA_DIR} ${PREFIX}/share/dataset/geography/spearfish
	cd ${WRKSRC}/spearfish/ && 					  \
		${PAX} -rw . ${PREFIX}/share/dataset/geography/spearfish/

.include "../../mk/bsd.pkg.mk"
