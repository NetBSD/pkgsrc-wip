# $NetBSD: Makefile,v 1.1.1.1 2004/11/15 20:21:19 daprice Exp $
#
.include "../emboss/Makefile.common"
.include "../emboss-base/Makefile.common"

DISTNAME=		HMMER-2.1.1
PKGNAME=		emboss-hmmer-2.1.1
COMMENT=		A collection of bioinformatic programs that is supplimentary to EMBOSS package

DIST_SUBDIR=		${PKG_DISTFILES_DIR}/hmmer-2.1.1-20041107

pre-configure:
	${SED} -e 's|../../../ajax/libajax.la|${PREFIX}/lib/libajax.la|' \
	       -e 's|@INCLUDE@|${PREFIX}/include/emboss|' \
		${WRKSRC}/src/Makefile.in > ${WRKSRC}/src/Makefile.in.bak
	${MV} ${WRKSRC}/src/Makefile.in.bak ${WRKSRC}/src/Makefile.in

do-build:
	cd ${WRKSRC} && ${MAKE} ${BUILD}

.include "../../mk/bsd.pkg.mk"
