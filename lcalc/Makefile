# $NetBSD: Makefile,v 1.2 2012/10/03 09:10:35 asau Exp $
#


DISTNAME=	L-1.23
PKGNAME=	lcalc-1.23
CATEGORIES=	math
MASTER_SITES=	http://pmmac03.math.uwaterloo.ca/~mrubinst/L_function_public/CODE/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pmmac03.math.uwaterloo.ca/~mrubinst/L_function_public/CODE/
COMMENT=	Lcalc is a program for calculating with L-functions
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${DISTNAME}/src
USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_SED.paths+=	-e 's,/usr/local,${PREFIX},g'
SUBST_FILES.paths+=	src/Makefile
SUBST_MESSAGE.paths=	Fixing header search paths.


INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lcalc ${DESTDIR}${PREFIX}/bin


.include "../../devel/gmp/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
