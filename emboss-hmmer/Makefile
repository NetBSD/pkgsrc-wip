# $NetBSD: Makefile,v 1.5 2012/09/02 11:14:10 noud4 Exp $
#

.include "../emboss-base/Makefile.common"
.include "../emboss/Makefile.common"

DISTNAME=		HMMER-2.1.1
PKGNAME=		emboss-hmmer-2.1.1
PKGREVISION=		2

COMMENT=		A collection of bioinformatic programs that is supplimentary to EMBOSS package

DIST_SUBDIR=		emboss/hmmer-2.1.1-20041107
BUILD_TARGET=		#EMPTY

pre-configure:
	${SED} -e 's|../../../ajax/libajax.la|${PREFIX}/lib/libajax.la|' \
	       -e 's|@INCLUDE@|${PREFIX}/include/emboss|' \
		${WRKSRC}/src/Makefile.in > ${WRKSRC}/src/Makefile.in.bak
	${MV} ${WRKSRC}/src/Makefile.in.bak ${WRKSRC}/src/Makefile.in

.include "../../mk/bsd.pkg.mk"
