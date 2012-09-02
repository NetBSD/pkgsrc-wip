# $NetBSD: Makefile,v 1.3 2012/09/02 11:14:10 noud4 Exp $
#

.include "../emboss-base/Makefile.common"
.include "../emboss/Makefile.common"

DISTNAME=		PHYLIP-3.57c
PKGNAME=		emboss-phylip-3.57c
PKGREVISION=		1

COMMENT=		A package of programs for inferring phylogenies

DIST_SUBDIR=		emboss/phylip-3.57c-20041107
BUILD_TARGET=		#empty

pre-configure:
	${SED} -e 's|../../../ajax/libajax.la|${PREFIX}/lib/libajax.la|' \
	       -e 's|@INCLUDE@|${PREFIX}/include/emboss|' \
		${WRKSRC}/src/Makefile.in > \
		${WRKSRC}/src/Makefile.in.bak
	${MV} ${WRKSRC}/src/Makefile.in.bak \
	      ${WRKSRC}/src/Makefile.in

.include "../../mk/bsd.pkg.mk"
