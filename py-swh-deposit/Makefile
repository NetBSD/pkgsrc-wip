# $NetBSD$

DISTNAME=	swh.deposit-0.6.0
PKGNAME=	${PYPKGPREFIX}-swh-deposit-0.6.0
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/swh.deposit/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://forge.softwareheritage.org/source/swh-deposit/
COMMENT=	Software Heritage Deposit Server
LICENSE=	gnu-gpl-v3

PYTHON_VERSIONS_INCOMPATIBLE+=	27

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=4.1.2:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-click>=7.1.2:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-xmltodict>=0:../../textproc/py-xmltodict
DEPENDS+=	${PYPKGPREFIX}-iso8601>=0.1.13:../../time/py-iso8601
DEPENDS+=	${PYPKGPREFIX}-requests>=2.25.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-swh-core>=0.10.0:../../wip/py-swh-core
DEPENDS+=	${PYPKGPREFIX}-swh-model>=0.7.2:../../wip/py-swh-model
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=6.2.0:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-django>=3.10.0:../../devel/py-test-django
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock>=2.0.0:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-requests-mock>=1.8.0:../../devel/py-requests-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-django-stubs-1.7.0:../../devel/py-django-stubs

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
