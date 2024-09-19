# $NetBSD$

DISTNAME=	spid_compliant_certificates-0.2
PKGNAME=	${DISTNAME:S/_/-/g}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/spid-compliant-certificates/}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://github.com/italia/spid-compliant-certificates-python
COMMENT=	Generate X509 certificates according to Avviso SPID 29 v3
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-cryptography>=3.3.0:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-iso3166>=1.0.1:../../devel/py-iso3166
DEPENDS+=	${PYPKGPREFIX}-packaging>=1.0.1:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-requests>=2.25.1:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-ruamel-yaml>=0.17.4:../../devel/py-ruamel-yaml

USE_LANGUAGES=			# none

# Only for Python 3
PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
