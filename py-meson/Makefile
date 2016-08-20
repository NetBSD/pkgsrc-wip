# $NetBSD: Makefile,v 1.9 2016/08/18 14:53:24 richard Exp $

DISTNAME=	meson-0.33.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=m/meson/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mesonbuild.com/
COMMENT=	Open source build system meant to be fast and user friendly
LICENSE=	apache-2.0

DEPENDS+=	ninja-build-[0-9]*:../../devel/ninja-build

# c++ for tests
USE_LANGUAGES=	c c++

SUBST_CLASSES+=		man
SUBST_SED.man+=		-e "s,share/man,${PKGMANDIR},"
SUBST_FILES.man+=	setup.py
SUBST_STAGE.man+=	pre-configure
SUBST_MESSAGE.man+=	Fixing man page installation path.

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} run_tests.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
