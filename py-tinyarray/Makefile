# $NetBSD$

DISTNAME=	tinyarray-1.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://files.pythonhosted.org/packages/5e/3c/f212cbf3fc9b725913b5f63e1918ed3a3c9885e44e451e7a7200b02e987f/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://gitlab.kwant-project.org/kwant/tinyarray
COMMENT=	Arrays of numbers for Python, optimized for small sizes
LICENSE=	2-clause-bsd

USE_LANGUAGES= c c++

.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
