# $NetBSD$

DISTNAME=		nlopt-2.7.0
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_GITHUB:=stevengj/}
GITHUB_PROJECT=		nlopt
GITHUB_TAG=		v${PKGVERSION_NOREV}
MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://nlopt.readthedocs.io/en/latest/
COMMENT=		Nonlinear optimization library
LICENSE=		gnu-lgpl-v2.1 OR mit

USE_TOOLS+=		cmake
USE_CMAKE=		yes
USE_LANGUAGES=		c c++

.include "../../devel/gmp/buildlink3.mk"
.include "../../lang/guile20/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
