# $NetBSD: Makefile,v 1.2 2004/12/14 19:49:07 daprice Exp $
#

.include "../emboss-base/Makefile.common"
.include "../emboss/Makefile.common"

DISTNAME=		TOPO-1.0.0
PKGNAME=		emboss-topo-1.0.0

COMMENT=		Draws an image of a transmembrane protein

DIST_SUBDIR=		${PKG_DISTFILES_DIR}/topo-1.0.0-20041107
BUILD_TARGET=		#empty

pre-configure:
	${SED} -e 's|@X116@|-Wl,-R${X11BASE}/lib|' \
	       -e 's|@INCLUDE@|${PREFIX}/include/emboss|' \
		${WRKSRC}/source/Makefile.in > ${WRKSRC}/source/Makefile.in.bak
	${MV} ${WRKSRC}/source/Makefile.in.bak ${WRKSRC}/source/Makefile.in

.include "../../mk/bsd.pkg.mk"
