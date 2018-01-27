# $NetBSD: Makefile,v 1.4 2006/10/29 11:23:07 shattered Exp $
#

.include "../../wip/emboss-base/Makefile.common"
.include "../../wip/emboss/Makefile.common"

DISTNAME=	MSE-1.0.0
PKGNAME=	emboss-mse-1.0.0

COMMENT=	Multiple Sequence Editor for EMBOSS

#ncurses required because:
#mse.c: In function `Initscr':
#mse.c:148: dereferencing pointer to incomplete type
#mse.c:149: dereferencing pointer to incomplete type
#mse.c 148  __Cols=Display->_maxx;
#mse.c 149  __Rows=Display->_maxy;
USE_NCURSES=	yes
DIST_SUBDIR=	emboss/mse-1.0.0-20041107
BUILD_TARGET=	#empty

pre-configure:
	${SED} -e 's|@EMBOSSLIB@|${PREFIX}/lib|' \
	       -e 's|@NCURSES@|-L${PREFIX}/lib -lncurses|' \
	       -e 's|@INCLUDE@|${PREFIX}/include -I${PREFIX}/include/emboss|' \
		${WRKSRC}/source/Makefile.in > ${WRKSRC}/source/Makefile.in.bak
	${MV} ${WRKSRC}/source/Makefile.in.bak ${WRKSRC}/source/Makefile.in
	${SED} -e 's|@NCURSES@|-L${PREFIX}/lib -lncurses|' \
		${WRKSRC}/h/Makefile.in > ${WRKSRC}/h/Makefile.in.bak
	${MV} ${WRKSRC}/h/Makefile.in.bak ${WRKSRC}/h/Makefile.in

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
