# $NetBSD$

DISTNAME=	patool-1.12
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	archivers python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/patool/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://wummel.github.io/patool/
COMMENT=	Portable archive file manager
LICENSE=	gnu-gpl-v2

SUBST_CLASSES+=         prefix
SUBST_FILES.prefix+=    setup.py
SUBST_STAGE.prefix=     pre-configure
SUBST_VARS.prefix=      PREFIX
SUBST_SED.prefix+=      -e 's,share/man/man1,${PREFIX}/man/man1,g'
SUBST_MESSAGE.paths=    Fixing header search paths.

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
