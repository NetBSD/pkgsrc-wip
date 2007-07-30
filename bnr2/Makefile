# $NetBSD: Makefile,v 1.21 2007/07/30 20:26:53 thomasklausner Exp $
#

DISTNAME=		BNR2beta-0.14.7
PKGNAME=		${DISTNAME:S/BNR2beta/bnr2/}
CATEGORIES=		news
MASTER_SITES=		http://www.bnr2.org/
EXTRACT_SUFX=		.tgz
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} \
			libborqt-6.9.0-qt2.3.so.tgz

MAINTAINER=		dhowland@users.sourceforge.net
HOMEPAGE=		http://www.bnr2.org/
COMMENT=		USENET bulk binary downloader (X11)

EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	jpeg x11

WRKSRC=			${WRKDIR}/BNR2
BUILD_DIRS=		# empty

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-install
SUBST_MESSAGE.prefix=	Fixing prefixes.
SUBST_FILES.prefix=	bnr2
SUBST_SED.prefix=	-e "s|@PREFIX@|${PREFIX}|g"

post-extract:
	${CP} ${FILESDIR}/bnr2 ${WRKSRC}/bnr2

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/bnr2
	${INSTALL} ${WRKSRC}/bin/BNR2 ${PREFIX}/lib/bnr2/
	${INSTALL} ${WRKSRC}/lib/libborqt-6.9.0-qt2.3.so ${PREFIX}/lib/bnr2/
	${LN} -s -f libborqt-6.9.0-qt2.3.so ${PREFIX}/lib/bnr2/libborqt-6.9-qt2.3.so
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/bnr2
	${INSTALL_DATA_DIR} ${PREFIX}/share/icons/bnr2
	${INSTALL_DATA_DIR} ${PREFIX}/share/themes/bnr2
	${INSTALL_DATA_DIR} ${PREFIX}/share/themes/bnr2/Luna
	${INSTALL_DATA_DIR} ${PREFIX}/share/themes/bnr2/Silver
	${INSTALL_DATA} ${WRKSRC}/icon/BNR2a.png ${PREFIX}/share/icons/bnr2/
	${INSTALL_DATA} ${WRKSRC}/docs/changes.txt ${PREFIX}/share/doc/bnr2/
	${INSTALL_DATA} ${WRKSRC}/docs/shutdown-readme.txt ${PREFIX}/share/doc/bnr2/
	${INSTALL_DATA} ${WRKSRC}/docs/BNR-readme.txt ${PREFIX}/share/doc/bnr2/
	${INSTALL_DATA} ${WRKSRC}/bin/Themes/Luna/* ${PREFIX}/share/themes/bnr2/Luna/
	${INSTALL_DATA} ${WRKSRC}/bin/Themes/Silver/* ${PREFIX}/share/themes/bnr2/Silver/
	${INSTALL_SCRIPT} ${WRKSRC}/bnr2 ${PREFIX}/bin/
	${LN} -s -f ${PREFIX}/share/themes/bnr2/ ${PREFIX}/lib/bnr2/Themes

.include "../../mk/bsd.pkg.mk"
