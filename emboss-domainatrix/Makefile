# $NetBSD: Makefile,v 1.1.1.1 2004/11/15 19:45:00 daprice Exp $
#
.include "../emboss/Makefile.common"
.include "../emboss-base/Makefile.common"

DISTNAME=		DOMAINATRIX-1.0.0
PKGNAME=		emboss-domainatrix-1.0.0
COMMENT=		Collection of bioinformatic programs for EMBOSS

DIST_SUBDIR=		${PKG_DISTFILES_DIR}/domainatrix-1.0.0-20040715


pre-configure:
	${SED} -e 's|../../../plplot/libplplot.la|${PREFIX}/lib/libplplot.la|' \
	       -e 's|../../../ajax/libajaxg.la|${PREFIX}/lib/libajaxg.la|' \
	       -e 's|../../../ajax/libajax.la|${PREFIX}/lib/libajax.la|' \
	       -e 's|../../../nucleus/libnucleus.la|${PREFIX}/lib/libnucleus.la|' \
	       -e 's|/../../depcomp|/depcomp|' \
	       -e 's|@INCLUDE@|${PREFIX}/include/emboss|' \
	       -e 's|@X116@|-Wl,-R${X11BASE}/lib|' \
	       ${WRKSRC}/src/Makefile.in > ${WRKSRC}/src/Makefile.in.bak
	${MV} ${WRKSRC}/src/Makefile.in.bak ${WRKSRC}/src/Makefile.in

do-build:
	cd ${WRKSRC} && ${MAKE}

.include "../../mk/bsd.pkg.mk"

