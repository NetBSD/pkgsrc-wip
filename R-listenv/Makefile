# $NetBSD$

R_PKGNAME=	listenv
R_PKGVER=	0.9.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Environments behaving (almost) as lists
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	# none
# Packages suggested but not available: 'R.rsp'
TEST_DEPENDS+=	R-R.utils-[0-9]*:../../devel/R-R.utils
TEST_DEPENDS+=	R-markdown-[0-9]*:../../textproc/R-markdown

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
