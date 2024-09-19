# $NetBSD$

DISTNAME=	pyodeint-0.4.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyodeint/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/bjodah/
COMMENT=	Python binding for odeint from boost
LICENSE=	2-clause-bsd

USE_LANGUAGES=	c c++

PYDISTUTILSPKG=	yes

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
