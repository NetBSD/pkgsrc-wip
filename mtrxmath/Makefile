# $NetBSD$

DISTNAME=	mtrxmath-1.0.2
CATEGORIES=	math
MASTER_SITES=	http://www.angelfire.com/linux/linuxjeff/mtrxmath/files/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.angelfire.com/linux/linuxjeff/mtrxmath/
COMMENT=	Small tool for matrix mathematics
LICENSE=	gnu-gpl-v2

INSTALLATION_DIRS=	${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mtrxmath ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/mtrxmath.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
