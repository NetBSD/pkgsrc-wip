# $NetBSD$

DISTNAME=	swh.model-0.9.0
PKGNAME=	${PYPKGPREFIX}-swh-model-0.9.0
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/swh.model/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://forge.softwareheritage.org/diffusion/DMOD/
COMMENT=	Software Heritage data model
LICENSE=	gnu-gpl-v3

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=4.1.2:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-attrs>=19.3.0:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-Deprecated>=1.2.7:../../devel/py-Deprecated
DEPENDS+=	${PYPKGPREFIX}-hypothesis>=5.41.5:../../devel/py-hypothesis
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=3.7.4.3:../../devel/py-typing-extensions
DEPENDS+=	${PYPKGPREFIX}-blake2>=1.1.2:../../wip/py-blake2
DEPENDS+=	${PYPKGPREFIX}-iso8601>=0.1.13:../../time/py-iso8601
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.8.1:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-attrs-strict>=0.2.0:../../wip/py-attrs-strict
DEPENDS+=	${PYPKGPREFIX}-swh-core>=0.10.0:../../wip/py-swh-core

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
