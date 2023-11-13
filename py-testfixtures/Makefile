# $NetBSD$

DISTNAME=	testfixtures-7.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/testfixtures/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/simplistix/testfixtures
COMMENT=	Helpers and mocks useful for automated tests in Python
LICENSE=	mit

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
TOOL_DEPENDS+=	${PYPKGPREFIX}-twine-[0-9]*:../../net/py-twine
DEPENDS+=	${PYPKGPREFIX}-test>=3.6:../../devel/py-test
DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
DEPENDS+=	${PYPKGPREFIX}-test-django-[0-9]*:../../www/py-test-django

DEPENDS+=	${PYPKGPREFIX}-mypy-[0-9]*:../../lang/py-mypy
DEPENDS+=	${PYPKGPREFIX}-zope.component-[0-9]*:../../devel/py-zope.component
DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django3
# TEST: django, sybil>=3, twisted
# DOCS: also sphinx, furo

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
