# $NetBSD: Makefile,v 1.1.1.1 2004/11/10 22:40:43 daprice Exp $

.include "Makefile.common"

DISTNAME=		EMBOSS-2.9.0

PKGNAME=		emboss-base-2.9.0

COMMENT=	 	European Molecular Biology Open Software Suite

DEPENDS+=		gd>=1.7.3:../../graphics/gd
DEPENDS+=		png>=1.0.5:../../graphics/png
DEPENDS+=		zlib>=1.1.3:../../devel/zlib
DEPENDS+=		jpeg>=6bnb1:../../graphics/jpeg

DIST_SUBDIR=		${PKG_DISTFILES_DIR}/emboss-2.9.0

post-extract:
	${CP} ${FILESDIR}/digestchange ${WRKSRC}/digestchange

post-patch:
	${SH} ${WRKSRC}/digestchange ${WRKSRC}
	${MV} ${WRKSRC}/doc/programs/text/digest.txt ${WRKSRC}/doc/programs/text/edigest.txt
	${MV} ${WRKSRC}/doc/programs/html/digest.html ${WRKSRC}/doc/programs/html/edigest.html
	${MV} ${WRKSRC}/emboss/digest.c ${WRKSRC}/emboss/edigest.c
	${MV} ${WRKSRC}/emboss/acd/digest.acd ${WRKSRC}/emboss/acd/edigest.acd
	${RM} -rf ${WRKSRC}/jemboss

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/emboss
	${INSTALL_DATA} ${WRKSRC}/ajax/*.h ${PREFIX}/include/emboss
	${INSTALL_DATA} ${WRKSRC}/nucleus/*.h ${PREFIX}/include/emboss
	${INSTALL_DATA} ${WRKSRC}/plplot/*.h ${PREFIX}/include/emboss
	${INSTALL_DATA_DIR} ${PREFIX}/share/EMBOSS/scripts
	${INSTALL_DATA} ${WRKSRC}/plplot/lib/plstnd5.fnt ${PREFIX}/share/EMBOSS
	${INSTALL_DATA} ${WRKSRC}/plplot/lib/plxtnd5.fnt ${PREFIX}/share/EMBOSS
	${INSTALL_DATA} ${WRKSRC}/config.guess ${PREFIX}/share/EMBOSS/scripts
	${INSTALL_DATA} ${WRKSRC}/config.sub ${PREFIX}/share/EMBOSS/scripts
	${INSTALL_DATA} ${WRKSRC}/depcomp ${PREFIX}/share/EMBOSS/scripts
	${INSTALL_DATA} ${WRKSRC}/install-sh ${PREFIX}/share/EMBOSS/scripts
	${INSTALL_DATA} ${WRKSRC}/mkinstalldirs ${PREFIX}/share/EMBOSS/scripts

.include "../../mk/bsd.pkg.mk"
