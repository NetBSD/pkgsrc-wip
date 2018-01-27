# $NetBSD: Makefile,v 1.2 2012/09/28 21:24:35 asau Exp $
#

DISTNAME=	depSolver-2.1
PKGNAME=	${DISTNAME:S/depSolver/depsolver/}
CATEGORIES=	math
MASTER_SITES=	http://depsolver.googlecode.com/files/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://depsolver.googlecode.com/
COMMENT=	Multimaterial 3D electrostatic solver
LICENSE=	gnu-gpl-v3

DEPENDS+=	doxygen-[0-9]*:../../devel/doxygen

WRKSRC=		${WRKDIR}/depSolver
USE_TOOLS+=	pax
USE_LANGUAGES=	c c++

DOCDIR=	${PREFIX}/share/doc/depsolver
EDGDIR=	${PREFIX}/share/examples/depsolver

INSTALLATION_DIRS=	bin ${DOCDIR} ${EDGDIR}

do-build:
	cd ${WRKSRC} && ${SH} install.sh

do-install:
	cd ${WRKSRC}/bin && ${CHMOD} +x *
	${INSTALL_DATA} ${WRKSRC}/bin/* ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/docs/*.pdf ${DESTDIR}${DOCDIR}
	cd ${WRKSRC}/examples && pax -rw -pp . ${DESTDIR}${EDGDIR}



.include "../../mk/bsd.pkg.mk"
