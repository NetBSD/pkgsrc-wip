# $NetBSD: Makefile,v 1.24 2012/09/24 17:06:18 asau Exp $
#

DISTNAME=		BNR2beta-0.14.7
PKGNAME=		${DISTNAME:S/BNR2beta/bnr2/}
CATEGORIES=		news
MASTER_SITES=		http://www.bnr2.org/
EXTRACT_SUFX=		.tgz
DISTFILES=		${DEFAULT_DISTFILES} libborqt-6.9.0-qt2.3.so.tgz

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

PKG_DESTDIR_SUPPORT=	user-destdir

post-extract:
	${CP} ${FILESDIR}/bnr2 ${WRKSRC}/bnr2

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/lib/bnr2
	${INSTALL} ${WRKSRC}/bin/BNR2 ${DESTDIR}${PREFIX}/lib/bnr2/
	${INSTALL} ${WRKSRC}/lib/libborqt-6.9.0-qt2.3.so ${DESTDIR}${PREFIX}/lib/bnr2/
	${LN} -s -f libborqt-6.9.0-qt2.3.so ${DESTDIR}${PREFIX}/lib/bnr2/libborqt-6.9-qt2.3.so
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/bnr2
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/icons/bnr2
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/themes/bnr2
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/themes/bnr2/Luna
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/themes/bnr2/Silver
	${INSTALL_DATA} ${WRKSRC}/icon/BNR2a.png ${DESTDIR}${PREFIX}/share/icons/bnr2/
	${INSTALL_DATA} ${WRKSRC}/docs/changes.txt ${DESTDIR}${PREFIX}/share/doc/bnr2/
	${INSTALL_DATA} ${WRKSRC}/docs/shutdown-readme.txt ${DESTDIR}${PREFIX}/share/doc/bnr2/
	${INSTALL_DATA} ${WRKSRC}/docs/BNR-readme.txt ${DESTDIR}${PREFIX}/share/doc/bnr2/
	${INSTALL_DATA} ${WRKSRC}/bin/Themes/Luna/* ${DESTDIR}${PREFIX}/share/themes/bnr2/Luna/
	${INSTALL_DATA} ${WRKSRC}/bin/Themes/Silver/* ${DESTDIR}${PREFIX}/share/themes/bnr2/Silver/
	${INSTALL_SCRIPT} ${WRKSRC}/bnr2 ${DESTDIR}${PREFIX}/bin/
	${LN} -s -f ${DESTDIR}${PREFIX}/share/themes/bnr2/ ${DESTDIR}${PREFIX}/lib/bnr2/Themes

.include "../../mk/bsd.pkg.mk"
