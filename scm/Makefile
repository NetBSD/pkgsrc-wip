# $NetBSD: Makefile,v 1.2 2003/07/21 17:33:19 marttikuparinen Exp $
#

DISTNAME=	scm5d6
#
# Convert the version number as follows 5d6 -> 5.4.6, where the d is
# changed to a 4, representing the 4th letter.
#
PKGNAME=	scm-5.4.6
CATEGORIES=	lang
MASTER_SITES=	http://swissnet.ai.mit.edu/ftpdir/scm/
EXTRACT_SUFX=	.zip

MAINTAINER=	davids@idiom.com
HOMEPAGE=	http://www.swiss.ai.mit.edu/~jaffer/SCM.html
COMMENT=	Portable scheme interpreter

BUILD_DEPENDS+=	slib-${SLIB_VER}:../../devel/slib
DEPENDS+=	${BUILD_DEPENDS}

USE_GMAKE=	# defined

WRKSRC=		${WRKDIR}/scm

ALL_TARGET=	scmlit

SLIB_VER=	2.4.4

SCM_DATA=	scm.info hobbit.info

.if defined(USE_X) && defined(USE_NCURSES)
.include "../../mk/x11.buildlink.mk"
.include "../../devel/ncurses/buildlink.mk"
PLIST_SRC=	${PKGDIR}/PLIST.X_ncurses
SCM_INFO=	${SCM_DATA} Xlibscm.info
BUILD_SCRIPT=	${FILESDIR}/buildscm_X_ncurses.sh
.elif defined(USE_X)
.include "../../mk/x11.buildlink.mk"
PLIST_SRC=	${PKGDIR}/PLIST.X
SCM_INFO=	${SCM_DATA} Xlibscm.info
BUILD_SCRIPT=	${FILESDIR}/buildscm_X.sh
.elif defined(USE_NCURSES)
.include "../../devel/ncurses/buildlink.mk"
PLIST_SRC=	${PKGDIR}/PLIST.ncurses
SCM_INFO=	${SCM_DATA}
BUILD_SCRIPT=	${FILESDIR}/buildscm_ncurses.sh
.else
PLIST_SRC=	${PKGDIR}/PLIST.plain
SCM_INFO=	${SCM_DATA}
BUILD_SCRIPT=	${FILESDIR}/buildscm.sh
.endif

post-patch:
	${SED} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		< ${FILESDIR}/require.scm > ${WRKSRC}/require.scm

post-build:
	${CAT} ${BUILD_SCRIPT} \
		| ${SED} -e 's|%%PREFIX%%|${PREFIX}|g' \
		| ${SED} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		> ${WRKSRC}/buildscm.sh
	cd ${WRKSRC} && ${SH} ./buildscm.sh

post-install:
	${INSTALL_DATA} ${WRKSRC}/slibcat ${PREFIX}/share/scm
.for file in ${SCM_INFO}
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/info
	${INSTALL_INFO} ${PREFIX}/info/${file} ${PREFIX}/info/dir
.endfor

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"

