# $NetBSD$

DISTNAME=	swh.icinga_plugins-0.2.1
PKGNAME=	${PYPKGPREFIX}-swh-icinga-plugins-0.2.1
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/swh.icinga_plugins/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://forge.softwareheritage.org/diffusion/swh-icinga-plugins
COMMENT=	Icinga plugins for Software Heritage infrastructure monitoring
LICENSE=	gnu-gpl-v3

PYTHON_VERSIONS_INCOMPATIBLE+=	27

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=4.1.2:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-psycopg2-[0-9]*:../../databases/py-psycopg2
DEPENDS+=	${PYPKGPREFIX}-requests>=2.25.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-swh-core>=0.10.0:../../wip/py-swh-core
DEPENDS+=	${PYPKGPREFIX}-swh-deposit>=0.6.0:../../wip/py-swh-deposit
DEPENDS+=	${PYPKGPREFIX}-swh-storage>=0.0.162:../../wip/py-swh-storage
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=6.2.0:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock>=2.0.0:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-requests-mock>=1.8.0:../../devel/py-requests-mock

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
