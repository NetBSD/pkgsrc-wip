# $NetBSD: Makefile,v 1.1 2015/08/01 22:12:08 jihbed Exp $

DISTNAME=	pylds-0.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pylds/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/mattjj/pylds
COMMENT=	Learning and inference for Gaussian linear dynamical systems
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.15.1:../../math/py-scipy

PYDISTUTILSPKG=	yes

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
