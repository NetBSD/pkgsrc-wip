# $NetBSD: Makefile,v 1.1.1.1 2004/11/15 20:09:38 daprice Exp $
#

.include "../emboss/Makefile.common"
.include "../emboss-base/Makefile.common"

DISTNAME=		EMNU-1.05
PKGNAME=		emboss-emnu-1.05
COMMENT=		Simple menu for EMBOSS applications

USE_NCURSES=            yes

CONFIGURE_ARGS+=        --prefix=${PREFIX}

DIST_SUBDIR=		${PKG_DISTFILES_DIR}/emnu-1.05-20041107

pre-configure:
	${SED} -e 's|../../../plplot/libplplot.la|${PREFIX}/lib/libplplot.la|' \
	       -e 's|../../../ajax/libajax.la|${PREFIX}/lib/libajax.la|' \
	       -e 's|../../../nucleus/libnucleus.la|${PREFIX}/lib/libnucleus.la|' \
	       -e 's|@NCURSES@|-L${PREFIX}/lib -lncurses|' \
	       -e 's|@X116@|-Wl,-R${X11BASE}/lib|' \
	       -e 's|@INCLUDE@|-I${PREFIX}/include/emboss|' \
		${WRKSRC}/source/Makefile.in > ${WRKSRC}/source/Makefile.in.bak
	${MV} ${WRKSRC}/source/Makefile.in.bak ${WRKSRC}/source/Makefile.in
	${SED} -e 's|@X116@|-Wl,-R${X11BASE}/lib|' \
		${WRKSRC}/Makefile.in > ${WRKSRC}/Makefile.in.bak
	${MV} ${WRKSRC}/Makefile.in.bak ${WRKSRC}/Makefile.in

do-build:
	cd ${WRKSRC} && ${MAKE}

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
