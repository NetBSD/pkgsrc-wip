# $NetBSD: Makefile,v 1.2 2014/06/01 12:49:41 thomasklausner Exp $

DISTNAME=	fdasrsf-1.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=f/fdasrsf/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://stat.fsu.edu/~dtucker/research.html
COMMENT=	Functional data analysis using the square root slope framework
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.12.1:../../math/py-scipy

PYDISTUTILSPKG=	yes

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_SED.paths+=	-e 's,share/man/man1,${PKGMANDIR}/man1,g'
SUBST_FILES.paths+=	setup.py
SUBST_MESSAGE.paths=	Fixing header search paths.

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
