# $NetBSD: Makefile,v 1.3 2010/04/16 20:30:19 jihbed Exp $
#

DISTNAME=	minisat2-070721
CATEGORIES=	math
MASTER_SITES=	http://www.cs.sunysb.edu/~algorith/implement/minisat/distrib/
EXTRACT_SUFX=	.zip

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://minisat.se/MiniSat.html
COMMENT=	Fast and lightweight SAT solver
#LICENSE=	LICENSE

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/minisat
USE_TOOLS+=	gmake
USE_LANGUAGES=	c++

INSTALLATION_DIRS+=	bin include share/doc

do-build:
	cd ${WRKSRC}/core && ${GMAKE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/core/minisat \
		${DESTDIR}${PREFIX}/bin/minisat2
	${INSTALL_DATA} ${WRKSRC}/LICENSE \
		${DESTDIR}${PREFIX}/share/doc/minisat2

.include "../../mk/bsd.pkg.mk"
