# $NetBSD: Makefile,v 1.1 2014/01/17 20:02:15 jihbed Exp $

DISTNAME=	fdasrsf-1.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	https://pypi.python.org/packages/source/f/fdasrsf/
FETCH_USING=	curl

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://stat.fsu.edu/~dtucker/research.html
COMMENT=	Functional data analysis using the square root slope framework
LICENSE=modified-bsd

PYDISTUTILSPKG=	yes

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_SED.paths+=	-e 's,share/man/man1,${PKGMANDIR}/man1,g'
SUBST_FILES.paths+=	setup.py
SUBST_MESSAGE.paths=	Fixing header search paths.

.include "../../devel/py-cython/buildlink3.mk"
.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.12.1:../../math/py-scipy
.include "../../mk/bsd.pkg.mk"
