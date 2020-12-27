# $NetBSD$

DISTNAME=	swh.web-0.0.273
PKGNAME=	${PYPKGPREFIX}-swh-web-0.0.273
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/swh.web/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://forge.softwareheritage.org/diffusion/DWUI/
COMMENT=	Software Heritage Web UI
LICENSE=	gnu-gpl-v3

PYTHON_VERSIONS_INCOMPATIBLE+=	27

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=4.1.2:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4>=0:../../www/py-beautifulsoup4
DEPENDS+=	${PYPKGPREFIX}-cryptography>=3.2.1:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-django-cors-headers>=3.5.0:../../www/py-django-cors-headers
DEPENDS+=	${PYPKGPREFIX}-django-js-reverse>=0.9.1:../../wip/py-django-js-reverse
DEPENDS+=	${PYPKGPREFIX}-djangorestframework>=3.12.1:../../www/py-djangorestframework
DEPENDS+=	${PYPKGPREFIX}-django-webpack-loader>=0:../../www/py-django-webpack-loader
DEPENDS+=	${PYPKGPREFIX}-docutils>=0.16:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-htmlmin>=0.1.12:../../wip/py-htmlmin
DEPENDS+=	${PYPKGPREFIX}-iso8601>=0.1.13:../../time/py-iso8601
DEPENDS+=	${PYPKGPREFIX}-lxml>=4.6.2:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-prometheus-client>=0:../../wip/py-prometheus-client
DEPENDS+=	${PYPKGPREFIX}-badges>=0:../../wip/py-badges
DEPENDS+=	${PYPKGPREFIX}-pygments>=2.5.2:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-keycloak>=0.19.0:../../wip/py-keycloak
DEPENDS+=	${PYPKGPREFIX}-magic>=0.4.0:../../sysutils/py-magic
DEPENDS+=	${PYPKGPREFIX}-memcached>=1.59:../../devel/py-memcached
DEPENDS+=	${PYPKGPREFIX}-yaml>=5.1:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-requests>=2.25.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-sentry-sdk>=0.19.4:../../wip/py-sentry-sdk
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=0:../../devel/py-typing-extensions
DEPENDS+=	${PYPKGPREFIX}-swh-core>=0.10.0:../../wip/py-swh-core
DEPENDS+=	${PYPKGPREFIX}-swh-indexer>=0.6.3:../../wip/py-swh-indexer
DEPENDS+=	${PYPKGPREFIX}-swh-model>=0.7.2:../../wip/py-swh-model
DEPENDS+=	${PYPKGPREFIX}-swh-scheduler>=0.4.0:../../wip/py-swh-scheduler
DEPENDS+=	${PYPKGPREFIX}-swh-search>=0.2.0:../../wip/py-swh-search
DEPENDS+=	${PYPKGPREFIX}-swh-storage>=0.13.1:../../wip/py-swh-storage
DEPENDS+=	${PYPKGPREFIX}-swh-vault>=0.0.33:../../wip/py-swh-vault

USE_LANGUAGES=	c++

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
