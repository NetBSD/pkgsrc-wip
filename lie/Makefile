# $NetBSD$

DISTNAME=	conLiE
PKGNAME=	lie-2.2.2
CATEGORIES=	math
MASTER_SITES=	http://young.sp2mi.univ-poitiers.fr/~marc/LiE/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://young.sp2mi.univ-poitiers.fr/~marc/LiE/
COMMENT=	Computer algebra package for Lie group computations
LICENSE=	gnu-lgpl-v3

WRKSRC=	${WRKDIR}/LiE

CPPFLAGS+=	-DUNiX -DPROTO

USE_TOOLS+=	bison gmake

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Lie.exe ${DESTDIR}${PREFIX}/bin/lie
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/lib/lie
	${INSTALL_DATA} ${WRKSRC}/INFO.* \
		${DESTDIR}${PREFIX}/lib/lie
	${INSTALL_DATA} ${WRKSRC}/LEARN.ind \
		${DESTDIR}${PREFIX}/lib/lie

.include "../../mk/bsd.pkg.mk"
