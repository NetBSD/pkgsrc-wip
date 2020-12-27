# $NetBSD$

DISTNAME=	swh.web.client-0.2.3
PKGNAME=	${PYPKGPREFIX}-swh-web-client-0.2.3
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/swh.web.client/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://forge.softwareheritage.org/source/swh-web-client/
COMMENT=	Software Heritage Web client
LICENSE=	gnu-gpl-v3

PYTHON_VERSIONS_INCOMPATIBLE+=	27

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=4.1.2:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-click>=7.1.2:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.8.1:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-requests>=2.25.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-swh-core>=0.10.0:../../wip/py-swh-core
DEPENDS+=	${PYPKGPREFIX}-swh-model>=0.7.2:../../wip/py-swh-model
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=6.2.0:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-requests-mock>=1.8.0:../../devel/py-requests-mock

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
