# $NetBSD: Makefile,v 1.1.1.1 2004/11/15 20:27:50 daprice Exp $
#
.include "../emboss/Makefile.common"
.include "../emboss-base/Makefile.common"

DISTNAME=	PHYLIP-3.57c
PKGNAME=	emboss-phylip-3.57c
COMMENT=	A package of programs for inferring phylogenies

DIST_SUBDIR=		${PKG_DISTFILES_DIR}/phylip-3.57c-20041107

pre-configure:
	${SED} -e 's|../../../ajax/libajax.la|${PREFIX}/lib/libajax.la|' \
	       -e 's|@INCLUDE@|${PREFIX}/include/emboss|' \
		${WRKSRC}/src/Makefile.in > \
		${WRKSRC}/src/Makefile.in.bak
	${MV} ${WRKSRC}/src/Makefile.in.bak \
	      ${WRKSRC}/src/Makefile.in

do-build:
	cd ${WRKSRC} && ${MAKE}

.include "../../mk/bsd.pkg.mk"
