# $NetBSD: Makefile,v 1.1.1.1 2004/11/15 20:30:04 daprice Exp $
#

.include "../emboss/Makefile.common"
.include "../emboss-base/Makefile.common"


DISTNAME=		TOPO-1.0.0
PKGNAME=		emboss-topo-1.0.0

COMMENT=		Draws an image of a transmembrane protein

DIST_SUBDIR=		${PKG_DISTFILES_DIR}/topo-1.0.0-20041107

pre-configure:
	${SED} -e 's|@X116@|-Wl,-R${X11BASE}/lib|' \
	       -e 's|@INCLUDE@|${PREFIX}/include/emboss|' \
		${WRKSRC}/source/Makefile.in > ${WRKSRC}/source/Makefile.in.bak
	${MV} ${WRKSRC}/source/Makefile.in.bak ${WRKSRC}/source/Makefile.in

do-build:
	cd ${WRKSRC} && ${MAKE}


.include "../../mk/bsd.pkg.mk"
