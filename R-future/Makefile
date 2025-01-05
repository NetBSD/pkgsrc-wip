# $NetBSD$

R_PKGNAME=	future
R_PKGVER=	1.34.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Unified parallel and distributed processing in R
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	R-digest>=0.6.31:../../security/R-digest
DEPENDS+=	R-globals>=0.16.1:../../devel/R-globals
DEPENDS+=	R-listenv-[0-9]*:../../wip/R-listenv
DEPENDS+=	R-parallelly>=1.36.0:../../wip/R-parallelly

# Packages suggested but not available: 'RhpcBLASctl', 'R.rsp'
TEST_DEPENDS+=	R-markdown-[0-9]*:../../textproc/R-markdown

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
