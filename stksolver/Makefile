# $NetBSD: Makefile,v 1.1.1.1 2011/05/09 14:29:47 jihbed Exp $
#

DISTNAME=	stkSolver-1.0
PKGNAME=	${DISTNAME:S/S/s/}
CATEGORIES=	science
MASTER_SITES=	http://stksolver.googlecode.com/files/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://code.google.com/p/stksolver/
COMMENT=	Stokes flow solver using the boundary element method
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=	${WRKDIR}/stkSolver

USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin share/doc/tksolver

do-build:
	cd ${WRKSRC}/src && ${GMAKE} -f makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/stkSolver ${DESTDIR}${PREFIX}/bin/stksolver
	${INSTALL_DATA} ${WRKSRC}/docs/stkSolverManual.pdf ${DESTDIR}${PREFIX}/share/doc/tksolver


.include "../../mk/bsd.pkg.mk"
