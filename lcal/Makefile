# $NetBSD: Makefile,v 1.1.1.1 2010/02/22 23:44:35 jihbed Exp $
#

DISTNAME=	L-1.23
PKGNAME=	lcalc-1.23
CATEGORIES=	math
MASTER_SITES=	http://pmmac03.math.uwaterloo.ca/~mrubinst/L_function_public/CODE/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pmmac03.math.uwaterloo.ca/~mrubinst/L_function_public/CODE/
COMMENT=	Lcalc is a program for calculating with L-functions
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

INSTALLATION_DIRS=	bin

do-build:
	cd ${WRKSRC}/src && ${GMAKE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/lcalc ${DESTDIR}${PREFIX}/bin


.include "../../devel/gmp/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
