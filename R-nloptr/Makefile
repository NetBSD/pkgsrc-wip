# $NetBSD: Makefile,v 1.8 2021/09/20 01:16:44 mef Exp $

R_PKGNAME=	nloptr
R_PKGVER=	2.0.3

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	R interface to NLopt
LICENSE=	gnu-lgpl-v3

#EPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat

TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-inline-[0-9]*:../../devel/R-inline
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config
#CFLAGS+=	-I ${PREFIX}/lib/R/library/testthat/include
#DFLAGS+=	-L ${WRKSRC}/nloptr/src/nlopt/lib

.include "../../devel/R-testthat/buildlink3.mk"
.include "../../math/R/Makefile.extension"
.include "../../math/nlopt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
