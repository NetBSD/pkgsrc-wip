# $NetBSD: Makefile,v 1.1.1.1 2004/11/15 20:26:18 daprice Exp $
#

.include "../emboss/Makefile.common"
.include "../emboss-base/Makefile.common"

DISTNAME=	MSE-1.0.0
PKGNAME=	emboss-mse-1.0.0
COMMENT=	Multiple Sequence Editor for EMBOSS
USE_NCURSES=    yes
DIST_SUBDIR=		emboss-2.9.0/mse-1.0.0-20041107

DIST_SUBDIR=		${PKG_DISTFILES_DIR}/mse-1.0.0-20041107

pre-configure:
	${SED} -e 's|@EMBOSSLIB@|${PREFIX}/lib|' \
	       -e 's|@NCURSES@|-L${PREFIX}/lib -lncurses|' \
	       -e 's|@INCLUDE@|${PREFIX}/include -I${PREFIX}/include/emboss|' \
		${WRKSRC}/source/Makefile.in > ${WRKSRC}/source/Makefile.in.bak
	${MV} ${WRKSRC}/source/Makefile.in.bak ${WRKSRC}/source/Makefile.in
	${SED} -e 's|@NCURSES@|-L${PREFIX}/lib -lncurses|' \
		${WRKSRC}/h/Makefile.in > ${WRKSRC}/h/Makefile.in.bak
	${MV} ${WRKSRC}/h/Makefile.in.bak ${WRKSRC}/h/Makefile.in

do-build:
	cd ${WRKSRC} && ${MAKE}

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
