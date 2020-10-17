# $NetBSD$

DISTNAME=	hug-2.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	https://files.pythonhosted.org/packages/9e/b2/0549ffd2f6bdeb37e5cbee7119830e0928ca0df12c16ab8ed68078c69239/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/hugapi/hug
COMMENT=	Developing APIs as simple as possible, but no simpler
LICENSE=	mit

PYTHON_VERSIONS_INCOMPATIBLE=	27

BUILD_DEPENDS+=	${PYPKGPREFIX}-test-runner>=5.2:../../devel/py-test-runner
DEPENDS+=	${PYPKGPREFIX}-falcon>=2.0.0:../../devel/py-falcon
DEPENDS+=	${PYPKGPREFIX}-requests>=2.24.0:../../devel/py-requests
TEST_DEPENDS+=	${PYPKGPREFIX}-mock>=3.0.5:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-marshmallow>=3.0.0:../../wip/py-marshmallow

USE_LANGUAGES=	c

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
