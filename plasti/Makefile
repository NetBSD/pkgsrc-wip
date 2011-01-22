# $NetBSD: Makefile,v 1.1.1.1 2011/01/22 13:14:48 jihbed Exp $
#

DISTNAME=	plasti-1.0.0
CATEGORIES=	math
MASTER_SITES=	http://www.geodynamics.org/cig/software/plasti/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.geodynamics.org/cig/software/plasti/
COMMENT=	Plasti is a 2D ALE (Arbitrary Lagrangian Eulerian) code
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	fortran

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/plasti_oly ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/meshg_oly ${DESTDIR}${PREFIX}/bin

.include "../../math/blas/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
.include "../../lang/g95/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
