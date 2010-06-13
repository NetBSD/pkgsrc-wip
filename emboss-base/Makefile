# $NetBSD: Makefile,v 1.6 2010/06/13 22:47:03 thomasklausner Exp $

.include "Makefile.common"
DISTNAME=		EMBOSS-2.9.0
PKGNAME=		emboss-base-2.9.0
PKGREVISION=		1

COMMENT=	European Molecular Biology Open Software Suite

DIST_SUBDIR=		emboss/emboss-2.9.0

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
