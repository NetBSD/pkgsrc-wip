# $NetBSD$

DISTNAME=	mccs-1.1-srcs
PKGNAME=	mccs-1.1
CATEGORIES=	misc
MASTER_SITES=	http://www.i3s.unice.fr/~cpjm/misc/
EXTRACT_SUFX=	.tgz

MAINTAINER=	vb@luminar.eu.org
HOMEPAGE=	http://www.i3s.unice.fr/~cpjm/misc/
COMMENT=	Multi Criteria CUDF Solver
LICENSE=	modified-bsd

MAKE_FILE=      makefile
USE_TOOLS+=	gmake
BUILD_TARGET=	mccs
USE_LANGUAGES=	c c++
WRKSRC= 	${WRKDIR}/mccs-1.1
INSTALLATION_DIRS+=bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mccs ${DESTDIR}${PREFIX}/bin/mccs

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
