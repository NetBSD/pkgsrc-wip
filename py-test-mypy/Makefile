# $NetBSD$

DISTNAME=	pytest-mypy-0.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	devel python
MASTER_SITES=	https://files.pythonhosted.org/packages/36/5e/6ea1fe0a56d3334bfbca51d71e5e119eacc84d872762e0b9dcf611fba4df/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/dbader/pytest-mypy
COMMENT=	Mypy static type checker plugin for Pytest
LICENSE=	mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-filelock>=3.0.12:../../devel/py-filelock
DEPENDS+=	${PYPKGPREFIX}-test>=6.0.2:../../devel/py-test
DEPENDS+=	${PYPKGPREFIX}-mypy>=0.782:../../lang/py-mypy

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
