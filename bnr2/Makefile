# $NetBSD: Makefile,v 1.8 2004/06/14 17:36:42 dhowland Exp $
#

DISTNAME=		BNR2beta-0.13.3
PKGNAME=		${DISTNAME:S/BNR2beta/bnr2/}
WRKSRC=			${WRKDIR}/BNR2
CATEGORIES=		news
MASTER_SITES=		http://www.bnr2.org/
EXTRACT_SUFX=		.tgz
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} \
			libborqt-6.9.0-qt2.3.so.tgz

MAINTAINER=		tv@duh.org
HOMEPAGE=		http://www.bnr2.org/
COMMENT=		USENET bulk binary downloader (X11)

CONFLICTS+=		BNR2beta-0.*

NO_BUILD=		# defined
USE_BUILDLINK3=		yes
USE_PKGINSTALL=		yes

ONLY_FOR_PLATFORM=	Linux-*-i386 NetBSD-*-i386

.include "../../emulators/suse_linux/Makefile.application"

.if ${OPSYS} != "Linux"
DEPENDS+=		suse_x11-[0-9]*:../../emulators/${SUSE_DIR_PREFIX}_x11
DEPENDS+=		suse_libjpeg-[0-9]*:../../emulators/${SUSE_DIR_PREFIX}_libjpeg
.endif

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/bnr2
	${INSTALL_SCRIPT} ${WRKSRC}/bin/BNR2 ${PREFIX}/lib/bnr2/
	${INSTALL_SCRIPT} ${WRKSRC}/lib/libborqt-6.9.0-qt2.3.so ${PREFIX}/lib/bnr2/
	${LN} -s -f libborqt-6.9.0-qt2.3.so ${PREFIX}/lib/bnr2/libborqt-6.9-qt2.3.so
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/bnr2
	${INSTALL_DATA_DIR} ${PREFIX}/share/icons/bnr2
	${INSTALL_DATA} ${WRKSRC}/icon/bnr2a.png ${PREFIX}/share/icons/bnr2/
	${INSTALL_DATA} ${WRKSRC}/docs/changes.txt ${PREFIX}/share/doc/bnr2/
	${INSTALL_DATA} ${WRKSRC}/docs/shutdown-readme.txt ${PREFIX}/share/doc/bnr2/
	${INSTALL_DATA} ${WRKSRC}/docs/tgz-readme.txt ${PREFIX}/share/doc/bnr2/
	${INSTALL_DATA} ${WRKSRC}/docs/install-script-readme.txt ${PREFIX}/share/doc/bnr2/
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/bnr2 >${WRKDIR}/bnr2
	${INSTALL_SCRIPT} ${WRKDIR}/bnr2 ${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
