# $NetBSD: Makefile,v 1.2 2004/12/14 19:11:47 daprice Exp $
#

.include "../emboss-base/Makefile.common"
.include "../emboss/Makefile.common"

DISTNAME=		HMMER-2.1.1
PKGNAME=		emboss-hmmer-2.1.1

COMMENT=		A collection of bioinformatic programs that is supplimentary to EMBOSS package

DIST_SUBDIR=		emboss/hmmer-2.1.1-20041107
BUILD_TARGET=		#EMPTY 

pre-configure:
	${SED} -e 's|../../../ajax/libajax.la|${PREFIX}/lib/libajax.la|' \
	       -e 's|@INCLUDE@|${PREFIX}/include/emboss|' \
		${WRKSRC}/src/Makefile.in > ${WRKSRC}/src/Makefile.in.bak
	${MV} ${WRKSRC}/src/Makefile.in.bak ${WRKSRC}/src/Makefile.in

.include "../../mk/bsd.pkg.mk"
