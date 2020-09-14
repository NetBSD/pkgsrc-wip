# $NetBSD$

DISTNAME=	lcapy-0.63
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	misc python
MASTER_SITES=	https://files.pythonhosted.org/packages/7b/20/2b7d183c17f0e5fcc9764bcfcdccef83b2c46b8ea7042e41fb1f631eb886/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/mph-/lcapy
COMMENT=	Symbolic linear circuit analysis
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	${PYPKGPREFIX}-matplotlib>=3.2.2:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-scipy>=1.4.1:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-sympy>=1.5.1:../../math/py-sympy
DEPENDS+=	${PYPKGPREFIX}-networkx>=1.4.1:../../math/py-networkx

USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
