# $NetBSD$

DISTNAME=	sym2num-0.1.dev2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/.dev2//}
CATEGORIES=	math python
MASTER_SITES=	https://files.pythonhosted.org/packages/15/f2/010a380ef983b41f363324f2d17d9deed7dc957eff2dd19b6e22279c56cd/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/cea-ufmg/sym2num
COMMENT=	Sympy to numpy code generator
LICENSE=	mit

#TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
#DEPENDS+=	${PYPKGPREFIX}-sympy>=1.2:../../math/py-sympy
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.10:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-attrdict>=2.0.0:../../wip/py-attrdict

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
