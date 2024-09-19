# $NetBSD: Makefile,v 1.16 2012/10/07 16:22:54 asau Exp $
#

DISTNAME=	scm-5e5
#
# Convert the version number as follows 5d6 -> 5.4.6, where the d is
# changed to a 4, representing the 4th letter.
#
PKGNAME=	scm-5.5.5
WRKSRC=		${WRKDIR}/scm
CATEGORIES=	lang
MASTER_SITES=	http://swissnet.ai.mit.edu/ftpdir/scm/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.swiss.ai.mit.edu/~jaffer/SCM.html
COMMENT=	Portable scheme interpreter
LICENSE=	gnu-gpl-v3 AND gnu-lgpl-v3

DEPENDS+=	slib>=2.4.4:../../devel/slib

USE_TOOLS+=	gmake

BUILD_TARGET=	scmlit

SCM_DATA=	scm.info hobbit.info
INFO_FILES=	# PLIST

.if defined(USE_X) && defined(USE_NCURSES)
.include "../../mk/x11.buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
PLIST_SRC=	${PKGDIR}/PLIST.X_ncurses
SCM_INFO=	${SCM_DATA} Xlibscm.info
BUILD_SCRIPT=	${FILESDIR}/buildscm_X_ncurses.sh
.elif defined(USE_X)
.include "../../mk/x11.buildlink3.mk"
PLIST_SRC=	${PKGDIR}/PLIST.X
SCM_INFO=	${SCM_DATA} Xlibscm.info
BUILD_SCRIPT=	${FILESDIR}/buildscm_X.sh
.elif defined(USE_NCURSES)
.include "../../devel/ncurses/buildlink3.mk"
PLIST_SRC=	${PKGDIR}/PLIST.ncurses
SCM_INFO=	${SCM_DATA}
BUILD_SCRIPT=	${FILESDIR}/buildscm_ncurses.sh
.else
PLIST_SRC=	${PKGDIR}/PLIST.plain
SCM_INFO=	${SCM_DATA}
BUILD_SCRIPT=	${FILESDIR}/buildscm.sh
.endif

post-patch:
	${SED} -e 's|%%LOCALBASE%%|${PREFIX}|g' \
		< ${FILESDIR}/require.scm > ${WRKSRC}/require.scm

post-build:
	${CAT} ${BUILD_SCRIPT} \
		| ${SED} -e 's|%%PREFIX%%|${PREFIX}|g' \
		| ${SED} -e 's|%%LOCALBASE%%|${PREFIX}|g' \
		> ${WRKSRC}/buildscm.sh
	cd ${WRKSRC} && ${SH} ./buildscm.sh

post-install:
	${INSTALL_DATA} ${WRKSRC}/slibcat ${DESTDIR}${PREFIX}/share/scm
.for file in ${SCM_INFO}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DESTDIR}${PREFIX}/${PKGINFODIR}
.endfor

.include "../../mk/bsd.pkg.mk"
