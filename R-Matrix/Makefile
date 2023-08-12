# $NetBSD$

R_PKGNAME=	Matrix
R_PKGVER=	1.6-0

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Sparse and Dense Matrix Classes and Methods
LICENSE=	gnu-gpl-v2 # file LICENCE

USE_LANGUAGES=	c fortran77

SUBST_CLASSES+=		prefix
SUBST_VARS.prefix+=	PREFIX
SUBST_FILES.prefix+=	src/CHOLMOD/Lib/Makefile
SUBST_STAGE.prefix=	pre-configure

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
