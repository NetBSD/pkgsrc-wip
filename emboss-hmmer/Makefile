# $NetBSD: Makefile,v 1.6 2012/11/13 22:25:30 othyro Exp $
#

.include "../emboss-base/Makefile.common"
.include "../emboss/Makefile.common"

DISTNAME=	HMMER-2.1.1
PKGNAME=	emboss-hmmer-2.1.1
PKGREVISION=	2

COMMENT=	Collection of bioinformatic programs supplimenting the EMBOSS package
LICENSE=	gnu-gpl-v2

DIST_SUBDIR=	emboss/hmmer-2.1.1-20041107
BUILD_TARGET=	#EMPTY

pre-configure:
	${SED} -e 's|../../../ajax/libajax.la|${PREFIX}/lib/libajax.la|' \
	       -e 's|@INCLUDE@|${PREFIX}/include/emboss|' \
		${WRKSRC}/src/Makefile.in > ${WRKSRC}/src/Makefile.in.bak
	${MV} ${WRKSRC}/src/Makefile.in.bak ${WRKSRC}/src/Makefile.in

.include "../../mk/bsd.pkg.mk"
