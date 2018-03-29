# $NetBSD: Makefile,v 1.7 2011/10/26 13:48:59 noud4 Exp $

.include "Makefile.common"
DISTNAME=		EMBOSS-2.9.0
PKGNAME=		emboss-base-2.9.0
PKGREVISION=		2

COMMENT=	European Molecular Biology Open Software Suite
LICENSE=	gnu-gpl-v2

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
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/include/emboss
	${INSTALL_DATA} ${WRKSRC}/ajax/*.h ${DESTDIR}${PREFIX}/include/emboss
	${INSTALL_DATA} ${WRKSRC}/nucleus/*.h ${DESTDIR}${PREFIX}/include/emboss
	${INSTALL_DATA} ${WRKSRC}/plplot/*.h ${DESTDIR}${PREFIX}/include/emboss
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/EMBOSS/scripts
	${INSTALL_DATA} ${WRKSRC}/plplot/lib/plstnd5.fnt ${DESTDIR}${PREFIX}/share/EMBOSS
	${INSTALL_DATA} ${WRKSRC}/plplot/lib/plxtnd5.fnt ${DESTDIR}${PREFIX}/share/EMBOSS
	${INSTALL_DATA} ${WRKSRC}/config.guess ${DESTDIR}${PREFIX}/share/EMBOSS/scripts
	${INSTALL_DATA} ${WRKSRC}/config.sub ${DESTDIR}${PREFIX}/share/EMBOSS/scripts
	${INSTALL_DATA} ${WRKSRC}/depcomp ${DESTDIR}${PREFIX}/share/EMBOSS/scripts
	${INSTALL_DATA} ${WRKSRC}/install-sh ${DESTDIR}${PREFIX}/share/EMBOSS/scripts
	${INSTALL_DATA} ${WRKSRC}/mkinstalldirs ${DESTDIR}${PREFIX}/share/EMBOSS/scripts

.include "../../mk/bsd.pkg.mk"
