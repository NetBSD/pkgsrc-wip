# $NetBSD$

DISTNAME=		nlopt-2.9.1
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_GITHUB:=stevengj/}
GITHUB_PROJECT=		nlopt
GITHUB_TAG=		v${PKGVERSION_NOREV}
MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://nlopt.readthedocs.io/en/latest/
COMMENT=		Nonlinear optimization library
LICENSE=		gnu-lgpl-v2.1 OR mit

USE_TOOLS+=		pkg-config:run
USE_LANGUAGES+=		c c++

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

.include "../../devel/cmake/build.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
