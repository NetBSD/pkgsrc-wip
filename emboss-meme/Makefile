# $NetBSD: Makefile,v 1.1.1.1 2004/11/15 20:23:10 daprice Exp $
#
.include "../emboss/Makefile.common"
.include "../emboss-base/Makefile.common"

DISTNAME=		MEME-2.3.1
PKGNAME=		emboss-meme-2.3.1
COMMENT=		Motif detection tool for EMBOSS

DIST_SUBDIR=		${PKG_DISTFILES_DIR}/meme-2.3.1-20041107

pre-configure:
	${SED} -e 's|@EMBOSSLIB@|${PREFIX}/lib|' \
	       -e 's|@INCLUDE@|${PREFIX}/include/emboss|' \
		${WRKSRC}/src/Makefile.in > ${WRKSRC}/src/Makefile.in.bak
	${MV} ${WRKSRC}/src/Makefile.in.bak ${WRKSRC}/src/Makefile.in

do-build:
	cd ${WRKSRC} && ${MAKE}

.include "../../mk/bsd.pkg.mk"
