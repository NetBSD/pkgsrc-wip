# $NetBSD: Makefile,v 1.5 2012/10/15 18:40:51 asau Exp $
#

DISTNAME=	harminv-1.3.1
CATEGORIES=	math
MASTER_SITES=	http://ab-initio.mit.edu/harminv/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://ab-initio.mit.edu/wiki/index.php/Harminv
COMMENT=	Solver of harmonic inversion
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=  c c++ fortran77

PKGCONFIG_OVERRIDE+=	harminv.pc.in

TEST_TARGET=	check

.include "../../math/blas/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
.include "../../math/mpcomplex/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
