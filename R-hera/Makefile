# $NetBSD$

R_PKGNAME=	hera
R_PKGVER=	0.1.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Companion to the 'xeus-r' 'jupyter' Kernel
LICENSE=	mit	# + file LICENSE

USE_LANGUAGES=	# none

DEPENDS+=	R-cli-[0-9]*:../../devel/R-cli
DEPENDS+=	R-evaluate-[0-9]*:../../devel/R-evaluate
DEPENDS+=	R-glue-[0-9]*:../../devel/R-glue
DEPENDS+=	R-IRdisplay-[0-9]*:../../devel/R-IRdisplay
DEPENDS+=	R-jsonlite-[0-9]*:../../textproc/R-jsonlite
DEPENDS+=	R-R6-[0-9]*:../../devel/R-R6
DEPENDS+=	R-repr-[0-9]*:../../devel/R-repr
DEPENDS+=	R-rlang-[0-9]*:../../devel/R-rlang


.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
